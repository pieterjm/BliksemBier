#include <Arduino.h>
#include <ArduinoOTA.h>
#include <esp32_smartdisplay.h>
#include "bliksembier.h"
#include "ui.h"
#include <ESP32Servo.h>
#include <WebSocketsClient.h>
#include <LittleFS.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>


// config variables
int config_servo_back = 180;
int config_servo_close = 180;
int config_servo_open = 70;
String config_wifi_ssid = "";
String config_wifi_pwd = "";
String config_lnurldeviceid = "";
String config_invoicekey = "";
String config_adminkey = "";
String config_wallet = "";
String config_lnurl = "";
int config_tap_duration = 8000;
String config_pin = String(CONFIG_PIN);
String config_cfgserver = "www.meulenhoff.org";
String config_deviceid = "";

// two booleans to pass instructions to the main loop
bool bWiFiReconnect = true;
bool bLoadDeviceSettings = false;
bool bWebSocketReconnect = false;
String config_wshost = "";
String config_wspath = "";

Servo servo;
WebSocketsClient webSocket;
lv_obj_t *ui_QrcodeLnurl = NULL; // the QR code object
lv_obj_t *ui_QrcodeWallet = NULL; 

// defines for the config file
#define BLIKSEMBIER_CFG_SSID "ssid"
#define BLIKSEMBIER_CFG_WIFIPASS "wifipassword"
#define BLIKSEMBIER_CFG_SERVO_BACK "servoback"
#define BLIKSEMBIER_CFG_SERVO_CLOSE "servoclose"
#define BLIKSEMBIER_CFG_SERVO_OPEN "servoopen"
#define BLIKSEMBIER_CFG_TAP_DURATION "tapduration"
#define BLIKSEMBIER_CFG_CFGSERVER "cfgserver"
#define BLIKSEMBIER_CFG_DEVICEID "deviceid"
#define BLIKSEMBIER_CFG_PIN "pin"

// defines for the QR code
#define QRCODE_PIXEL_SIZE 3
#define QRCODE_X_OFFSET 10
#define QRCODE_Y_OFFSET 10

void beerClose() {
  servo.write(config_servo_close);
}

void beerOpen() {
  servo.write(config_servo_open);
}

void beerClean() {
  servo.write(config_servo_back);
}

void connectBliksemBier(const char *ssid,const char *pwd, const char *deviceid,const char *configserver) {
  config_wifi_ssid = String(ssid);
  config_wifi_pwd = String(pwd);
  config_deviceid = String(deviceid);
  config_cfgserver = String(configserver);
  bWiFiReconnect = true;
  saveConfig();
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
    lv_disp_load_scr(ui_ScreenMain);	  
  }
} 

void beer()
{
  lv_bar_set_value(ui_BarBierProgress,0,LV_ANIM_OFF);
	lv_disp_load_scr(ui_ScreenBierFlowing);	
	//lv_timer_t *timer = lv_timer_create(beerTimerFinished, config_tap_duration, NULL);
  lv_timer_t *timer = lv_timer_create(beerTimerProgress, config_tap_duration / 10, NULL);
  lv_timer_set_repeat_count(timer,10);
	beerOpen();    
}

void setUIStatus(bool bWiFiConnected,bool bConfigLoaded, bool bWebSocketConnected) {
  if ( bWebSocketConnected ) {
    lv_label_set_text(ui_LabelAboutStatus,"WebSocket connected");
    lv_label_set_text(ui_LabelMainWebSocketStatus,"WS OK");
    lv_label_set_text(ui_LabelMainWiFiStatus,"Wi-Fi OK");
    lv_label_set_text(ui_LabelConfigStatus,"Wi-Fi connected\nConfiguration loaded\nWebSocket connected");
    lv_obj_clear_flag(ui_QrcodeLnurl,LV_OBJ_FLAG_HIDDEN);
  } else if ( bConfigLoaded  ) {
    lv_label_set_text(ui_LabelAboutStatus,"Configuration loaded");
    lv_label_set_text(ui_LabelMainWebSocketStatus,"No WS");
    lv_label_set_text(ui_LabelMainWiFiStatus,"Wi-Fi OK");
    lv_label_set_text(ui_LabelConfigStatus,"Wi-Fi connected\nConfiguration loaded\nWebSocket not connected");
    lv_obj_add_flag(ui_QrcodeLnurl,LV_OBJ_FLAG_HIDDEN);
  } else if ( bWiFiConnected ) {
    lv_label_set_text(ui_LabelAboutStatus,"Wi-Fi Connected");
    lv_label_set_text(ui_LabelMainWebSocketStatus,"No WS");
    lv_label_set_text(ui_LabelMainWiFiStatus,"Wi-Fi OK");
    lv_label_set_text(ui_LabelConfigStatus,"Wi-Fi connected\nConfiguration not loaded\nWebSocket not connected");
    lv_obj_add_flag(ui_QrcodeLnurl, LV_OBJ_FLAG_HIDDEN);
  } else {
    lv_label_set_text(ui_LabelAboutStatus,"Wi-Fi not connected");
    lv_label_set_text(ui_LabelMainWebSocketStatus,"No WS");
    lv_label_set_text(ui_LabelMainWiFiStatus,"No Wi-Fi");
    lv_label_set_text(ui_LabelConfigStatus,"Wi-Fi not connected\nConfiguration not loaded\nWebSocket not connected");
    lv_obj_add_flag(ui_QrcodeLnurl, LV_OBJ_FLAG_HIDDEN);
  }
}

void webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {
  switch(type) {
    case WStype_DISCONNECTED:
      if ( WiFi.status() == WL_CONNECTED ) {
        setUIStatus(true,true,false);                  
      } else {
        setUIStatus(false,false,false);
      }
      break;
    case WStype_CONNECTED:
      webSocket.sendTXT("Connected");
      setUIStatus(true,true,true);
      break;
    case WStype_TEXT:
      beer();
      break;
    default:
			break;
  }
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
        } else if ( name == BLIKSEMBIER_CFG_CFGSERVER ) {
          config_cfgserver = String(value);     
        } else if ( name == BLIKSEMBIER_CFG_TAP_DURATION ) {
          config_tap_duration = String(value).toInt();
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
  doc[5]["name"] = BLIKSEMBIER_CFG_TAP_DURATION;
  doc[5]["value"] = config_tap_duration;
  doc[6]["name"] = BLIKSEMBIER_CFG_CFGSERVER;
  doc[6]["value"] = config_cfgserver;
  doc[7]["name"] = BLIKSEMBIER_CFG_PIN;
  doc[7]["value"] = config_pin;
  doc[8]["name"] = BLIKSEMBIER_CFG_DEVICEID;
  doc[8]["value"] = config_deviceid;

  String output = "";
  serializeJson(doc, output);
  serializeJson(doc, file);
  file.close();
}

void getLNURLSettings(String deviceid) 
{  
  // clear path
  config_wspath = "";
  config_wshost = "";

  String config_url = "https://";
  config_url += config_cfgserver;
  config_url += "/.well-known/bliksembier/";
  config_url += deviceid;
  config_url += ".json";

  HTTPClient http;
  http.begin(config_url);
  int statusCode = http.GET();
  if ( statusCode != HTTP_CODE_OK ) {
    return;
  }  

  // obtain the payload
  String payload = http.getString();                
  http.end();

  StaticJsonDocument<2000> doc;
  DeserializationError error = deserializeJson(doc, payload);
  if ( error.code() ==  DeserializationError::Ok ) {
    String id = doc["id"];
    String host = doc["host"];
    String lnurl = doc["lnurl"];
    config_wshost = host;
    config_wspath = "/api/v1/ws/" + id;
    lv_qrcode_update(ui_QrcodeLnurl, lnurl.c_str(), lnurl.length());
  }
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
  lv_textarea_set_text(ui_TextAreaConfigHost,config_cfgserver.c_str());
  lv_textarea_set_text(ui_TextAreaConfigDeviceID,config_deviceid.c_str());
  lv_label_set_text(ui_LabelPINValue,"");

  // initialize the QR code
  lv_color_t bg_color = lv_color_hex(0xFFFFFF);
  lv_color_t fg_color = lv_color_hex(0x000000);
  ui_QrcodeLnurl = lv_qrcode_create(ui_ScreenMain,240,fg_color,bg_color);
  lv_obj_center(ui_QrcodeLnurl);
  lv_obj_set_pos(ui_QrcodeLnurl,-3, -3);
  lv_obj_set_style_border_width(ui_QrcodeLnurl, 0, 0);
  lv_obj_add_flag(ui_QrcodeLnurl, LV_OBJ_FLAG_HIDDEN);

  // connect to servo
  servo.attach(BIER_SERVO_PIN);
  webSocket.onEvent(webSocketEvent);

  // Force WiFi to reconnect
  bWiFiReconnect = true;

  // set label in the About screen
  setUIStatus(false,false,false);
}

void loop()
{

  // reconnect to Wi-Fi 
  if ( bWiFiReconnect ) {
    bWiFiReconnect = false;
    WiFi.disconnect();
    WiFi.begin(config_wifi_ssid.c_str(),config_wifi_pwd.c_str());
    setUIStatus(false,false, false);

    bLoadDeviceSettings = true;
  }

  if ( bLoadDeviceSettings && WiFi.status() == WL_CONNECTED ) {
    bLoadDeviceSettings = false;
    setUIStatus(true,false, false);
    getLNURLSettings(config_deviceid);
    bWebSocketReconnect = true;
  }

  if ( bWebSocketReconnect && WiFi.status() == WL_CONNECTED && config_wshost.length() > 0 ) {
    bWebSocketReconnect = false;
    setUIStatus(true, true, false);
    webSocket.beginSSL(config_wshost, 443, config_wspath);
  }

  lv_timer_handler();  
  webSocket.loop();
}