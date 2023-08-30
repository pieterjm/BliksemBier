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
#include <HTTPClient.h>
#include <TaskScheduler.h>

// config variables
int config_servo_back = 0;
int config_servo_close = 53;
int config_servo_open = 111;
String config_wifi_ssid = "";
String config_wifi_pwd = "";
int config_tap_duration = 11000;
String config_pin = String(CONFIG_PIN);
String config_lnbitshost = "";
String config_deviceid = "";

// the switches data
#define BLIKSEMBIER_CFG_MAX_SWITCHES 3
int config_numswitches = 0;
String config_switchid[BLIKSEMBIER_CFG_MAX_SWITCHES];
String config_label[BLIKSEMBIER_CFG_MAX_SWITCHES];
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

// task functions
void createInvoice();
void checkInvoice();
void notifyOrderFulfilled();
void notifyOrderReceived();
void checkWiFi();
void checkNFCPayment();
void hidePanelAboutMessage();
void hidePanelMainMessage();
void expireInvoice();
void backToAboutPage();

// task scheduler
Scheduler taskScheduler;
Task createInvoiceTask(TASK_IMMEDIATE,1,&createInvoice);
Task checkInvoiceTask(TASK_SECOND * 2, 310, &checkInvoice);
Task notifyOrderReceivedTask(TASK_IMMEDIATE,1,&notifyOrderReceived);
Task notifyOrderFulfilledTask(TASK_IMMEDIATE,1,&notifyOrderFulfilled);
Task checkWiFiTask(TASK_SECOND * 10, TASK_FOREVER, &checkWiFi);
Task checkNFCPaymentTask(TASK_IMMEDIATE, TASK_FOREVER, &checkNFCPayment);
Task hidePanelAboutMessageTask(TASK_IMMEDIATE, TASK_ONCE, &hidePanelAboutMessage);
Task hidePanelMainMessageTask(TASK_IMMEDIATE, TASK_ONCE, &hidePanelMainMessage);
Task expireInvoiceTask(TASK_IMMEDIATE, TASK_ONCE, &expireInvoice);
Task backToAboutPageTask(TASK_IMMEDIATE, TASK_ONCE, &backToAboutPage);

// defines for the config file
#define BLIKSEMBIER_CFG_SSID "ssid"
#define BLIKSEMBIER_CFG_WIFIPASS "wifipassword"
#define BLIKSEMBIER_CFG_SERVO_BACK "servoback"
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

void beerClean() {
  if ( bI2CServo ) {
    seesaw_servo.write(config_servo_back);
  } else {
    servo.write(config_servo_back);
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

void saveTuning(int32_t servoBack, int32_t servoClosed, int32_t servoOpen, int32_t tapDuration) {
  config_servo_back = servoBack;
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

bool createPaymentRequest(String switchid) {
  HTTPClient http;

  String url = "https://";
  url += config_lnbitshost;
  url += "/bliksembier/api/v1/device/";
  url += config_deviceid;
  url += "/";
  url += switchid;
  url += "/createInvoice";


  String payload = "";
  if ( true ) {
    http.begin(url);
    http.addHeader("Content-type","application/json");
    int statusCode = http.POST("");
    payload = http.getString();
    http.end();

    // create invoice data
    if ( statusCode != HTTP_CODE_OK) {
      Serial.println("Failed to create invoice");
      Serial.println(statusCode);
      Serial.printf("POST payload='%s'\n",payload.c_str());
      return false;
    } 
  }

  DynamicJsonDocument doc(2048);
  DeserializationError error = deserializeJson(doc, payload.c_str());
  if ( error != DeserializationError::Ok ) {
    Serial.println("Failed to parse invoice ");
    return false;
  }

  payment_request = doc["pr"].as<String>();
  payment_hash = doc["payment_hash"].as<String>();

  Serial.printf("Payment hash: %s\n",payment_hash.c_str());

  return true;
}

void checkInvoice() {
  HTTPClient http;
  int statusCode = 0;
  String payload = "";

  http.begin(paymentStateURL);
  statusCode = http.GET();
  payload = http.getString();
  http.end();
  
  Serial.printf("Ping %d\n",statusCode);

  if (( statusCode == 200 ) && ( payload.equals("{\"status\":\"paid\"}"))) {
    checkInvoiceTask.disable();
    if ( bNFCEnabled ) {
      checkNFCPaymentTask.disable();
    }

    beerScreen();
    notifyOrderReceivedTask.restartDelayed(10);
  } 
  else if (( statusCode == 200 ) && ( payload.equals("{\"status\":\"expired\"}"))) {
    checkInvoiceTask.disable();
    if ( bNFCEnabled ) {
      checkNFCPaymentTask.disable();
    }

    expireInvoiceTask.disable();
    expireInvoice();
    backToAboutPageTask.restart();

  } 

  if ( checkInvoiceTask.isLastIteration() && bNFCEnabled ) {
    checkNFCPaymentTask.disable();
  }
}

void notifyOrderReceived()
{
  HTTPClient http;

  Serial.println("Order received");
  String url = "https://";
  url += config_lnbitshost;
  url += "/bliksembier/api/v1/order/";
  url += payment_hash;
  url += "/received";

  if ( true ) {
    http.begin(url);
    int statusCode = http.GET();
    http.end();
  }
}

void notifyOrderFulfilled()
{
  HTTPClient http;

  Serial.println("Order fulfilled");
  String url = "https://";
  url += config_lnbitshost;
  url += "/bliksembier/api/v1/order/";
  url += payment_hash;
  url += "/fulfilled";

  if ( true ) {
    http.begin(url);
    int statusCode = http.GET();
    http.end();
  }
}

void backToAboutPage()
{
  lv_obj_add_flag(ui_PanelAboutMessage,LV_OBJ_FLAG_HIDDEN);
  lv_disp_load_scr(ui_ScreenAbout);	  
  lv_timer_handler();      
}

void backToAboutPageNow()
{
  // disable the current expire Invoice task and expire the invoie right away
  expireInvoiceTask.disable();
  expireInvoice();

  // disable the current backToAbout page task and go back now
  backToAboutPageTask.disable();
  backToAboutPage();
}

void beerTimerProgress(lv_timer_t * timer)
{
  int progress = lv_bar_get_value(ui_BarBierProgress);
  progress += 10;
  if ( progress > 100 ) {
    progress = 100;
  }
  lv_bar_set_value(ui_BarBierProgress,progress, LV_ANIM_OFF);

  if ( progress >=  100 ) {
    beerClose();

    lv_obj_add_flag(ui_BarBierProgress,LV_OBJ_FLAG_HIDDEN);
    lv_timer_handler();

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
  int tapstep = tap_duration / 10;
  lv_timer_t *timer = lv_timer_create(beerTimerProgress, tapstep, NULL);
  lv_timer_set_repeat_count(timer,10);
  lv_obj_add_flag(ui_ButtonBierStart,LV_OBJ_FLAG_HIDDEN);
	lv_obj_clear_flag(ui_BarBierProgress,LV_OBJ_FLAG_HIDDEN);
	beerOpen();    
}

void freeBeerClicked()
{
  tap_duration = config_tap_duration;
  beerScreen();
}

void setUIStatus(String shortMsg, String longMsg, bool bDisplayQRCode = false) {


  static bool prevBDisplayQRCode = false;

  lv_label_set_text(ui_LabelAboutStatus,shortMsg.c_str());
  lv_label_set_text(ui_LabelConfigStatus,longMsg.c_str());
  
  if ( bDisplayQRCode ) {
    lv_obj_clear_flag(ui_QrcodeLnurl,LV_OBJ_FLAG_HIDDEN);
  } else {
    lv_obj_add_flag(ui_QrcodeLnurl,LV_OBJ_FLAG_HIDDEN);
  }
}

bool make_lnurlw_withdraw(String lnurlw) {
  HTTPClient http;

  if ( ! lnurlw.startsWith("lnurlw://")) {
    Serial.println("This is not an LNURLW");
    return false;
  }
  
  // create URL
  String url = String("https://") + lnurlw.substring(9);
  
  String payload = "";
  if ( true ) {
    http.begin(url);
    int statusCode = http.GET();
    payload = http.getString();
    http.end();

    if ( statusCode != HTTP_CODE_OK ) {
      Serial.println("HTTP request not accepted for LNURLW");
      return false;
    }

  }
  Serial.printf("Received from card URL: %s\n",payload.c_str());
  
  DynamicJsonDocument doc(2048);
  DeserializationError error = deserializeJson(doc, payload.c_str());
  if ( error != DeserializationError::Ok ) {
    Serial.println("Failed to parse JSON ");
    return false;
  }

  // extract callback URL and k1
  String callback = doc["callback"].as<String>();
  String k1 = doc["k1"].as<String>();
  String status = doc["status"].as<String>();
  String reason = doc["reason"].as<String>();
  if (( status != NULL ) && status.equals("ERROR")) {
    Serial.println("Error in LNURLW response");
    Serial.println(reason);
    return false;
  }

  if ( callback == NULL ) {
    Serial.println("No callback in LNURLW response");
    return false;
  }

  


  url = callback + "?k1=" + k1 + "&pr=" + payment_request;
  Serial.println(url);            

  if ( true ) {
    http.begin(url);
    int statusCode = http.GET();
    payload = http.getString();
    http.end();

    if ( statusCode != HTTP_CODE_OK ) {
      Serial.println("HTTP request not accepted for callback");
      return false;
    }
  }

  error = deserializeJson(doc, payload.c_str());
  if ( error != DeserializationError::Ok ) {
    Serial.println("Failed to parse payment result ");
    return false;
  }
 
  status = doc["status"].as<String>();  

  if ( status.equals("OK") ) {
    Serial.println("Payment succesfull");
    return true;
  } else {
    Serial.println("Payment failed");
    return false;
  }
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
  Serial.println("expireInvoice");
  expireInvoiceTask.disable();

  lv_obj_clear_flag(ui_PanelMainMessage,LV_OBJ_FLAG_HIDDEN);
  lv_label_set_text(ui_LabelMainMessage, "INVOICE EXPIRED");
  lv_timer_handler();    

  hidePanelMainMessageTask.restartDelayed(TASK_SECOND * 5);
  backToAboutPageTask.restartDelayed(TASK_SECOND * 5);
  if ( bNFCEnabled ) {
    checkNFCPaymentTask.disable();
  }
  checkInvoiceTask.disable();

  payment_hash = "";
  payment_request = "";  

}

void createInvoice()
{
  Serial.println("Start Create Invoice");

  if ( createPaymentRequest(config_switchid[selectedItem]) == false ) {
    Serial.println("Could not create payment request");
    lv_obj_clear_flag(ui_PanelAboutMessage,LV_OBJ_FLAG_HIDDEN);
    lv_label_set_text(ui_LabelAboutMessage, "FAILED TO CREATE INVOICE");
    lv_timer_handler();    
    hidePanelAboutMessageTask.restartDelayed(TASK_SECOND * 2);
    return;
  }

  // create URL to watch
  paymentStateURL = "https://";
  paymentStateURL += config_lnbitshost;
  paymentStateURL += "/public/v1/payment/";
  paymentStateURL += payment_hash;

  // Start checking the invoice  
  expireInvoiceTask.restartDelayed(TASK_SECOND * 60);
  checkInvoiceTask.restart();
  if ( bNFCEnabled ) {
    checkNFCPaymentTask.restart();
  }

  // Update UI
  lv_obj_add_flag(ui_PanelMainMessage,LV_OBJ_FLAG_HIDDEN);
  lv_qrcode_update(ui_QrcodeLnurl, payment_request.c_str(), payment_request.length());
  lv_disp_load_scr(ui_ScreenMain);	
  lv_label_set_text(ui_LabelMainProduct,config_label[selectedItem].c_str());
}

void wantBierClicked(int item) {
  Serial.println("wantBierClicked");
  selectedItem = item;

  if ( config_numswitches == 0 ) {
    lv_disp_load_scr(ui_ScreenPin);	
    return;
  }

  // reset all parameters
  payment_hash = "";
  payment_request = "";
  
  // set tap duration
  tap_duration = config_duration[item];

  lv_obj_clear_flag(ui_PanelAboutMessage,LV_OBJ_FLAG_HIDDEN);

  createInvoiceTask.restartDelayed(100);
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
        } else if ( name == BLIKSEMBIER_CFG_SERVO_BACK ) {
          config_servo_back = String(value).toInt();
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
  doc[2]["name"] = BLIKSEMBIER_CFG_SERVO_BACK;
  doc[2]["value"] = config_servo_back;
  doc[3]["name"] = BLIKSEMBIER_CFG_SERVO_CLOSE;
  doc[3]["value"] = config_servo_close;
  doc[4]["name"] = BLIKSEMBIER_CFG_SERVO_OPEN;
  doc[4]["value"] = config_servo_open;
  doc[5]["name"] = BLIKSEMBIER_CFG_LNBITSHOST;
  doc[5]["value"] = config_lnbitshost;
  doc[6]["name"] = BLIKSEMBIER_CFG_PIN;
  doc[6]["value"] = config_pin;
  doc[7]["name"] = BLIKSEMBIER_CFG_DEVICEID;
  doc[7]["value"] = config_deviceid;

  String output = "";
  serializeJson(doc, output);
  serializeJson(doc, file);
  file.close();
}



bool getLNURLSettings(String deviceid) 
{  
  HTTPClient http;

  String config_url = "https://";
  config_url += config_lnbitshost;
  config_url += "/bliksembier/api/v1/device/";
  config_url += deviceid;
  config_url += "/switches";


  String payload = "";
  if ( true ) {
    http.begin(config_url);
    int statusCode = http.GET();
    payload = http.getString();
    http.end();

    if ( statusCode == HTTP_CODE_NOT_FOUND ) {
      Serial.printf("StatusCode %d\n",statusCode);
      setUIStatus("Incorrect DeviceID","Incorrect DeviceID. Check the configuration of the DeviceID and reconnect");
      return false;
    }
    else if ( statusCode == -1 ) {
      setUIStatus("Configuraion error","Configuration error. Check of the LNbits host is correct and reconnect.");
      return false;
    }
    else if ( statusCode != HTTP_CODE_OK ) {
      setUIStatus("Unknown error","Retrieving device configuration resulted in an unknown error");
      return false;
    }  
  }

  DynamicJsonDocument doc(2048);
  DeserializationError error = deserializeJson(doc, payload);
  if ( error.code() !=  DeserializationError::Ok ) {
    return false;
  }

  // clear current switches
  config_numswitches = 0;
  
  // bewaar opties in een keuzelijstje
  JsonArray switches = doc["switches"].as<JsonArray>();
  config_numswitches = switches.size() < BLIKSEMBIER_CFG_MAX_SWITCHES ? switches.size() : BLIKSEMBIER_CFG_MAX_SWITCHES;
  for (int i=0;i < config_numswitches;i++) {
    JsonObject obj = switches[i];
    config_switchid[i] = obj["id"].as<String>();
    config_label[i] = obj["label"].as<String>();
    config_duration[i] = obj["duration"].as<int>();
    // get duration here? 
  }

  switch ( config_numswitches ) {
    case 0:
      lv_obj_clear_flag(ui_ButtonAboutOne,LV_OBJ_FLAG_HIDDEN);
      lv_obj_add_flag(ui_ButtonAboutTwo,LV_OBJ_FLAG_HIDDEN);
      lv_obj_add_flag(ui_ButtonAboutThree,LV_OBJ_FLAG_HIDDEN);
      lv_obj_set_x(ui_ButtonAboutOne, 0);
      lv_label_set_text(ui_LabelAboutOne, "CONFIG");
      break;
    case 1:
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

  return true;
}


void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(2000);

  // add tasks to task scheduler
  taskScheduler.addTask(createInvoiceTask);
  taskScheduler.addTask(checkInvoiceTask);
  taskScheduler.addTask(notifyOrderReceivedTask);
  taskScheduler.addTask(notifyOrderFulfilledTask);
  taskScheduler.addTask(checkWiFiTask);
  taskScheduler.addTask(checkNFCPaymentTask);
  taskScheduler.addTask(hidePanelAboutMessageTask);
  taskScheduler.addTask(hidePanelMainMessageTask);
  taskScheduler.addTask(expireInvoiceTask);
  taskScheduler.addTask(backToAboutPageTask);

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
  lv_slider_set_value(ui_SliderConfigServoBack,config_servo_back,LV_ANIM_OFF);
  lv_slider_set_value(ui_SliderConfigServoClosed,config_servo_close,LV_ANIM_OFF);
  lv_slider_set_value(ui_SliderConfigServoOpen,config_servo_open,LV_ANIM_OFF);
  lv_slider_set_value(ui_SliderConfigTapDuration,config_tap_duration,LV_ANIM_OFF);
  
  // set the current valuues of the labels
  lv_label_set_text_fmt(ui_LabelConfigServoBack,"%d",config_servo_back);
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
    bConnected = false;
  }

  wl_status_t status = WiFi.status();
  switch ( status ) {
    case WL_CONNECTED:
      Serial.println("Connected");
      if ( bConnected == false ) {
        Serial.println("loading configuration");
        bool bResult = getLNURLSettings(config_deviceid);
        if ( bResult == true ) {
          setUIStatus("Ready to Serve!","Ready to serve!",true);
          checkWiFiTask.setInterval(TASK_SECOND * 15);
        } 
      }      
      bConnected = true;
      break;
    case WL_NO_SSID_AVAIL:
      Serial.println("ERROR_CONFIG_SSID");
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
      setUIStatus("Wi-Fi not initialized","Wi-Fi not initialized");
      if ( config_wifi_ssid.length() > 0 ) {
        WiFi.disconnect();
        WiFi.begin(config_wifi_ssid.c_str(),config_wifi_pwd.c_str());        
        checkWiFiTask.setInterval(TASK_SECOND);
      }
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
  
  uint8_t buffer[512];
  uint8_t bytesread = nfc.ntag424_ISOReadFile(buffer);
  String lnurlw = String((char *)buffer,bytesread);

  if ( ! lnurlw.startsWith("lnurlw://")) {
    lv_label_set_text(ui_LabelMainMessage, "NO LNURLW");
    lv_timer_handler();  
    hidePanelMainMessageTask.restartDelayed(TASK_SECOND * 3);
    return;
  }


  Serial.printf("Received %s from card\n",lnurlw.c_str());
  if ( make_lnurlw_withdraw(lnurlw) == false ) {
    lv_label_set_text(ui_LabelMainMessage, "PAYMENT FAILED");
    lv_timer_handler();  
    hidePanelMainMessageTask.restartDelayed(TASK_SECOND * 3);
    return;
  }
      
  lv_label_set_text(ui_LabelMainMessage, "PAYMENT SUCCES");
  lv_timer_handler();    
  hidePanelMainMessageTask.restartDelayed(TASK_SECOND * 3);
}


void loop()
{
  // update handlers
  lv_timer_handler();  
  taskScheduler.execute();
}
