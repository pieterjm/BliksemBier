#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <LittleFS.h>
#include <WebSocketsClient.h>
#include <Hash.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h> 
#include "Servo.h"
#include <ArduinoJson.h>
  
FS &FlashFS = LittleFS; 


#define SERVO_PIN 5 // D1
#define LED_PIN  4   // D2
#define BUTTON_PIN 0 // D3

#define JSON_WSURL "wsurl"
#define JSON_MAX_WAIT "max_wait"
#define JSON_MAX_TAP "max_tap"
#define JSON_SERVO_OPEN "servo_open"
#define JSON_SERVO_CLOSED "servo_closed"

// beer servo PIN
Servo beerServo;
bool gotbeer = true;

// Strings
#define WIFI_SSID "BliksemBier"
#define WIFI_PSK ""
#define ERROR_UNKNOWN_COMMAND_ARGUMENT "Unknown command argument."
#define ERROR_UNKNOWN_COMMAND "Unknown command."
#define ERROR_ACCESS_DENIED "Not allowed."
#define WSC_BEER_COMMAND "1-1"

bool shouldSaveConfig = false;

// config values and their defaults
char config_websocket_url[512] = "ws://legend.lnbits.com/api/v1/ws/DGrCiY5fGp6ZXMHDZ66aE8";
//ws://lnbits.meulenhoff.org/api/v1/ws/Tm3SNAmq88zsVb5mr7chtQ";
char config_max_wait[10] = "20000";
char config_max_tap[10] = "9000";
char config_servo_open[10] = "25";
char config_servo_closed[10] = "180";

// runtime parameters, assigning these parameters should not be
String websocket_host = "legend.lnbits.com";
String websocket_path = "/api/v1/ws/DGrCiY5fGp6ZXMHDZ66aE8";
long unsigned int max_wait = String(config_max_wait).toInt();
long unsigned int max_tap = String(config_max_tap).toInt();
int servo_open = String(config_servo_open).toInt();
int servo_closed = String(config_servo_closed).toInt();


bool bDebugMode = true; // verbose debug mode


#define BEER_STATE_UNAVAILABLE 0    // Beer tap not ready
#define BEER_STATE_AVAILABLE   1    // Beer tap ready to pour a beer
#define BEER_STATE_POURING     2    // Beer tap pouring beer
int beerState = BEER_STATE_UNAVAILABLE;

// led blink interval when available for pouring beer
#define LED_BLINK_OFF_INTERVAL 5000
#define LED_BLINK_ON_INTERVAL  100


const uint8_t LED_ACTIVE = LOW;

ESP8266WebServer server;
WebSocketsClient webSocket;

// this function pours some beer
bool beer()
{
  if ( beerState == BEER_STATE_AVAILABLE ) {
    beerState = BEER_STATE_POURING;
  } else {
    return false;
  }

  // turn on led
  digitalWrite(LED_PIN, HIGH);
  
  while ( digitalRead(BUTTON_PIN) != LOW ) {
    delay(50);
  }      
  unsigned long wait_millis = millis() + max_wait;
  unsigned long tap_millis = 0;
  beerServo.write(servo_open);
  int state = LOW;
  while (( millis() < wait_millis ) && ( tap_millis < max_tap)) {
    int newstate = digitalRead(BUTTON_PIN);
    if ( state != newstate ) {
      if ( newstate == LOW ) {
        beerServo.write(servo_open);
      } else {
        beerServo.write(servo_closed);
      }
      state = newstate;
    }
    if ( state == LOW ) {
      tap_millis += 50;
    }
    delay(100);
  }
  digitalWrite(LED_PIN,LOW);  
  beerServo.write(servo_closed);
  digitalWrite(LED_PIN,LOW);  

  
  // turn off led
  beerState = BEER_STATE_AVAILABLE;

  return true;
}


// callback function for handling websocket events
void webSocketEventHandler(WStype_t type, uint8_t *payload, size_t length) 
{
  switch (type)
  {
  case WStype_DISCONNECTED:
    if ( bDebugMode ) {
      Serial.printf("[WSc] Disconnected!\n");
    }

    // set beerState to available and blink led slowly
    beerState = BEER_STATE_UNAVAILABLE;

    break;
  case WStype_CONNECTED:
  {
    if ( bDebugMode ) {
      Serial.printf("[WSc] Connected to url: %s\n", payload);
      Serial.println("[WSc] SENT: Connected");
    }

    // set beerState to available and blink led slowly
    beerState = BEER_STATE_AVAILABLE;

    webSocket.sendTXT("Connected");
  }
  break;
  case WStype_TEXT:
    if ( bDebugMode ) {
      Serial.printf("[WSc] RESPONSE: %s\n", payload);
    }

    // Check if the payload is the beer command
    if ( String((char *)payload) == WSC_BEER_COMMAND ) {
      if ( bDebugMode ) {
        Serial.println("Pouring beer from websocker");
      }
      if ( beer() ) {
        Serial.println("Beer from websocket completed");
      } else {
        Serial.println("Beer from websocket not allowed. Customer could be wanting money back!");
      }
    }
    break;
  case WStype_BIN:
    if ( bDebugMode ) {
      Serial.printf("[WSc] get binary length: %u\n", length);
    }
    break;
  case WStype_PING:
    // pong will be send automatically
    //Serial.printf("[WSc] get ping\n");
    break;
  case WStype_PONG:
    // answer to a ping we send
    //Serial.printf("[WSc] get pong\n");
    break;
  case WStype_ERROR:
    if ( bDebugMode ) {
      Serial.println("]Wsc] Got error");
    }
    break;
  default:
    break;
  }
}

// get content type based on extension
String getContentType(String filename) {
  if (filename.endsWith(".html")) return "text/html";
  else if (filename.endsWith(".css")) return "text/css";
  else if (filename.endsWith(".gif")) return "image/gif";
  else if (filename.endsWith(".png")) return "image/png";
  else if (filename.endsWith(".js")) return "application/javascript";
  else if (filename.endsWith(".ico")) return "image/x-icon";
  else if (filename.endsWith(".gz")) return "application/x-gzip";
  return "text/plain";
}

// utility function for the webserver, provides files from the data directory
void handleFileRequest(String path) {
  if ( bDebugMode ) {
    Serial.println("Request for resource: " + path);
  }

  String contentType = getContentType(path);
  File file = LittleFS.open(path,"r");
  if ( file ) {
    server.streamFile(file, contentType);                 //Send it to the client
    file.close();                                                  //Close the file again
  } else {
    Serial.println("File does not exist");
    server.send(404, "text/plain", "404: Not Found");  
  }
}

// web server callback for current status, returns a JSON document with current status
void handleWebserverStatus() {
  switch ( beerState ) {
    case BEER_STATE_UNAVAILABLE:
      server.send(200,"application/json","{\"status\":\"unavailable\"}");
      break;
    case BEER_STATE_AVAILABLE:
      server.send(200,"application/json","{\"status\":\"available\"}");
      break;
    case BEER_STATE_POURING:
      server.send(200,"application/json","{\"status\":\"pouring\"}");
      break;
    default:
      server.send(200,"application/json","{\"status\":\"unknown\"}");
      break;
  }
}

// web server callback for beer
void handleWebserverBeer() {
  if ( gotbeer ) { 
    gotbeer = false;
    beer();
    server.send(200,"text/html","Here you go!");
  } else {
    server.send(200,"text/html","Out of beer");  
  }
}

/* load config from config.json and fall back to defaults in case of trouble */
void loadConfig() {
  // set all parameters to their defaults


  File file = LittleFS.open("/config.json","r");
  if ( file ) {
    DynamicJsonDocument config(2048);
    DeserializationError error = deserializeJson(config, file);
    Serial.println(error.c_str());
    file.close();
    
    if ( config.containsKey(JSON_MAX_WAIT)) {
      String tmp = config[JSON_MAX_WAIT];
      strcpy(config_max_wait,tmp.c_str());
      max_wait = tmp.toInt();
      Serial.print("Max wait set to: ");
      Serial.println(max_wait);
    }
    if ( config.containsKey(JSON_MAX_TAP)) {
      String tmp = config[JSON_MAX_TAP];
      strcpy(config_max_tap,tmp.c_str());
      max_tap = tmp.toInt();      
      Serial.print("Max tap set to: ");
      Serial.println(max_tap);
    }
    if ( config.containsKey(JSON_SERVO_OPEN)) {
      String tmp = config[JSON_SERVO_OPEN];
      strcpy(config_servo_open,tmp.c_str());
      servo_open = tmp.toInt();
      Serial.print("Servo open set to: ");
      Serial.println(servo_open);
    }
    if ( config.containsKey(JSON_SERVO_CLOSED)) {
      String tmp = config[JSON_SERVO_CLOSED];
      strcpy(config_servo_closed,tmp.c_str());
      servo_closed = tmp.toInt();
      Serial.print("Servo closed set to: ");
      Serial.println(servo_closed);
    }
    if ( config.containsKey("wsurl") ) {  
      String wsurl = config["wsurl"];
      strcpy(config_websocket_url,wsurl.c_str());
      Serial.print("Websocket URL: ");
      Serial.println(wsurl);

      if ( wsurl.startsWith("ws://") ) {
        wsurl = wsurl.substring(5);
      } else if ( wsurl.startsWith("wss://") ) {
        wsurl = wsurl.substring(6);
      } else {
        return;
      }
      int index = wsurl.indexOf("/");
      if ( index == -1 ) {
        return;
      }
      websocket_host = wsurl.substring(0,index);
      websocket_path = wsurl.substring(index);
      Serial.print("Websocket host: ");
      Serial.println(websocket_host);
      Serial.print("Websocket Path: ");
      Serial.println(websocket_path);

    }
  

  }
}
  

// blink the led in a non-blocking way
void flashLed() {
  static long nextMillis = 0;
  static bool _ledState = LOW;

  // we slowly flash the led when in a good state, ready for beer serving
  long currentMillis = millis();
  if ( currentMillis > nextMillis ) {
    if ( _ledState == LOW ) {
      _ledState = HIGH;
      nextMillis = currentMillis + LED_BLINK_ON_INTERVAL;
    } else {
      _ledState = LOW;
      nextMillis = currentMillis + LED_BLINK_OFF_INTERVAL;
    }
    digitalWrite(LED_PIN, _ledState);
  }
}

// WiFiManager requiring config save callback
void saveConfigCallback () {
	shouldSaveConfig = true;
}

void setup()
{
  beerServo.write(servo_closed); // close servo valve
  beerServo.attach(SERVO_PIN);
  beerServo.write(servo_closed); // close servo valve
  
  // Initialise serial port and print welcome message
  Serial.begin(115200);

  // initialize input button and LED
  pinMode(LED_PIN, OUTPUT); 
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // initialize flash storage
  Serial.println("Initializing flash storage");
  if ( !LittleFS.begin() ) {
    Serial.println("Could not start Flash Filesystem");
  }

  // wait 10 seconds, if there is a button press, reset wifi
  delay(2000);
  digitalWrite(LED_PIN, HIGH);  // turn off the LED
  bool bResetWifi = false;
  for(int i=0;(i<50);i++) {
    if ( digitalRead(BUTTON_PIN) == LOW ) {
      bResetWifi = true;
      break;
    }
    delay(100);
  }
  digitalWrite(LED_PIN, LOW);  // turn off the LED

  // load config
  Serial.println("Loading config");
  delay(1000);
  loadConfig();



  // Create wifi manager
  
  Serial.println("Initializing wifi manager");
  delay(1000);
  WiFiManager wifiManager;
  WiFiManagerParameter wm_wsurl(JSON_WSURL,"WebSocket URL",config_websocket_url,512);
  WiFiManagerParameter wm_max_wait(JSON_MAX_WAIT,"Max wait (ms)",config_max_wait,10);
  WiFiManagerParameter wm_max_tap(JSON_MAX_TAP,"Max tap (ms)",config_max_tap,10);
  WiFiManagerParameter wm_servo_open(JSON_SERVO_OPEN,"Tap open (deg)",config_servo_open,10);
  WiFiManagerParameter wm_servo_closed(JSON_SERVO_CLOSED,"Tap closed (deg)",config_servo_closed,10);
  wifiManager.setSaveConfigCallback(saveConfigCallback);
  wifiManager.addParameter(&wm_wsurl);
  wifiManager.addParameter(&wm_max_wait);
  wifiManager.addParameter(&wm_max_tap);
  wifiManager.addParameter(&wm_servo_open);
  wifiManager.addParameter(&wm_servo_closed);
  wifiManager.setConnectTimeout(10);

  Serial.println("After wifi manager configuration");
  delay(1000);

  // Start config portal if button pressed during boot
  if ( bResetWifi ) {
    Serial.println("Going to reset wifi");
    delay(1000);
    wifiManager.startConfigPortal(WIFI_SSID);
  } else {
    Serial.println("Autoconnect");
    delay(1000);
    wifiManager.autoConnect(WIFI_SSID);
  }

  Serial.println("After wifi manager");
  delay(1000);
  if ( shouldSaveConfig ) {
    Serial.println("Should save config");
    delay(1000);

    // get values from config
    strcpy(config_websocket_url,wm_wsurl.getValue());
    strcpy(config_max_tap,wm_max_tap.getValue());
    strcpy(config_max_wait,wm_max_wait.getValue());
    strcpy(config_servo_open,wm_servo_open.getValue());
    strcpy(config_servo_closed,wm_servo_closed.getValue());
    

    // create json document and set variables
    DynamicJsonDocument config(2048);
		config[JSON_WSURL] = config_websocket_url;
    config[JSON_MAX_WAIT] = config_max_wait;
    config[JSON_MAX_TAP] = config_max_tap;
    config[JSON_SERVO_OPEN] = config_servo_open;
    config[JSON_SERVO_CLOSED] = config_servo_closed;
    
	  File file = LittleFS.open("/config.json", "w");
    if ( file ) {
      serializeJson(config, file);
      file.close();
    }

    // restart ESP
    ESP.restart();
  }

  // attaching servo  
  Serial.println("Attaching servo");
  delay(1000);

  beerServo.write(servo_closed); // close servo valve
  beerServo.attach(SERVO_PIN);
  delay(1000);
  beerServo.write(servo_closed); // close servo valve

  
  // Start websockets client
  delay(1000);
  Serial.println("Initializing WebSocket client");
  webSocket.beginSSL(websocket_host.c_str(), 443, websocket_path.c_str());
  webSocket.onEvent(webSocketEventHandler);
  webSocket.setReconnectInterval(5000);

  // web server config
  server.on("/status",HTTP_GET,handleWebserverStatus);
  server.serveStatic("/",LittleFS,"/");
  server.begin();

  delay(1000);

  // turn of ledd
  digitalWrite(LED_PIN, HIGH);  // turn off the LED
}

void loop()
{
  // keep webserver running
  server.handleClient();

  // keep websocket connection running
  webSocket.loop();

  // handle the Led (and blinking)
  if ( beerState == BEER_STATE_AVAILABLE ) {  
    flashLed(); 
  }


}
