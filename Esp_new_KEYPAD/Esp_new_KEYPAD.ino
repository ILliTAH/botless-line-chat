#include <ESP8266WiFi.h>
#include <MicroGear.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
//
const char* ssid     = "CHILL VAPOR WIFI_2.4G"; //change this to your SSID
const char* password = "Ponlakorn"; //change this to your PASSWORD
//const char* ssid     = "Carbon"; //change this to your SSID
//const char* password = "30113011"; //change this to your PASSWORD

const char* host = "http://botlessrandomy.herokuapp.com/bot.php";
#define APPID   "botlesslinechat"     //change this to your APPID
#define KEY     "1MBZpxQIzpiTMKB"     //change this to your KEY
#define SECRET  "zW32kAlwlsiaxCDiNhtRO6rQk"     //change this to your SECRET

#define ALIAS   "NodeMCU1" //set name of device
#define TargetWeb "switch" //set target name of web

WiFiClient client;

byte h=0,v=0;    
const unsigned long period=50;  
unsigned long kdelay=0;       
const byte rows=4;             
const byte columns=4;            
const byte Output[rows]={2,14,12,13}; 
const byte Input[columns]={16,5,4,0}; 
byte keypad() 
{
 static bool no_press_flag=0;  
  for(byte x=0;x<columns;x++)   
  {
     if (digitalRead(Input[x])==HIGH);   
     else
     break;
     if(x==(columns-1))   
     {
      no_press_flag=1;
      h=0;
      v=0;
     }
  }
  if(no_press_flag==1) 
  {
    for(byte r=0;r<rows;r++) 
    digitalWrite(Output[r],LOW);
    for(h=0;h<columns;h++)  
    {
      if(digitalRead(Input[h])==HIGH) 
      continue;
      else    
      {
          for (v=0;v<rows;v++)   
          {
          digitalWrite(Output[v],HIGH);   
          if(digitalRead(Input[h])==HIGH)  
          {
            no_press_flag=0;                
            for(byte w=0;w<rows;w++) 
            digitalWrite(Output[w],LOW);
            return v*4+h; 
          }
          }
      }
    }
  }
 return 50;
}



String uid = "";
int timer = 0;
int setStatRadom1 = 0;
int setStatRadom2 = 0;
int setStatRadom3 = 0;
int setStatRadom4 = 0;
int setStatRadom5 = 0;
int setStatRadom6 = 0;
int setStatRadom7 = 0;
int setStatRadom8 = 0;
int setStatRadom9 = 0;
int setStatRadom10 = 0;

int waittimer = 9000;     // เวลาในการ รอ

unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change:
const long interval = 3000;   // ระยะเวลาในการ สุ่มข้อความ


int startwaittimer = 5000;



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
    //digitalWrite(LED_BUILTIN, HIGH);
    microgear.chat(TargetWeb, "เริ่ม");
    send_json("การสุ่ม รางวัลที่ 1 \r\n จะเริ่มแล้วนะ");
    setStatRadom1 = 1;
    delay(startwaittimer);
  }else 
  if(stateStr == "เริ่ม2") 
  {
    //digitalWrite(LED_BUILTIN, HIGH);
    microgear.chat(TargetWeb, "เริ่ม");
    send_json("การสุ่ม รางวัลที่ 2 \r\n จะเริ่มแล้วนะ");
    setStatRadom2 = 1;
    delay(startwaittimer);
  }else 
  if(stateStr == "เริ่ม3") 
  {
    //digitalWrite(LED_BUILTIN, HIGH);
    microgear.chat(TargetWeb, "เริ่ม");
    send_json("การสุ่ม รางวัลที่ 3 \r\n จะเริ่มแล้วนะ");
    setStatRadom3 = 1;
    delay(startwaittimer);
  }else 
  if(stateStr == "เริ่ม4") 
  {
    //digitalWrite(LED_BUILTIN, HIGH);
    microgear.chat(TargetWeb, "เริ่ม");
    send_json("การสุ่ม รางวัลที่ 4 \r\n จะเริ่มแล้วนะ");
    setStatRadom4 = 1;
    delay(startwaittimer);
  }else 
  if(stateStr == "เริ่ม5") 
  {
    //digitalWrite(LED_BUILTIN, HIGH);
    microgear.chat(TargetWeb, "เริ่ม");
    send_json("การสุ่ม รางวัลที่ 5 \r\n จะเริ่มแล้วนะ");
    setStatRadom5 = 1;
    delay(startwaittimer);
  } else 
  if(stateStr == "เริ่ม6") 
  {
    //digitalWrite(LED_BUILTIN, HIGH);
    microgear.chat(TargetWeb, "เริ่ม");
    send_json("การสุ่ม รางวัลที่ 6 \r\n จะเริ่มแล้วนะ");
    setStatRadom6 = 1;
    delay(startwaittimer);
  }else 
  if(stateStr == "เริ่ม7") 
  {
    //digitalWrite(LED_BUILTIN, HIGH);
    microgear.chat(TargetWeb, "เริ่ม");
    send_json("การสุ่ม รางวัลที่ 7 \r\n จะเริ่มแล้วนะ");
    setStatRadom7 = 1;
    delay(startwaittimer);
  }else 
  if(stateStr == "เริ่ม8") 
  {
    //digitalWrite(LED_BUILTIN, HIGH);
    microgear.chat(TargetWeb, "เริ่ม");
    send_json("การสุ่ม รางวัลที่ 8 \r\n จะเริ่มแล้วนะ");
    setStatRadom8 = 1;
    delay(startwaittimer);
  }else 
  if(stateStr == "เริ่ม9") 
  {
    //digitalWrite(LED_BUILTIN, HIGH);
    microgear.chat(TargetWeb, "เริ่ม");
    send_json("การสุ่ม รางวัลที่ 9 \r\n จะเริ่มแล้วนะ");
    setStatRadom9 = 1;
    delay(startwaittimer);
  }else 
  if(stateStr == "เริ่ม10") 
  {
    //digitalWrite(LED_BUILTIN, HIGH);
    microgear.chat(TargetWeb, "เริ่ม");
    send_json("การสุ่ม รางวัลที่ 10 \r\n จะเริ่มแล้วนะ");
    setStatRadom10 = 1;
    delay(startwaittimer);
  }
  else if (stateStr == "รอ") 
  {
    //digitalWrite(LED_BUILTIN, LOW);
    microgear.chat(TargetWeb, "OFF");
    if(setStatRadom1 == 1|| setStatRadom2 == 1|| setStatRadom3 == 1|| setStatRadom4 == 1 ||setStatRadom5 == 1  ||setStatRadom6 == 1  ||setStatRadom7 == 1 ||setStatRadom8 == 1  ||setStatRadom9 == 1  || setStatRadom10 == 1){
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
    if(setStatRadom6 == 1)
      setStatRadom6 = 2;
    if(setStatRadom7 == 1)
      setStatRadom7 = 2;
    if(setStatRadom8 == 1)
      setStatRadom8 = 2;
    if(setStatRadom9 == 1)
      setStatRadom9 = 2;
    if(setStatRadom10 == 1)
      setStatRadom10 = 2;
      }else {
        send_json("ข้อผิดพลาด !\r\nยังไม่มีการเริ่มหรือคุณอาจส่งคำสั่งการรอมากไป");
      }
  }else if(stateStr == "หยุด") 
  {
    //digitalWrite(LED_BUILTIN, LOW);
    microgear.chat(TargetWeb, "OFF");
    send_json("หยุดแล้ว");
    setStatRadom1 = 0;
    setStatRadom2 = 0;
    setStatRadom3 = 0;
    setStatRadom4 = 0;
    setStatRadom5 = 0;
    setStatRadom6 = 0;
    setStatRadom7 = 0;
    setStatRadom8 = 0;
    setStatRadom9 = 0;
    setStatRadom10 = 0;
    
  }else if(stateStr == "กติกา") 
  {
//    //digitalWrite(LED_BUILTIN, LOW);
    microgear.chat(TargetWeb, "OFF");
    String rule = " ";
        rule += "***** กติกาการเล่น *****\r\n";
        rule += "ใส่ข้อความ\r\n";
        rule += "ใส่ข้อความ\r\n";
        rule += "ใส่ข้อความ";
    
    send_json(rule);  
  }else if (stateStr == "อื่นๆ1"){
    
     //digitalWrite(LED_BUILTIN, LOW);
    microgear.chat(TargetWeb, "OFF");
    String other = " ";
        other += "***** อื่นๆ1ใส่ข้อความ *****\r\n";
        other += "ใส่ข้อความ\r\n";
        other += "ใส่ข้อความ\r\n";
        other += "ใส่ข้อความ";
    
    send_json(other);
    
    
    
    
    }else if (stateStr == "อื่นๆ2"){
    
     //digitalWrite(LED_BUILTIN, LOW);
    microgear.chat(TargetWeb, "OFF");
    String other = " ";
        other += "***** อื่นๆ2ใส่ข้อความ *****\r\n";
        other += "ใส่ข้อความ\r\n";
        other += "ใส่ข้อความ\r\n";
        other += "ใส่ข้อความ";
    
    send_json(other);
    
    
    
    
    }else if (stateStr == "อื่นๆ3"){
    
     //digitalWrite(LED_BUILTIN, LOW);
    microgear.chat(TargetWeb, "OFF");
    String other = " ";
        other += "***** อื่นๆ3ใส่ข้อความ *****\r\n";
        other += "ใส่ข้อความ\r\n";
        other += "ใส่ข้อความ\r\n";
        other += "ใส่ข้อความ";
    
    send_json(other);
    
    
    
    
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

for(byte i=0;i<rows;i++)  
  {
  pinMode(Output[i],OUTPUT);
  }
  for(byte s=0;s<columns;s++)  
  {
    pinMode(Input[s],INPUT_PULLUP);
  }
    
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
     //digitalWrite(LED_BUILTIN, HIGH);   // LED on
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
//
//  Col1 = digitalRead(ButtonCo1);
//  Col2 = digitalRead(ButtonCo2);
//  Col3 = digitalRead(ButtonCo3);
//  Col4 = digitalRead(ButtonCo4);
//  
//  Row1 = digitalRead(ButtonRo1);
//  Row2 = digitalRead(ButtonRo2);
//  Row3 = digitalRead(ButtonRo3);
//  Row4 = digitalRead(ButtonRo4);
//
//  
//    if(Row1 == 0 && Col1 == 0) 
//  {
//    //digitalWrite(LED_BUILTIN, HIGH);
//    microgear.chat(TargetWeb, "เริ่ม");
//    send_json("การสุ่ม รางวัลที่ 1 \r\n จะเริ่มแล้วนะ");
//    setStatRadom1 = 1;
//  }else 
//  if(Row1 == 0 && Col2 == 0) 
//  {
//    //digitalWrite(LED_BUILTIN, HIGH);
//    microgear.chat(TargetWeb, "เริ่ม");
//    send_json("การสุ่ม รางวัลที่ 2 \r\n จะเริ่มแล้วนะ");
//    setStatRadom2 = 1;
//  }else 
//  if(Row1 == 0 && Col3 == 0) 
//  {
//    //digitalWrite(LED_BUILTIN, HIGH);
//    microgear.chat(TargetWeb, "เริ่ม");
//    send_json("การสุ่ม รางวัลที่ 3 \r\n จะเริ่มแล้วนะ");
//    setStatRadom3 = 1;
//  }else 
//  if(Row1 == 0 && Col4 == 0) 
//  {
//    //digitalWrite(LED_BUILTIN, HIGH);
//    microgear.chat(TargetWeb, "เริ่ม");
//    send_json("การสุ่ม รางวัลที่ 4 \r\n จะเริ่มแล้วนะ");
//    setStatRadom4 = 1;
//  }else 
//  if(Row2 == 0 && Col1 == 0) 
//  {
//    //digitalWrite(LED_BUILTIN, HIGH);
//    microgear.chat(TargetWeb, "เริ่ม");
//    send_json("การสุ่ม รางวัลที่ 5 \r\n จะเริ่มแล้วนะ");
//    setStatRadom5 = 1;
//  }
//  if(Row2 == 0 && Col2 == 0) 
//  {
//    //digitalWrite(LED_BUILTIN, HIGH);
//    microgear.chat(TargetWeb, "เริ่ม");
//    send_json("การสุ่ม รางวัลที่ 6 \r\n จะเริ่มแล้วนะ");
//    setStatRadom6 = 1;
//  }
//  if(Row2 == 0 && Col3 == 0) 
//  {
//    //digitalWrite(LED_BUILTIN, HIGH);
//    microgear.chat(TargetWeb, "เริ่ม");
//    send_json("การสุ่ม รางวัลที่ 7 \r\n จะเริ่มแล้วนะ");
//    setStatRadom7 = 1;
//  }
//  if(Row2 == 0 && Col4 == 0) 
//  {
//    //digitalWrite(LED_BUILTIN, HIGH);
//    microgear.chat(TargetWeb, "เริ่ม");
//    send_json("การสุ่ม รางวัลที่ 8 \r\n จะเริ่มแล้วนะ");
//    setStatRadom8 = 1;
//  }
//  if(Row3 == 0 && Col1 == 0) 
//  {
//    //digitalWrite(LED_BUILTIN, HIGH);
//    microgear.chat(TargetWeb, "เริ่ม");
//    send_json("การสุ่ม รางวัลที่ 9 \r\n จะเริ่มแล้วนะ");
//    setStatRadom9 = 1;
//  }
//  if(Row3 == 0 && Col2 == 0) 
//  {
//    //digitalWrite(LED_BUILTIN, HIGH);
//    microgear.chat(TargetWeb, "เริ่ม");
//    send_json("การสุ่ม รางวัลที่ 10 \r\n จะเริ่มแล้วนะ");
//    setStatRadom10 = 1;
//  }      
//  else if (Row3 == 0 && Col4 == 0) 
//  {
//    //digitalWrite(LED_BUILTIN, LOW);
//    microgear.chat(TargetWeb, "OFF");
//    if(setStatRadom1 == 1|| setStatRadom2 == 1|| setStatRadom3 == 1|| setStatRadom4 == 1 ||setStatRadom5 == 1  ||setStatRadom6 == 1  ||setStatRadom7 == 1  ||setStatRadom8 == 1  ||setStatRadom9 == 1  ||setStatRadom10 == 1){
//    send_json("กำลังรอ");
//    if(setStatRadom1 == 1)
//      setStatRadom1 = 2;
//    if(setStatRadom2 == 1)
//      setStatRadom2 = 2;
//    if(setStatRadom3 == 1)
//      setStatRadom3 = 2;
//    if(setStatRadom4 == 1)
//      setStatRadom4 = 2;
//    if(setStatRadom5 == 1)
//      setStatRadom5 = 2;
//    if(setStatRadom6 == 1)
//      setStatRadom6 = 2;
//    if(setStatRadom7 == 1)
//      setStatRadom7 = 2;
//    if(setStatRadom8 == 1)
//      setStatRadom8 = 2;
//    if(setStatRadom9 == 1)
//      setStatRadom9 = 2;
//    if(setStatRadom10 == 1)
//      setStatRadom10 = 2;
//      }else {
//        send_json("ข้อผิดพลาด !\r\nยังไม่มีการเริ่มหรือคุณอาจส่งคำสั่งการรอมากไป");
//      }
//  }else if(stopStatus == 0) 
//  {
//    //digitalWrite(LED_BUILTIN, LOW);
//    microgear.chat(TargetWeb, "OFF");
//    send_json("หยุดแล้ว");
//    setStatRadom1 = 0;
//    setStatRadom2 = 0;
//    setStatRadom3 = 0;
//    setStatRadom4 = 0;
//    setStatRadom5 = 0;
//    setStatRadom6 = 0;
//    setStatRadom7 = 0;
//    setStatRadom8 = 0;
//    setStatRadom9 = 0;
//    setStatRadom10 = 0;
//  }else if(ruleStatus == 0) 
//  {
//    //digitalWrite(LED_BUILTIN, LOW);
//    microgear.chat(TargetWeb, "OFF");
//    String rule = " ";
//        rule += "***** กติกาการเลิ่น *****\r\n";
//        rule += "ใส่ข้อความ\r\n";
//        rule += "ใส่ข้อความ\r\n";
//        rule += "ใส่ข้อความ";
//    
//    send_json(rule);
//    
//  }else if(otherStatus == 0) 
//  {
//    //digitalWrite(LED_BUILTIN, LOW);
//    microgear.chat(TargetWeb, "OFF");
//    String other = " ";
//        other += "***** อื่นๆใส่ข้อความ *****\r\n";
//        other += "ใส่ข้อความ\r\n";
//        other += "ใส่ข้อความ\r\n";
//        other += "ใส่ข้อความ";
//    
//    send_json(other);
//    
//  }else{
////    int pos = random(4);
////    String msg = errorMSG[pos];
////    send_json(msg);
//    }
//  
  
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

  if(millis()-kdelay>period) 
  {
    kdelay=millis();  
switch (keypad())  
   {
            case 0:
            {
             microgear.chat(TargetWeb, "เริ่ม");
    send_json("การสุ่ม รางวัลที่ 1 \r\n จะเริ่มแล้วนะ");
    setStatRadom1 = 1;
    delay(startwaittimer);
            }
       break;  
            case 1:
            {
            microgear.chat(TargetWeb, "เริ่ม");
    send_json("การสุ่ม รางวัลที่ 2 \r\n จะเริ่มแล้วนะ");
    setStatRadom2 = 1;
    delay(startwaittimer);
            }
       break;
            case 2:
            {
             microgear.chat(TargetWeb, "เริ่ม");
    send_json("การสุ่ม รางวัลที่ 3 \r\n จะเริ่มแล้วนะ");
    setStatRadom3 = 1;
    delay(startwaittimer);
            }
       break;
            case 3:
            {
             microgear.chat(TargetWeb, "เริ่ม");
    send_json("การสุ่ม รางวัลที่ 4 \r\n จะเริ่มแล้วนะ");
    setStatRadom4 = 1;
    delay(startwaittimer);
            }
       break;
            case 4:
            {
             microgear.chat(TargetWeb, "เริ่ม");
    send_json("การสุ่ม รางวัลที่ 5 \r\n จะเริ่มแล้วนะ");
    setStatRadom5 = 1;
    delay(startwaittimer);
            }
       break;
            case 5:
            {
             microgear.chat(TargetWeb, "เริ่ม");
    send_json("การสุ่ม รางวัลที่ 5 \r\n จะเริ่มแล้วนะ");
    setStatRadom5 = 1;
    delay(startwaittimer);
            }
       break;
            case 6:
            {
            microgear.chat(TargetWeb, "เริ่ม");
    send_json("การสุ่ม รางวัลที่ 7 \r\n จะเริ่มแล้วนะ");
    setStatRadom7 = 1;
    delay(startwaittimer);
            }
       break;
            case 7:
            {
            microgear.chat(TargetWeb, "เริ่ม");
    send_json("การสุ่ม รางวัลที่ 8 \r\n จะเริ่มแล้วนะ");
    setStatRadom8 = 1;
    delay(startwaittimer);
            }
       break;
            case 8:
            {
            microgear.chat(TargetWeb, "เริ่ม");
    send_json("การสุ่ม รางวัลที่ 9 \r\n จะเริ่มแล้วนะ");
    setStatRadom9 = 1;
    delay(startwaittimer);
            }
       break;
            case 9:
            {
            microgear.chat(TargetWeb, "เริ่ม");
    send_json("การสุ่ม รางวัลที่ 10 \r\n จะเริ่มแล้วนะ");
    setStatRadom10 = 1;
    delay(startwaittimer);
            }
       break;
            case 10:
            {
            microgear.chat(TargetWeb, "OFF");
            String rule = " ";
            rule += "***** กติกาการเล่น *****\r\n";
            rule += "ใส่ข้อความ\r\n";
            rule += "ใส่ข้อความ\r\n";
            rule += "ใส่ข้อความ";
             send_json(rule); 
            } 
       break;
            case 11:
            {
            microgear.chat(TargetWeb, "OFF");
    if(setStatRadom1 == 1|| setStatRadom2 == 1|| setStatRadom3 == 1|| setStatRadom4 == 1 ||setStatRadom5 == 1  ||setStatRadom6 == 1  ||setStatRadom7 == 1 ||setStatRadom8 == 1  ||setStatRadom9 == 1  || setStatRadom10 == 1){
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
    if(setStatRadom6 == 1)
      setStatRadom6 = 2;
    if(setStatRadom7 == 1)
      setStatRadom7 = 2;
    if(setStatRadom8 == 1)
      setStatRadom8 = 2;
    if(setStatRadom9 == 1)
      setStatRadom9 = 2;
    if(setStatRadom10 == 1)
      setStatRadom10 = 2;
      }else {
        send_json("ข้อผิดพลาด !\r\nยังไม่มีการเริ่มหรือคุณอาจส่งคำสั่งการรอมากไป");
      }
            }
       break;
            case 12:
            {
            microgear.chat(TargetWeb, "OFF");
    String other = " ";
        other += "***** อื่นๆ1ใส่ข้อความ *****\r\n";
        other += "ใส่ข้อความ\r\n";
        other += "ใส่ข้อความ\r\n";
        other += "ใส่ข้อความ";
    
    send_json(other);
            }
       break;
            case 13:
            {
             microgear.chat(TargetWeb, "OFF");
    String other = " ";
        other += "***** อื่นๆ2ใส่ข้อความ *****\r\n";
        other += "ใส่ข้อความ\r\n";
        other += "ใส่ข้อความ\r\n";
        other += "ใส่ข้อความ";
    
    send_json(other);
            }
       break;
            case 14:
            {
            microgear.chat(TargetWeb, "OFF");
    String other = " ";
        other += "***** อื่นๆ3ใส่ข้อความ *****\r\n";
        other += "ใส่ข้อความ\r\n";
        other += "ใส่ข้อความ\r\n";
        other += "ใส่ข้อความ";
    
    send_json(other);
            }
       break;
            case 15:
            {
             microgear.chat(TargetWeb, "OFF");
    send_json("หยุดแล้ว");
    setStatRadom1 = 0;
    setStatRadom2 = 0;
    setStatRadom3 = 0;
    setStatRadom4 = 0;
    setStatRadom5 = 0;
    setStatRadom6 = 0;
    setStatRadom7 = 0;
    setStatRadom8 = 0;
    setStatRadom9 = 0;
    setStatRadom10 = 0;
       break;
            }
     default:
            ;
}
}
   
    
     unsigned long currentMillis = millis();  
if (currentMillis - previousMillis >= interval) {

    previousMillis = currentMillis;

     if(setStatRadom1 == 1){
      
      String msgsent;
      int pos = random(12);
      int numRandom = random(00,99);
      msgsent = String(numRandom);
      if(numRandom < 10){
        msgsent = "0"+msgsent;
        }
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
      
     String msgsent;
      int pos = random(12);
      int numRandom = random(00,99);
      msgsent = String(numRandom);
      if(numRandom < 10){
        msgsent = "0"+msgsent;
        }
      String texFormate = " ";
        texFormate += "ผลที่ส่งทางไลน์\r\n";
        texFormate += "รางวัลประจำเดือนมิถุนายน 61\r\n";
        texFormate += "รางวัลที่ 2\r\n";
        texFormate += "เลขที่ออก ";
        texFormate += msgsent;

      send_json(texFormate);
      }

      if(setStatRadom3 == 1){
      
    String msgsent;
      int pos = random(12);
      int numRandom = random(00,99);
      msgsent = String(numRandom);
      if(numRandom < 10){
        msgsent = "0"+msgsent;
        }
      String texFormate = " ";
        texFormate += "ผลที่ส่งทางไลน์\r\n";
        texFormate += "รางวัลประจำเดือนมิถุนายน 61\r\n";
        texFormate += "รางวัลที่ 3\r\n";
        texFormate += "เลขที่ออก ";
        texFormate += msgsent;

      send_json(texFormate);
      }

      if(setStatRadom4 == 1){
      
     String msgsent;
      int pos = random(12);
      int numRandom = random(00,99);
      msgsent = String(numRandom);
      if(numRandom < 10){
        msgsent = "0"+msgsent;
        }
      String texFormate = " ";
        texFormate += "ผลที่ส่งทางไลน์\r\n";
        texFormate += "รางวัลประจำเดือนมิถุนายน 61\r\n";
        texFormate += "รางวัลที่ 4\r\n";
        texFormate += "เลขที่ออก ";
        texFormate += msgsent;

      send_json(texFormate);
      }

      if(setStatRadom5 == 1){
     String msgsent;
      int pos = random(12);
      int numRandom = random(00,99);
      msgsent = String(numRandom);
      if(numRandom < 10){
        msgsent = "0"+msgsent;
        }
      String texFormate = " ";
        texFormate += "ผลที่ส่งทางไลน์\r\n";
        texFormate += "รางวัลประจำเดือนมิถุนายน 61\r\n";
        texFormate += "รางวัลที่ 5\r\n";
        texFormate += "เลขที่ออก ";
        texFormate += msgsent;

      send_json(texFormate);
      }

      if(setStatRadom6 == 1){
     String msgsent;
      int pos = random(12);
      int numRandom = random(00,99);
      msgsent = String(numRandom);
      if(numRandom < 10){
        msgsent = "0"+msgsent;
        }
      String texFormate = " ";
        texFormate += "ผลที่ส่งทางไลน์\r\n";
        texFormate += "รางวัลประจำเดือนมิถุนายน 61\r\n";
        texFormate += "รางวัลที่ 6\r\n";
        texFormate += "เลขที่ออก ";
        texFormate += msgsent;

      send_json(texFormate);
      }

      if(setStatRadom7 == 1){
     String msgsent;
      int pos = random(12);
      int numRandom = random(00,99);
      msgsent = String(numRandom);
      if(numRandom < 10){
        msgsent = "0"+msgsent;
        }
      String texFormate = " ";
        texFormate += "ผลที่ส่งทางไลน์\r\n";
        texFormate += "รางวัลประจำเดือนมิถุนายน 61\r\n";
        texFormate += "รางวัลที่ 7\r\n";
        texFormate += "เลขที่ออก ";
        texFormate += msgsent;

      send_json(texFormate);
      }

      if(setStatRadom8 == 1){
     String msgsent;
      int pos = random(12);
      int numRandom = random(00,99);
      msgsent = String(numRandom);
      if(numRandom < 10){
        msgsent = "0"+msgsent;
        }
      String texFormate = " ";
        texFormate += "ผลที่ส่งทางไลน์\r\n";
        texFormate += "รางวัลประจำเดือนมิถุนายน 61\r\n";
        texFormate += "รางวัลที่ 8\r\n";
        texFormate += "เลขที่ออก ";
        texFormate += msgsent;

      send_json(texFormate);
      }

      if(setStatRadom9 == 1){
     String msgsent;
      int pos = random(12);
      int numRandom = random(00,99);
      msgsent = String(numRandom);
      if(numRandom < 10){
        msgsent = "0"+msgsent;
        }
      String texFormate = " ";
        texFormate += "ผลที่ส่งทางไลน์\r\n";
        texFormate += "รางวัลประจำเดือนมิถุนายน 61\r\n";
        texFormate += "รางวัลที่ 9\r\n";
        texFormate += "เลขที่ออก ";
        texFormate += msgsent;

      send_json(texFormate);
      }

      if(setStatRadom10 == 1){
     String msgsent;
      int pos = random(12);
      int numRandom = random(00,99);
      msgsent = String(numRandom);
      if(numRandom < 10){
        msgsent = "0"+msgsent;
        }
      String texFormate = " ";
        texFormate += "ผลที่ส่งทางไลน์\r\n";
        texFormate += "รางวัลประจำเดือนมิถุนายน 61\r\n";
        texFormate += "รางวัลที่ 10\r\n";
        texFormate += "เลขที่ออก ";
        texFormate += msgsent;

      send_json(texFormate);
      }

      
  }
   

 //   
}
