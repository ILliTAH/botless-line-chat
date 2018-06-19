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

#define ButtonStart1 16
#define ButtonStart2 5
#define ButtonStart3 4
#define ButtonStart4 0
#define ButtonStart5 2
#define ButtonPause 14
#define ButtonStop 12

#define ButtonRule 13
#define ButtonOther 15

int startStatus1 = 1;
int startStatus2 = 1;
int startStatus3 = 1;
int startStatus4 = 1;
int startStatus5 = 1;
int pauseStatus = 1;
int stopStatus = 1;
int ruleStatus = 1;
int otherStatus = 1;


String uid = "";
int timer = 0;
int setStatRadom1 = 0;
int setStatRadom2 = 0;
int setStatRadom3 = 0;
int setStatRadom4 = 0;
int setStatRadom5 = 0;
int waittimer = 9000;

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

  if(stateStr == "เริ่ม1") 
  {
    digitalWrite(LED_BUILTIN, HIGH);
    microgear.chat(TargetWeb, "เริ่ม");
    send_json("การสุ่ม รางวัลที่ 1 \r\n จะเริ่มแล้วนะ");
    setStatRadom1 = 1;
  }else 
  if(stateStr == "เริ่ม2") 
  {
    digitalWrite(LED_BUILTIN, HIGH);
    microgear.chat(TargetWeb, "เริ่ม");
    send_json("การสุ่ม รางวัลที่ 2 \r\n จะเริ่มแล้วนะ");
    setStatRadom2 = 1;
  }else 
  if(stateStr == "เริ่ม3") 
  {
    digitalWrite(LED_BUILTIN, HIGH);
    microgear.chat(TargetWeb, "เริ่ม");
    send_json("การสุ่ม รางวัลที่ 3 \r\n จะเริ่มแล้วนะ");
    setStatRadom3 = 1;
  }else 
  if(stateStr == "เริ่ม4") 
  {
    digitalWrite(LED_BUILTIN, HIGH);
    microgear.chat(TargetWeb, "เริ่ม");
    send_json("การสุ่ม รางวัลที่ 4 \r\n จะเริ่มแล้วนะ");
    setStatRadom4 = 1;
  }else 
  if(stateStr == "เริ่ม5") 
  {
    digitalWrite(LED_BUILTIN, HIGH);
    microgear.chat(TargetWeb, "เริ่ม");
    send_json("การสุ่ม รางวัลที่ 5 \r\n จะเริ่มแล้วนะ");
    setStatRadom5 = 1;
  } 
  else if (stateStr == "รอ") 
  {
    digitalWrite(LED_BUILTIN, LOW);
    microgear.chat(TargetWeb, "OFF");
    if(setStatRadom1 == 1|| setStatRadom2 == 1|| setStatRadom3 == 1|| setStatRadom4 == 1 ||setStatRadom5 == 1){
    send_json("กำลังรอ");
    if(setStatRadom1 == 1)
      setStatRadom1 = 2;
    if(setStatRadom2 == 1)
      setStatRadom2 = 2;
    if(setStatRadom3 == 1)
      setStatRadom3 = 2;
    if(setStatRadom4 == 1)
      setStatRadom4 = 2;
    if(setStatRadom5 == 1)
      setStatRadom5 = 2;
      }else {
        send_json("ข้อผิดพลาด !\r\nยังไม่มีการเริ่มหรือคุณอาจส่งคำสั่งการรอมากไป");
      }
  }else if(stateStr == "หยุด") 
  {
    digitalWrite(LED_BUILTIN, LOW);
    microgear.chat(TargetWeb, "OFF");
    send_json("หยุดแล้ว");
    setStatRadom1 = 0;
    setStatRadom2 = 0;
    setStatRadom3 = 0;
    setStatRadom4 = 0;
    setStatRadom5 = 0;
  }else if(stateStr == "กติกา") 
  {
    digitalWrite(LED_BUILTIN, LOW);
    microgear.chat(TargetWeb, "OFF");
    String rule = " ";
        rule += "***** กติกาการเล่น *****\r\n";
        rule += "ใส่ข้อความ\r\n";
        rule += "ใส่ข้อความ\r\n";
        rule += "ใส่ข้อความ";
    
    send_json(rule);  
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
    pinMode(ButtonStart1,INPUT_PULLUP);
    pinMode(ButtonStart2,INPUT_PULLUP);
    pinMode(ButtonStart3,INPUT_PULLUP);
    pinMode(ButtonStart4,INPUT_PULLUP);
    pinMode(ButtonStart5,INPUT_PULLUP);
    pinMode(ButtonPause,INPUT_PULLUP);
    pinMode(ButtonStop,INPUT_PULLUP);
    pinMode(ButtonRule,INPUT_PULLUP);
    pinMode(ButtonOther,INPUT_PULLUP);
    
    
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


void buttonEvent(){

  startStatus1 = digitalRead(ButtonStart1);
  startStatus2 = digitalRead(ButtonStart2);
  startStatus3 = digitalRead(ButtonStart3);
  startStatus4 = digitalRead(ButtonStart4);
  startStatus5 = digitalRead(ButtonStart5);

  pauseStatus = digitalRead(ButtonPause);
  stopStatus = digitalRead(ButtonStop);
  ruleStatus = digitalRead(ButtonRule);
  otherStatus = digitalRead(ButtonOther);
  
    if(startStatus1 == 0) 
  {
    digitalWrite(LED_BUILTIN, HIGH);
    microgear.chat(TargetWeb, "เริ่ม");
    send_json("การสุ่ม รางวัลที่ 1 \r\n จะเริ่มแล้วนะ");
    setStatRadom1 = 1;
  }else 
  if(startStatus2 == 0) 
  {
    digitalWrite(LED_BUILTIN, HIGH);
    microgear.chat(TargetWeb, "เริ่ม");
    send_json("การสุ่ม รางวัลที่ 2 \r\n จะเริ่มแล้วนะ");
    setStatRadom2 = 1;
  }else 
  if(startStatus3 == 0) 
  {
    digitalWrite(LED_BUILTIN, HIGH);
    microgear.chat(TargetWeb, "เริ่ม");
    send_json("การสุ่ม รางวัลที่ 3 \r\n จะเริ่มแล้วนะ");
    setStatRadom3 = 1;
  }else 
  if(startStatus4 == 0) 
  {
    digitalWrite(LED_BUILTIN, HIGH);
    microgear.chat(TargetWeb, "เริ่ม");
    send_json("การสุ่ม รางวัลที่ 4 \r\n จะเริ่มแล้วนะ");
    setStatRadom4 = 1;
  }else 
  if(startStatus5 == 0) 
  {
    digitalWrite(LED_BUILTIN, HIGH);
    microgear.chat(TargetWeb, "เริ่ม");
    send_json("การสุ่ม รางวัลที่ 5 \r\n จะเริ่มแล้วนะ");
    setStatRadom5 = 1;
  } 
  else if (pauseStatus == 0) 
  {
    digitalWrite(LED_BUILTIN, LOW);
    microgear.chat(TargetWeb, "OFF");
    if(setStatRadom1 == 1|| setStatRadom2 == 1|| setStatRadom3 == 1|| setStatRadom4 == 1 ||setStatRadom5 == 1){
    send_json("กำลังรอ");
    if(setStatRadom1 == 1)
      setStatRadom1 = 2;
    if(setStatRadom2 == 1)
      setStatRadom2 = 2;
    if(setStatRadom3 == 1)
      setStatRadom3 = 2;
    if(setStatRadom4 == 1)
      setStatRadom4 = 2;
    if(setStatRadom5 == 1)
      setStatRadom5 = 2;
      }else {
        send_json("ข้อผิดพลาด !\r\nยังไม่มีการเริ่มหรือคุณอาจส่งคำสั่งการรอมากไป");
      }
  }else if(stopStatus == 0) 
  {
    digitalWrite(LED_BUILTIN, LOW);
    microgear.chat(TargetWeb, "OFF");
    send_json("หยุดแล้ว");
    setStatRadom1 = 0;
    setStatRadom2 = 0;
    setStatRadom3 = 0;
    setStatRadom4 = 0;
    setStatRadom5 = 0;
  }else if(ruleStatus == 0) 
  {
    digitalWrite(LED_BUILTIN, LOW);
    microgear.chat(TargetWeb, "OFF");
    String rule = " ";
        rule += "***** กติกาการเลิ่น *****\r\n";
        rule += "ใส่ข้อความ\r\n";
        rule += "ใส่ข้อความ\r\n";
        rule += "ใส่ข้อความ";
    
    send_json(rule);
    
  }else if(otherStatus == 0) 
  {
    digitalWrite(LED_BUILTIN, LOW);
    microgear.chat(TargetWeb, "OFF");
    String other = " ";
        other += "***** อื่นๆใส่ข้อความ *****\r\n";
        other += "ใส่ข้อความ\r\n";
        other += "ใส่ข้อความ\r\n";
        other += "ใส่ข้อความ";
    
    send_json(other);
    
  }else{
//    int pos = random(4);
//    String msg = errorMSG[pos];
//    send_json(msg);
    }
  
  
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

     if(setStatRadom1 == 1){
      
      int pos = random(12);
      int numRandom = random(1000,9999);
      String msgsent = String(numRandom);
      String texFormate = " ";
        texFormate += "ผลที่ส่งทางไลน์\r\n";
        texFormate += "รางวัลประจำเดือนมิถุนายน 61\r\n";
        texFormate += "รางวัลที่ 1\r\n";
        texFormate += "เลขที่ออก ";
        texFormate += msgsent;

      send_json(texFormate);

      }
      if(setStatRadom1 == 2){
         delay(waittimer);
         send_json("สิ้นสุดการรอ");
            setStatRadom1 = 1;   
     
        }
       if(setStatRadom2 == 2){
         delay(waittimer);
         send_json("สิ้นสุดการรอ");
            setStatRadom2 = 1;   
     
        }
       if(setStatRadom3 == 2){
         delay(waittimer);
         send_json("สิ้นสุดการรอ");
            setStatRadom3 = 1;   
     
        }
       if(setStatRadom4 == 2){
         delay(waittimer);
         send_json("สิ้นสุดการรอ");
            setStatRadom4 = 1;   
     
        }
      if(setStatRadom5 == 2){
         delay(waittimer);
         send_json("สิ้นสุดการรอ");
            setStatRadom5 = 1;   
     
        }

        if(setStatRadom2 == 1){
      
      int pos = random(12);
      int numRandom = random(1000,9999);
      String msgsent = String(numRandom);
      String texFormate = " ";
        texFormate += "ผลที่ส่งทางไลน์\r\n";
        texFormate += "รางวัลประจำเดือนมิถุนายน 61\r\n";
        texFormate += "รางวัลที่ 2\r\n";
        texFormate += "เลขที่ออก ";
        texFormate += msgsent;

      send_json(texFormate);
      }

      if(setStatRadom3 == 1){
      
      int pos = random(12);
      int numRandom = random(1000,9999);
      String msgsent = String(numRandom);
      String texFormate = " ";
        texFormate += "ผลที่ส่งทางไลน์\r\n";
        texFormate += "รางวัลประจำเดือนมิถุนายน 61\r\n";
        texFormate += "รางวัลที่ 3\r\n";
        texFormate += "เลขที่ออก ";
        texFormate += msgsent;

      send_json(texFormate);
      }

      if(setStatRadom4 == 1){
      
      int pos = random(12);
      int numRandom = random(1000,9999);
      String msgsent = String(numRandom);
      String texFormate = " ";
        texFormate += "ผลที่ส่งทางไลน์\r\n";
        texFormate += "รางวัลประจำเดือนมิถุนายน 61\r\n";
        texFormate += "รางวัลที่ 4\r\n";
        texFormate += "เลขที่ออก ";
        texFormate += msgsent;

      send_json(texFormate);
      }

      if(setStatRadom5 == 1){
      
      int pos = random(12);
      int numRandom = random(1000,9999);
      String msgsent = String(numRandom);
      String texFormate = " ";
        texFormate += "ผลที่ส่งทางไลน์\r\n";
        texFormate += "รางวัลประจำเดือนมิถุนายน 61\r\n";
        texFormate += "รางวัลที่ 5\r\n";
        texFormate += "เลขที่ออก ";
        texFormate += msgsent;

      send_json(texFormate);
      }

      
  }
   

    
}
