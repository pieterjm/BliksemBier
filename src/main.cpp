#include <Arduino.h>
#include <esp32_smartdisplay.h>
#include "bliksembier.h"
#include "ui.h"
#include "Adafruit_seesaw.h"
#include "seesaw_servo.h"
#include <ESP32Servo.h>
#include <Adafruit_PN532_NTAG424.h>
#include <LittleFS.h>
#include <ArduinoJson.h>
#include <WebSocketsClient.h>
#include <TaskScheduler.h>

// config variables
int config_servo_close = 90;
int config_servo_open = 90;
String config_wifi_ssid = "";
String config_wifi_pwd = "";
int config_tap_duration = 5000;
String config_pin = String(CONFIG_PIN);
String config_lnbitshost = "";
String config_deviceid = "";

// the switches data
#define BLIKSEMBIER_CFG_MAX_SWITCHES 3
int config_numswitches = 0;
String config_switchid[BLIKSEMBIER_CFG_MAX_SWITCHES];
String config_label[BLIKSEMBIER_CFG_MAX_SWITCHES];
String config_paystr[BLIKSEMBIER_CFG_MAX_SWITCHES];
int config_duration[BLIKSEMBIER_CFG_MAX_SWITCHES];

// servo and I2C config
Adafruit_seesaw seesaw;
seesaw_Servo seesaw_servo(&seesaw);
Servo servo;
bool bI2CServo = false; // set to true if the servo runs via I2C

// NFC reader config
Adafruit_PN532 nfc(PN532_SCL,PN532_SDA);
bool bNFCEnabled = false; // set to true van NFC reader is detected
uint8_t success;
uint8_t uid[] = {0, 0, 0, 0, 0, 0, 0}; 
uint8_t uidLength;

// data related to a payment
int selectedItem = 0;  // the index of the selected button
String payment_request = "";  // the payment request
String payment_hash = ""; // the payment hash
String paymentStateURL = ""; // the URL to retrieve state of the payment
int tap_duration = 0;  // the duration of the tap

// websocket
WebSocketsClient webSocket;

// task functions
void notifyOrderFulfilled();
void notifyOrderReceived();
void checkWiFi();
void checkNFCPayment();
void hidePanelMainMessage();
void expireInvoice();
void updateBeerTapProgress();

// task scheduler
Scheduler taskScheduler;
Task checkWiFiTask(TASK_SECOND * 10, TASK_FOREVER, &checkWiFi);
Task checkNFCPaymentTask(TASK_IMMEDIATE, TASK_FOREVER, &checkNFCPayment);
Task hidePanelMainMessageTask(TASK_IMMEDIATE, TASK_ONCE, &hidePanelMainMessage);
Task expireInvoiceTask(TASK_IMMEDIATE, TASK_ONCE, &expireInvoice);
Task backToAboutPageTask(TASK_IMMEDIATE, TASK_ONCE, &backToAboutPage);
Task beerTapProgressTask(TASK_IMMEDIATE, TAPPROGRESS_STEPS, &updateBeerTapProgress);

// defines for the config file
#define BLIKSEMBIER_CFG_SSID "ssid"
#define BLIKSEMBIER_CFG_WIFIPASS "wifipassword"
#define BLIKSEMBIER_CFG_SERVO_CLOSE "servoclose"
#define BLIKSEMBIER_CFG_SERVO_OPEN "servoopen"
#define BLIKSEMBIER_CFG_LNBITSHOST "lnbitshost"
#define BLIKSEMBIER_CFG_DEVICEID "deviceid"
#define BLIKSEMBIER_CFG_PIN "pin"
  
void beerClose() {
  if ( bI2CServo) {
    seesaw_servo.write(config_servo_close);
  } else {
    servo.write(config_servo_close);
  }
}

void beerOpen() {
  if ( bI2CServo ) {
    seesaw_servo.write(config_servo_open);
  } else {     
    servo.write(config_servo_open);
  }
}

void connectBliksemBier(const char *ssid,const char *pwd, const char *deviceid,const char *lnbitshost) {
  
  config_wifi_ssid = String(ssid);
  config_wifi_pwd = String(pwd);
  config_deviceid = String(deviceid);
  config_lnbitshost = String(lnbitshost);

  saveConfig();

  // restart Wi-Fi
  checkWiFiTask.restart();

}

void saveTuning(int32_t servoClosed, int32_t servoOpen, int32_t tapDuration) {
  config_servo_close = servoClosed;
  config_servo_open = servoOpen;
  config_tap_duration = tapDuration;
  saveConfig();
}

void updatePIN(const char *pin) {
  config_pin = String(pin);
  saveConfig();
}

  
bool checkPIN(const char *pin) {
  if ( pin == NULL ) {
    return false;
  }
  if ( String(pin).equals(config_pin) ) {
    return true;
  }
  return false;
}

void notifyOrderReceived()
{
  String wsmessage = "{\"event\":\"acknowledged\",\"payment_hash\":\"";
  wsmessage += payment_hash;
  wsmessage += "\"}";
  webSocket.sendTXT(wsmessage);  
}

void notifyOrderFulfilled()
{
  String wsmessage = "{\"event\":\"fulfilled\",\"payment_hash\":\"";
  wsmessage += payment_hash;
  wsmessage += "\"}";
  webSocket.sendTXT(wsmessage);  
}

void toConfigPage()
{
  expireInvoiceTask.disable();
  if ( bNFCEnabled ) {
    checkNFCPaymentTask.disable();
  }
  lv_obj_add_flag(ui_PanelAboutMessage,LV_OBJ_FLAG_HIDDEN);
  lv_disp_load_scr(ui_ScreenPin);	  
  lv_timer_handler();      

}

void backToAboutPage()
{
  expireInvoiceTask.disable();
  if ( bNFCEnabled ) {
    checkNFCPaymentTask.disable();
  }
  lv_obj_add_flag(ui_PanelAboutMessage,LV_OBJ_FLAG_HIDDEN);
  lv_disp_load_scr(ui_ScreenAbout);	  
  lv_timer_handler();      
}

// update the slider of the progress bar while tapping
void updateBeerTapProgress()
{
  lv_bar_set_value(ui_BarBierProgress,beerTapProgressTask.getRunCounter(), LV_ANIM_OFF);
  lv_timer_handler();

  if (beerTapProgressTask.isLastIteration() ) {
    beerClose();
    notifyOrderFulfilled();
    lv_obj_add_flag(ui_BarBierProgress,LV_OBJ_FLAG_HIDDEN);
    backToAboutPageTask.restartDelayed(TASK_SECOND * 3);
  }
} 

void beerScreen()
{
  lv_obj_add_flag(ui_BarBierProgress,LV_OBJ_FLAG_HIDDEN);
	lv_obj_clear_flag(ui_ButtonBierStart,LV_OBJ_FLAG_HIDDEN);
  lv_bar_set_value(ui_BarBierProgress,0,LV_ANIM_OFF);
	lv_disp_load_scr(ui_ScreenBierFlowing);	
}

void beerStart()
{
  notifyOrderReceived();
  beerTapProgressTask.setInterval(tap_duration / TAPPROGRESS_STEPS);
  beerTapProgressTask.restart();
  lv_bar_set_value(ui_BarBierProgress,0, LV_ANIM_OFF);
  lv_obj_add_flag(ui_ButtonBierStart,LV_OBJ_FLAG_HIDDEN);
	lv_obj_clear_flag(ui_BarBierProgress,LV_OBJ_FLAG_HIDDEN);
  lv_timer_handler();
	beerOpen();    
}

void freeBeerClicked()
{
  tap_duration = config_tap_duration;
  beerScreen();
}

void setUIStatus(String shortMsg, String longMsg, bool bDisplayQRCode = false) {
  static String prevLongMsg = "";

  if ( prevLongMsg.equals(longMsg) ) {
    return;
  } 
  prevLongMsg = longMsg;

  lv_label_set_text(ui_LabelAboutStatus,shortMsg.c_str());
  lv_label_set_text(ui_LabelConfigStatus,longMsg.c_str());
}

void make_lnurlw_withdraw(String lnurlw) {
  String wsmessage = "{\"event\":\"lnurlw\",\"payment_request\":\""; 
  wsmessage += payment_request;
  wsmessage += "\",\"lnurlw\":\"";
  wsmessage += lnurlw;
  wsmessage += "\"}";
  webSocket.sendTXT(wsmessage);  
}

void hidePanelAboutMessage()
{
  lv_obj_add_flag(ui_PanelAboutMessage,LV_OBJ_FLAG_HIDDEN);
  lv_timer_handler();    
}

void hidePanelMainMessage()
{
  lv_obj_add_flag(ui_PanelMainMessage,LV_OBJ_FLAG_HIDDEN);
  lv_timer_handler();    
}

void expireInvoice()
{ 
  lv_obj_add_flag(ui_PanelAboutMessage,LV_OBJ_FLAG_HIDDEN);
  lv_disp_load_scr(ui_ScreenAbout);	  
  lv_timer_handler();  

  expireInvoiceTask.disable();
  if ( bNFCEnabled ) {
    checkNFCPaymentTask.disable();
  }
  payment_hash = "";
  payment_request = "";  
}

void showInvoice(DynamicJsonDocument *doc)
{
  payment_request = (*doc)["pr"].as<String>();
  payment_hash = (*doc)["payment_hash"].as<String>();

  // Start countdown to expire invoice
  expireInvoiceTask.restartDelayed(TASK_SECOND * 60);
  if ( bNFCEnabled ) {
    checkNFCPaymentTask.restart();
  }

  // Update UI
  lv_obj_add_flag(ui_PanelMainMessage,LV_OBJ_FLAG_HIDDEN);
  lv_qrcode_update(ui_QrcodeLnurl, payment_request.c_str(), payment_request.length());
  lv_obj_clear_flag(ui_QrcodeLnurl,LV_OBJ_FLAG_HIDDEN);
  lv_disp_load_scr(ui_ScreenMain);	

  lv_label_set_text(ui_LabelHeaderMain,config_paystr[selectedItem].c_str());

}

void wantBierClicked(int item) {
  Serial.println("wantBierClicked");

  if ( config_numswitches == 0 ) {
    lv_disp_load_scr(ui_ScreenPin);	
    return;
  }

  // reset all parameters
  payment_hash = "";
  payment_request = "";
  // set tap duration to default
  tap_duration = config_duration[item];

  // send request to create invoice
  if ( webSocket.isConnected() ) {
    String wsmessage = "{\"event\":\"createinvoice\",\"switch_id\":\"";
    wsmessage += config_switchid[item];
    wsmessage += "\"}";
    webSocket.sendTXT(wsmessage.c_str());  

    lv_obj_clear_flag(ui_PanelAboutMessage,LV_OBJ_FLAG_HIDDEN);
  }
}


void myDelay(uint32_t ms) {
  delay(ms);
}

void loadConfig() {
  File file = LittleFS.open("/config.json", "r");
  if (file) {

    String content = file.readString();
    DynamicJsonDocument doc(2048);
    DeserializationError error = deserializeJson(doc, content);
    file.close();

    if ( error.code() ==  DeserializationError::Ok ) {

      JsonArray arr = doc.as<JsonArray>();
      for (JsonObject obj: arr) {
        String name = obj["name"];
        String value = obj["value"];

        if ( name == BLIKSEMBIER_CFG_SSID ) {
          config_wifi_ssid = String(value);
        } else if ( name == BLIKSEMBIER_CFG_WIFIPASS ) {
          config_wifi_pwd = String(value);
        } else if ( name == BLIKSEMBIER_CFG_SERVO_CLOSE ) {
          config_servo_close = String(value).toInt();
        } else if ( name == BLIKSEMBIER_CFG_SERVO_OPEN ) {
          config_servo_open = String(value).toInt();
        } else if ( name == BLIKSEMBIER_CFG_LNBITSHOST ) {
          config_lnbitshost = String(value);     
        } else if (name == BLIKSEMBIER_CFG_PIN ) {
          config_pin = String(value);
        } else if ( name == BLIKSEMBIER_CFG_DEVICEID ) {
          config_deviceid = String(value);
        }
      }
    }
  }
}

void saveConfig() {
  File file = LittleFS.open("/config.json", "w");
  if (!file) {
    return;
  }

  DynamicJsonDocument doc(2048);
  doc[0]["name"] = BLIKSEMBIER_CFG_SSID;
  doc[0]["value"] = config_wifi_ssid;    
  doc[1]["name"] = BLIKSEMBIER_CFG_WIFIPASS;
  doc[1]["value"]= config_wifi_pwd;
  doc[2]["name"] = BLIKSEMBIER_CFG_SERVO_CLOSE;
  doc[2]["value"] = config_servo_close;
  doc[3]["name"] = BLIKSEMBIER_CFG_SERVO_OPEN;
  doc[3]["value"] = config_servo_open;
  doc[4]["name"] = BLIKSEMBIER_CFG_LNBITSHOST;
  doc[4]["value"] = config_lnbitshost;
  doc[5]["name"] = BLIKSEMBIER_CFG_PIN;
  doc[5]["value"] = config_pin;
  doc[6]["name"] = BLIKSEMBIER_CFG_DEVICEID;
  doc[6]["value"] = config_deviceid;

  String output = "";
  serializeJson(doc, output);
  serializeJson(doc, file);
  file.close();
}

void handlePaid(DynamicJsonDocument *doc) {
  if ( ! (*doc)["payment_hash"].as<String>().equals(payment_hash) ) {
    Serial.println("Payment Hash not OK");
    return;
  }

  expireInvoiceTask.disable();
  if ( bNFCEnabled ) {
    checkNFCPaymentTask.disable();
  }
  tap_duration = (*doc)["payload"].as<String>().toInt();
  beerScreen();
}


void configureSwitches(DynamicJsonDocument *doc) {
  char charValue[100];

  // clear current switches
  config_numswitches = 0;
  
  // bewaar opties in een keuzelijstje
  JsonArray switches = (*doc)["switches"].as<JsonArray>();
  config_numswitches = switches.size() < BLIKSEMBIER_CFG_MAX_SWITCHES ? switches.size() : BLIKSEMBIER_CFG_MAX_SWITCHES;
  for (int i=0;i < config_numswitches;i++) {
    JsonObject obj = switches[i];
    config_switchid[i] = obj["id"].as<String>();
    config_label[i] = obj["label"].as<String>();
    config_duration[i] = obj["duration"].as<int>();

    float amount = obj["amount"].as<float>();    
    String currency = obj["currency"].as<String>();
    if ( currency.equals("sat") ) { 
      sprintf(charValue,"PAY %.0f %s",amount,currency.c_str());
    } else {
      sprintf(charValue,"PAY %.2f %s",amount,currency.c_str());
    }
    config_paystr[i] = charValue;

    config_label[i].toUpperCase();
    config_paystr[i].toUpperCase();

    // get duration here? 
  }

  switch ( config_numswitches ) {
    case 0:
      lv_obj_add_flag(ui_ButtonAboutOne,LV_OBJ_FLAG_HIDDEN);
      lv_obj_add_flag(ui_ButtonAboutTwo,LV_OBJ_FLAG_HIDDEN);
      lv_obj_add_flag(ui_ButtonAboutThree,LV_OBJ_FLAG_HIDDEN);
      break;
    case 1:
      lv_obj_clear_flag(ui_ButtonAboutOne,LV_OBJ_FLAG_HIDDEN);
      lv_obj_add_flag(ui_ButtonAboutTwo,LV_OBJ_FLAG_HIDDEN);
      lv_obj_add_flag(ui_ButtonAboutThree,LV_OBJ_FLAG_HIDDEN);
      lv_obj_set_x(ui_ButtonAboutOne, 0);
      lv_label_set_text(ui_LabelAboutOne, config_label[0].c_str());
      break;
    case 2:
      lv_obj_clear_flag(ui_ButtonAboutOne,LV_OBJ_FLAG_HIDDEN);
      lv_obj_clear_flag(ui_ButtonAboutTwo,LV_OBJ_FLAG_HIDDEN);
      lv_obj_add_flag(ui_ButtonAboutThree,LV_OBJ_FLAG_HIDDEN);
      lv_obj_set_x(ui_ButtonAboutOne, -60);
      lv_obj_set_x(ui_ButtonAboutTwo, 60);
      lv_label_set_text(ui_LabelAboutOne, config_label[0].c_str());
      lv_label_set_text(ui_LabelAboutTwo, config_label[1].c_str());
      break;
    case 3:
      lv_obj_clear_flag(ui_ButtonAboutOne,LV_OBJ_FLAG_HIDDEN);
      lv_obj_clear_flag(ui_ButtonAboutTwo,LV_OBJ_FLAG_HIDDEN);
      lv_obj_clear_flag(ui_ButtonAboutThree,LV_OBJ_FLAG_HIDDEN);
      lv_obj_set_x(ui_ButtonAboutOne, -105);
      lv_obj_set_x(ui_ButtonAboutTwo, 0);
      lv_obj_set_x(ui_ButtonAboutThree, 105);
      lv_label_set_text(ui_LabelAboutOne, config_label[0].c_str());
      lv_label_set_text(ui_LabelAboutTwo, config_label[1].c_str());
      lv_label_set_text(ui_LabelAboutThree, config_label[2].c_str());
      break;
    default:
      break;
  }

  setUIStatus("Ready to Serve","Ready to Serve");

}

void webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {
  switch(type) {
    case WStype_DISCONNECTED:
      if ( WiFi.status() != WL_CONNECTED ) {
        setUIStatus("WiFi Disconnected","WiFi Disconnected");
      } else {
        setUIStatus("WebSocket Disconnected","WebSocket Disconnected");
      }      
      break;
    case WStype_CONNECTED:
      setUIStatus("WebSocket Connected","WebSocket Connected");
      break;
    case WStype_TEXT:
      {
        DynamicJsonDocument doc(2000);
        DeserializationError error = deserializeJson(doc, (char *)payload);
        if ( error.code() !=  DeserializationError::Ok ) {
          Serial.println("Error in JSON parsing");
          return;
        }

        // get the message type
        String event = doc["event"].as<String>();
        Serial.printf("WS Event type = %s\n",event.c_str());

        if ( event.equals("switches")) {
          configureSwitches(&doc);
        } else if ( event.equals("invoice")) {
          showInvoice(&doc);
        } else if ( event.equals("paid")) {          
          handlePaid(&doc);
        }

      }
      break;
    default:
			break;
  }
}


void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(2000);

  // add tasks to task scheduler
  taskScheduler.addTask(checkWiFiTask);
  taskScheduler.addTask(checkNFCPaymentTask);
  taskScheduler.addTask(hidePanelMainMessageTask);
  taskScheduler.addTask(expireInvoiceTask);
  taskScheduler.addTask(backToAboutPageTask);
  taskScheduler.addTask(beerTapProgressTask);

  checkWiFiTask.restartDelayed(1000);

  LittleFS.begin(true);

  smartdisplay_init();
  ui_init();

  lv_color_t c = lv_color_hex(0x000000); 
  lv_color32_t rgb;
  rgb.full = lv_color_to32(c);
  smartdisplay_set_led_color(rgb);
  smartdisplay_tft_set_backlight(BB_TFT_INTENSITY);
  // set UI components from config
  loadConfig();

  // set the values of the sliders
  lv_slider_set_value(ui_SliderConfigServoClosed,config_servo_close,LV_ANIM_OFF);
  lv_slider_set_value(ui_SliderConfigServoOpen,config_servo_open,LV_ANIM_OFF);
  lv_slider_set_value(ui_SliderConfigTapDuration,config_tap_duration,LV_ANIM_OFF);
  
  // set the current values of the labels
  lv_label_set_text_fmt(ui_LabelConfigServoClosed,"%d",config_servo_close);
  lv_label_set_text_fmt(ui_LabelConfigServoOpen,"%d",config_servo_open);
  lv_label_set_text_fmt(ui_LabelConfigTapDuration,"%d",config_tap_duration);

  // set wifi configuration and device id
  lv_textarea_set_text(ui_TextAreaConfigSSID,config_wifi_ssid.c_str());
  lv_textarea_set_text(ui_TextAreaWifiPassword,config_wifi_pwd.c_str());
  lv_textarea_set_text(ui_TextAreaConfigHost,config_lnbitshost.c_str());
  lv_textarea_set_text(ui_TextAreaConfigDeviceID,config_deviceid.c_str());
  lv_label_set_text(ui_LabelPINValue,"");

 

  // connect to servo
  if(!seesaw.begin() ) {
    Serial.println("Seesaw device not detected");
    servo.attach(BIER_SERVO_PIN);
    bI2CServo = false;
  }
  else {
    Serial.println("Seesaw succsfully started");  
    seesaw_servo.attach(BIER_SERVO_PIN_I2C);
    bI2CServo = true;
  }

  beerClose();
  webSocket.onEvent(webSocketEvent);

  // initialize NFC reader
  if ( bI2CServo ) {
    nfc.begin();  
    uint32_t versiondata = nfc.getFirmwareVersion();
    if (!versiondata) {
      bNFCEnabled = false;
      Serial.print("Didn't find PN53x board"); 
    } else {
      bNFCEnabled = true;

      // Got ok data, print it out!
      Serial.print("Found chip PN53x");
      Serial.println((versiondata >> 24) & 0xFF, HEX);
      Serial.print("Firmware ver. ");
      Serial.print((versiondata >> 16) & 0xFF, DEC);
      Serial.print('.');
      Serial.println((versiondata >> 8) & 0xFF, DEC);

      // configure board to read RFID tags
      nfc.SAMConfig();

      Serial.println("Waiting for an ISO14443A Card ...");
    }
  }


  // set label in the About screen
  setUIStatus("Initialized","Initialized");

}


void checkWiFi() {
  static bool bConnected = false;

  if ( checkWiFiTask.isFirstIteration() ) {
    Serial.println("is first iteration");
    bConnected = false;

    if ( config_wifi_ssid.length() > 0 ) {
      WiFi.disconnect();
      WiFi.begin(config_wifi_ssid.c_str(),config_wifi_pwd.c_str());        
      checkWiFiTask.setInterval(TASK_SECOND);
    }
  }

  wl_status_t status = WiFi.status();
  switch ( status ) {
    case WL_CONNECTED:
      Serial.println("Wi-Fi Connected");
      if ( bConnected == false ) {
        setUIStatus("Wi-Fi connected","Wi-Fi connected");
        checkWiFiTask.setInterval(TASK_MINUTE);
        Serial.println("Connecting WebSocket");
        webSocket.setReconnectInterval(1000);
        String wspath = "/bliksembier/api/v1/ws/";
        wspath += config_deviceid;
        webSocket.beginSSL(config_lnbitshost, 443, wspath);
      }      
      bConnected = true;
      break;
    case WL_NO_SSID_AVAIL:
      Serial.println("ERROR_CONFIG_SSID");
      setUIStatus("SSID not found","SSID not found");
      checkWiFiTask.setInterval(TASK_MINUTE);
      break;
    case WL_CONNECTION_LOST:
      Serial.println("CONNECTION LOST");
      break;
    case WL_IDLE_STATUS:
      Serial.println("W_IDLE_STATUS");
      break;
    case WL_DISCONNECTED:
      Serial.println("WL_DISCONNECTED");
      break;
    case WL_NO_SHIELD:
      Serial.println("Wi-Fi device not initialized");
      break;
    case WL_CONNECT_FAILED:
      Serial.println("WL_CONNECT_FAILED");
      break;
    default:
      Serial.printf("Unknown WiFi state %d\n",status);
      break;
    }


}

void checkNFCPayment() {
  if ( bNFCEnabled == false ) {
    return;
  }

  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength,NFC_TIMEOUT);
  if ( ! success ) {
    return;
  }
  
  lv_label_set_text(ui_LabelMainMessage, "DETECTED NFC TAG");  
  lv_obj_clear_flag(ui_PanelMainMessage, LV_OBJ_FLAG_HIDDEN);    
  lv_timer_handler();  
  Serial.println("DETECTED NFC TAG");
  hidePanelMainMessageTask.restartDelayed(TASK_SECOND * 3);

  if ((uidLength != 7) && (uidLength != 4)) {
    lv_label_set_text(ui_LabelMainMessage, "INCOMPATIBLE CARD");
    lv_timer_handler();  
    hidePanelMainMessageTask.restartDelayed(TASK_SECOND * 3);
    return;
  }
  
  lv_label_set_text(ui_LabelMainMessage, "CORRECT LENGTH");
  lv_timer_handler();  
                
  if (!nfc.ntag424_isNTAG424()) {
    lv_label_set_text(ui_LabelMainMessage, "GO AWAY!!");
    lv_timer_handler();  
    hidePanelMainMessageTask.restartDelayed(TASK_SECOND * 3);
    return;
  }
  
  lv_label_set_text(ui_LabelMainMessage, "DETECTED NTAG424");
  lv_timer_handler();  
  Serial.println("DETECTED NTAG4 424");
  
  uint8_t buffer[512];
  uint8_t bytesread = nfc.ntag424_ISOReadFile(buffer);
  Serial.printf("Bytes read = %d\n",bytesread);

  String lnurlw = String((char *)buffer,bytesread);

  if ( ! lnurlw.startsWith("lnurlw://")) {
    lv_label_set_text(ui_LabelMainMessage, "NO LNURLW");
    lv_timer_handler();  
    hidePanelMainMessageTask.restartDelayed(TASK_SECOND * 3);
    return;
  }

  Serial.printf("Received %s from card\n",lnurlw.c_str());
  make_lnurlw_withdraw(lnurlw);
      
  lv_label_set_text(ui_LabelMainMessage, "PAYMENT SUCCES");
  lv_timer_handler();    
  hidePanelMainMessageTask.restartDelayed(TASK_SECOND * 3);
}

void loop()
{
  webSocket.loop();
  lv_timer_handler();  
  taskScheduler.execute();
  lv_timer_handler();  
}
