#include <Arduino.h>
#include <esp32_smartdisplay.h>
#include "bliksembier.h"
#include "ui.h"
#include <ESP32Servo.h>
#include <WebSocketsClient.h>
#include <LittleFS.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>

// config variables
int config_servo_back = 0;
int config_servo_close = 53;
int config_servo_open = 111;
String config_wifi_ssid = "";
String config_wifi_pwd = "";
int config_tap_duration = 11000;
int tap_duration = 0;
String payment_hash = ""; // the current payment hash (ouch)
String config_pin = String(CONFIG_PIN);
String config_lnbitshost = "";
String config_deviceid = "";

// two booleans to pass instructions to the main loop
String config_wspath = "";

// the LNURLs for the switches
#define BLIKSEMBIER_CFG_MAX_SWITCHES 3
int config_numswitches = 0;
String config_lnurl[BLIKSEMBIER_CFG_MAX_SWITCHES];
String config_label[BLIKSEMBIER_CFG_MAX_SWITCHES];



Servo servo;
WebSocketsClient webSocket;
lv_obj_t *ui_QrcodeLnurl = NULL; // the QR code object

// defines for the config file
#define BLIKSEMBIER_CFG_SSID "ssid"
#define BLIKSEMBIER_CFG_WIFIPASS "wifipassword"
#define BLIKSEMBIER_CFG_SERVO_BACK "servoback"
#define BLIKSEMBIER_CFG_SERVO_CLOSE "servoclose"
#define BLIKSEMBIER_CFG_SERVO_OPEN "servoopen"
#define BLIKSEMBIER_CFG_LNBITSHOST "lnbitshost"
#define BLIKSEMBIER_CFG_DEVICEID "deviceid"
#define BLIKSEMBIER_CFG_PIN "pin"

// defines for the QR code
#define QRCODE_PIXEL_SIZE 3
#define QRCODE_X_OFFSET 10
#define QRCODE_Y_OFFSET 10

// WebSocket Events
#define EVENT_PAID "paid"

// state
enum DeviceState {
  OFFLINE = 1,
  CONNECTING = 2,
  CONNECTED = 3, 
  CONFIGURED = 4, 
  READY_TO_SERVE = 5,
  ERROR_UNKNOWN_DEVICEID = 6,
  ERROR_CONFIG_HTTP = 7,
  ERROR_CONFIG_JSON = 8,
  CONNECTING_WEBSOCKET = 9,
  WAITING_FOR_RECONNECT = 10
};

DeviceState deviceState = OFFLINE;

void beerClose() {
  servo.write(config_servo_close);
}

void beerOpen() {
  servo.write(config_servo_open);
}

void beerClean() {
  servo.write(config_servo_back);
}

void connectBliksemBier(const char *ssid,const char *pwd, const char *deviceid,const char *lnbitshost) {
  
  config_wifi_ssid = String(ssid);
  config_wifi_pwd = String(pwd);
  config_deviceid = String(deviceid);
  config_lnbitshost = String(lnbitshost);

  saveConfig();

  deviceState = OFFLINE;
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

bool getWifiStatus() {
  if ( WiFi.status() == WL_CONNECTED ) {
    return true;
  } 
  return false;
}

bool getWebSocketStatus() {
  return webSocket.isConnected();
}


void notifyOrderReceived()
{
  Serial.println("Order received");
  String url = "https://";
  url += config_lnbitshost;
  url += "/bliksembier/api/v1/order/";
  url += payment_hash;
  url += "/received";

  HTTPClient http;
  http.begin(url);
  int statusCode = http.GET();

  http.end();
}

void notifyOrderFulfilled()
{
  Serial.println("Order fulfilled");
  String url = "https://";
  url += config_lnbitshost;
  url += "/bliksembier/api/v1/order/";
  url += payment_hash;
  url += "/fulfilled";

  HTTPClient http;
  http.begin(url);
  int statusCode = http.GET();

  http.end();
}

void backToAbout(lv_timer_t * timer)
{
  notifyOrderFulfilled();

  lv_disp_load_scr(ui_ScreenAbout);	  
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

    lv_timer_t *timer = lv_timer_create(backToAbout, 3000, NULL);
    lv_obj_add_flag(ui_BarBierProgress,LV_OBJ_FLAG_HIDDEN);
    lv_timer_set_repeat_count(timer,1);

  }
} 

void beerScreen()
{
  lv_obj_add_flag(ui_BarBierProgress,LV_OBJ_FLAG_HIDDEN);
	lv_obj_clear_flag(ui_ButtonBierStart,LV_OBJ_FLAG_HIDDEN);
  lv_bar_set_value(ui_BarBierProgress,0,LV_ANIM_OFF);
	lv_disp_load_scr(ui_ScreenBierFlowing);	
	//lv_timer_t *timer = lv_timer_create(beerTimerFinished, config_tap_duration, NULL);
}

void beerStart()
{
  lv_timer_t *timer = lv_timer_create(beerTimerProgress, tap_duration / 10, NULL);
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
  static String prevShortMsg = "";
  static String prevLongMsg = "";
  static bool prevBDisplayQRCode = false;

  if ( ! shortMsg.equals(prevShortMsg)) {
    lv_label_set_text(ui_LabelAboutStatus,shortMsg.c_str());
    prevShortMsg = shortMsg;    
  }
  
  if ( ! longMsg.equals(prevLongMsg)) {
    lv_label_set_text(ui_LabelConfigStatus,longMsg.c_str());
    prevLongMsg = longMsg;
  }

  if ( bDisplayQRCode != prevBDisplayQRCode ) {
    prevBDisplayQRCode = bDisplayQRCode;
    if ( bDisplayQRCode ) {
      lv_obj_clear_flag(ui_QrcodeLnurl,LV_OBJ_FLAG_HIDDEN);
    } else {
      lv_obj_add_flag(ui_QrcodeLnurl,LV_OBJ_FLAG_HIDDEN);
    }
  }
}



void webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {
  switch(type) {
    case WStype_DISCONNECTED:
      if ( WiFi.status() == WL_CONNECTED ) {
        deviceState = CONNECTED;
      } else {
        deviceState = OFFLINE;
      }
      break;
    case WStype_CONNECTED:
      webSocket.sendTXT("Connected");
      deviceState = READY_TO_SERVE;
      break;
    case WStype_TEXT:
      {
        Serial.println("Go a WebSocket Message");
        DynamicJsonDocument doc(2000);
        DeserializationError error = deserializeJson(doc, (char *)payload);
        if ( error.code() !=  DeserializationError::Ok ) {
          Serial.println("Error JSON parse");
          return;
        }

        // get the message type
        String event = doc["event"].as<String>();
        Serial.printf("Event type = %s\n",event.c_str());

        if ( event == EVENT_PAID ) {
          payment_hash = doc["payment_hash"].as<String>();
          String payload = doc["payload"].as<String>();
          tap_duration = atoi(payload.c_str());
          beerScreen();
          notifyOrderReceived();
        }

      }
      break;
    default:
			break;
  }
}

void wantBierClicked(int item) {
  if ( config_numswitches == 0 ) {
    lv_disp_load_scr(ui_ScreenPin);	
    return;
  }

  //als we de pagina laden? 
  lv_qrcode_update(ui_QrcodeLnurl, config_lnurl[item].c_str(), config_lnurl[item].length());
  lv_disp_load_scr(ui_ScreenMain);	
  lv_label_set_text(ui_LabelMainProduct,config_label[item].c_str());

  // todo: zet nog een label op het screen erbij  
}


void myDelay(uint32_t ms) {
  delay(ms);
}

void loadConfig() {
  File file = LittleFS.open("/config.json", "r");
  if (file) {

    //  StaticJsonDocument<2000> doc;
    DynamicJsonDocument doc(2000);
    String content = file.readString();
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

  //StaticJsonDocument<2000> doc;
  DynamicJsonDocument doc(2000);

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
  // clear path
  config_wspath = "";

  String config_url = "https://";
  config_url += config_lnbitshost;
  config_url += "/bliksembier/api/v1/device/";
  config_url += deviceid;
  config_url += "/switches";

  HTTPClient http;
  http.begin(config_url);
  int statusCode = http.GET();
  Serial.printf("Status code %d\n",statusCode);
  if ( statusCode == HTTP_CODE_NOT_FOUND ) {
    deviceState = ERROR_UNKNOWN_DEVICEID;
    return false;
  }
  else if ( statusCode != HTTP_CODE_OK ) {
    deviceState = ERROR_CONFIG_HTTP;
    return false;
  }  

  // obtain the payload
  String payload = http.getString();                
  http.end();

  StaticJsonDocument<2000> doc;
  DeserializationError error = deserializeJson(doc, payload);
  if ( error.code() !=  DeserializationError::Ok ) {
    deviceState = ERROR_CONFIG_JSON;
    return false;
  }

  // clear current switches
  config_numswitches = 0;
  
  // bewaar opties in een keuzelijstje
  JsonArray switches = doc["switches"].as<JsonArray>();
  config_numswitches = switches.size() < BLIKSEMBIER_CFG_MAX_SWITCHES ? switches.size() : BLIKSEMBIER_CFG_MAX_SWITCHES;
  for (int i=0;i < config_numswitches;i++) {
    JsonObject obj = switches[i];
    config_lnurl[i] = obj["lnurl"].as<String>();
    config_label[i] = obj["label"].as<String>();
  }

  config_wspath = "/api/v1/ws/" + config_deviceid;

  switch ( config_numswitches ) {
    case 0:
      lv_obj_clear_flag(ui_ButtonAboutOne,LV_OBJ_FLAG_HIDDEN);
      lv_obj_add_flag(ui_ButtonAboutTwo,LV_OBJ_FLAG_HIDDEN);
      lv_obj_add_flag(ui_ButtonAboutThree,LV_OBJ_FLAG_HIDDEN);
      lv_obj_set_x(ui_ButtonAboutOne, 0);
      lv_label_set_text(ui_LabelAboutOne, "CONFIG");
      config_wspath = "";
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

  return true;
}


void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(2000);

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

  // initialize the QR code
  lv_color_t bg_color = lv_color_hex(0xFFFFFF);
  lv_color_t fg_color = lv_color_hex(0x000000);
  ui_QrcodeLnurl = lv_qrcode_create(ui_ScreenMain,240,fg_color,bg_color);
  lv_obj_center(ui_QrcodeLnurl);
  lv_obj_set_pos(ui_QrcodeLnurl,-3, 7);
  lv_obj_set_style_border_width(ui_QrcodeLnurl, 0, 0);
  lv_obj_add_flag(ui_QrcodeLnurl, LV_OBJ_FLAG_HIDDEN);

  // connect to servo
  servo.attach(BIER_SERVO_PIN);
  beerClose();
  webSocket.onEvent(webSocketEvent);

  // set label in the About screen
  setUIStatus("Initialized","Initialized");

}

void loop()
{
  int retryInMillis = 0;

  // update handlers
  lv_timer_handler();  

  webSocket.loop();
  // do something base on the state we are in
  switch ( deviceState ) {
    case OFFLINE:
      setUIStatus("Initialized","Initialized");

      // try to connect to WiFi
      if ( config_wifi_ssid.length() > 0 ) {
        WiFi.disconnect();
        WiFi.begin(config_wifi_ssid.c_str(),config_wifi_pwd.c_str());
        deviceState = CONNECTING;
      }
      break;
    case CONNECTING:
      setUIStatus("Connecting to Wi-Fi","Connecting to Wi-Fi");

      if ( WiFi.status() == WL_CONNECTED ) {
        deviceState = CONNECTED;
      } 

      break;
    case CONNECTED:
      setUIStatus("Wi-Fi connected","Connected to Wi-Fi network");
      {
        webSocket.setReconnectInterval(86400000);
        webSocket.disconnect();
        bool bResult = getLNURLSettings(config_deviceid);
        if ( bResult == true ) {
          deviceState = CONNECTING_WEBSOCKET;
          webSocket.setReconnectInterval(1000);
          webSocket.beginSSL(config_lnbitshost, 443, config_wspath);
        }
      }
      break;
    case CONNECTING_WEBSOCKET:
      setUIStatus("Connecting WebSocket","Connecting WebSocket");
      break;
    case READY_TO_SERVE:
      setUIStatus("Ready to Serve!","WebSocket Connected",true);
      break;
    case ERROR_UNKNOWN_DEVICEID:
      setUIStatus("Configuration error","DeviceID incorrect");
      break;
    case ERROR_CONFIG_HTTP:
      setUIStatus("Configuration error","Error response from LNbits");
      retryInMillis = millis() + 10000;
      deviceState = WAITING_FOR_RECONNECT;
      break;
    case ERROR_CONFIG_JSON:
      setUIStatus("Configuration error","Error parsing JSON config");      
      retryInMillis = millis() + 10000;
      deviceState = WAITING_FOR_RECONNECT;
    case WAITING_FOR_RECONNECT:
      if ( millis() > retryInMillis ) {
        if ( WiFi.isConnected() ) {
          deviceState = CONNECTED;
        } else {
          deviceState = OFFLINE;
        }
      }
      break;
    default:
      setUIStatus("Unknown state","Unknown device state");
      deviceState = OFFLINE;
      break;
  }
}
