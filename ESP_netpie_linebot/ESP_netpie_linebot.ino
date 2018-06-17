#include <ESP8266WiFi.h>
#include <MicroGear.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
const char* ssid     = "gummybea"; //change this to your SSID
const char* password = "30113011"; //change this to your PASSWORD

const char* host = "http://botlessrandomy.herokuapp.com/bot.php";
#define APPID   "botlesslinechat"     //change this to your APPID
#define KEY     "1MBZpxQIzpiTMKB"     //change this to your KEY
#define SECRET  "zW32kAlwlsiaxCDiNhtRO6rQk"     //change this to your SECRET

#define ALIAS   "NodeMCU1" //set name of drvice
#define TargetWeb "switch" //set target name of web

WiFiClient client;
String uid = "";
int timer = 0;
int setStatRadom = 0;
int waittimer = 9000;
String dataNev[12] = {"4705","8744","6454","245","544","197","355","221","847","305","978","333"} ;

unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change:
const long interval = 3000;

MicroGear microgear(client);

void onMsghandler(char *topic, uint8_t* msg, unsigned int msglen) { // 
Serial.print("Incoming message --> ");
  Serial.print(topic);
  Serial.print(" : ");
  char strState[msglen];

  for (int i = 0; i < msglen; i++) 
  {
    strState[i] = (char)msg[i];
    Serial.print((char)msg[i]);
  }
  Serial.println();

  String stateStr = String(strState).substring(0, msglen);

  if(stateStr == "เริ่ม") 
  {
    digitalWrite(LED_BUILTIN, HIGH);
    microgear.chat(TargetWeb, "เริ่ม");
    send_json("จะเริ่มแล้วนะ");
    setStatRadom = 1;
  } 
  else if (stateStr == "รอ") 
  {
    digitalWrite(LED_BUILTIN, LOW);
    microgear.chat(TargetWeb, "OFF");
    send_json("กำลังรอ");
    setStatRadom = 2;
  }else if(stateStr == "หยุด") 
  {
    digitalWrite(LED_BUILTIN, LOW);
    microgear.chat(TargetWeb, "OFF");
    send_json("หยุดแล้ว");
    setStatRadom = 0;
  }else{
    send_json("ฉันยังไม่เข้าใจ");
    }
  
   
}

void onConnected(char *attribute, uint8_t* msg, unsigned int msglen) {
    Serial.println("Connected to NETPIE...");
    microgear.setName(ALIAS);
}


void setup() {
    microgear.on(MESSAGE,onMsghandler);
    microgear.on(CONNECTED,onConnected);

    Serial.begin(115200);
    Serial.println("Starting...");

    pinMode(LED_BUILTIN, OUTPUT);
  
    if (WiFi.begin(ssid, password)) {
        while (WiFi.status() != WL_CONNECTED) {
            delay(500);
            Serial.print(".");
        }
    }

Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    microgear.init(KEY,SECRET,ALIAS);
    microgear.connect(APPID);
     digitalWrite(LED_BUILTIN, HIGH);   // LED on
}

void send_json(String data){
  StaticJsonBuffer<300> JSONbuffer;   //Declaring static JSON buffer
    JsonObject& JSONencoder = JSONbuffer.createObject(); 
 
    JSONencoder["ESP"] = data;
 
    JsonArray& values = JSONencoder.createNestedArray("values"); //JSON array
    values.add(20); //Add value to array
    values.add(21); //Add value to array
    values.add(23); //Add value to array
 
 
    char JSONmessageBuffer[300];
    JSONencoder.prettyPrintTo(JSONmessageBuffer, sizeof(JSONmessageBuffer));
    Serial.println(JSONmessageBuffer);
 
    HTTPClient http;    //Declare object of class HTTPClient
 
    http.begin(host);      //Specify request destination
    http.addHeader("Content-Type", "application/json");  //Specify content-type header
 
    int httpCode = http.POST(JSONmessageBuffer);   //Send the request
    String payload = http.getString();                                        //Get the response payload
 
    Serial.println(httpCode);   //Print HTTP return code
    Serial.println(payload);    //Print request response payload
 
    http.end();  //Close connection
}
void loop() {

    if (microgear.connected()) {
        Serial.println("..."); 
        microgear.loop();
        timer = 0;
    }
    else {
        Serial.println("connection lost, reconnect...");
        if (timer >= 5000) {
            microgear.connect(APPID); 
            timer = 0;
        }
        else timer += 100;
    }
    
    delay(100);
     unsigned long currentMillis = millis();  
if (currentMillis - previousMillis >= interval) {

    previousMillis = currentMillis;

     if(setStatRadom == 1){
      
      int pos = random(12);
      String msgsent = dataNev[pos];
      send_json(msgsent);

      }
      if(setStatRadom == 2){
         delay(waittimer);
         send_json("ไม่รอล่ะ");
            setStatRadom = 1;   
            
            
        }
  }
   

    
}
