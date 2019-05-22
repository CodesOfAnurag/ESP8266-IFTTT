#include<ESP8266WiFi.h>
#include "Adafruit_MQTT_Client.h"


// Make changes to basic connection details
// Wifi details
#define wifi "SSID"
#define pass "Password"

// adafruit details
#define user "Adafruit Account"
#define key "Server Key"

#define port 1883
#define server "io.adafruit.com"

// pin_out for ldr
#define led 16

WiFiClient esp;
Adafruit_MQTT_Client mqtt(&esp, server, port, user, key);
Adafruit_MQTT_Subscribe feed =Adafruit_MQTT_Subscribe(&mqtt,user"/feeds/ldrprogram");

void setup() {
  pinMode(16,OUTPUT);
  Serial.begin(115200);
  delay(10);
  Serial.println("Adafruit Demo");
  Serial.print("Connecting to ");
  Serial.print(wifi);

  WiFi.begin(wifi,pass);
  
  while(WiFi.status()!= WL_CONNECTED)
  {
    delay(500);
    Serial.print(" . ");
  }
  
  Serial.println("Connected to WiFi");
  Serial.print(wifi);
  Serial.println("IP Address");
  Serial.print(WiFi.localIP());
  
  mqtt.subscribe(&feed);
  Serial.println("Connecting through MQTT");

  while(mqtt.connect())
  {
    Serial.print(" . ");
  }
  Serial.println("Connected");
 
}

void loop() {
  while(mqtt.readSubscription(3000))
  {
    Serial.print("Got : "); 
    //Serial.println((char*)feed.lastread);
    int a = atoi((char*)feed.lastread);
    
    Serial.print(a);
    while(feed.lastread == 1 || feed.lastread ==
    if (a==0)
      digitalWrite(16,LOW);
    else if (a==1)
      digitalWrite(16,HIGH);
    else
    {
      int i = 0;
      while(i<20)
      {
        i=i+1;
        digitalWrite(16,HIGH);
        delay(100);
        digitalWrite(16,LOW);
        delay(100);
        digitalWrite(16,HIGH);
      }
    }

    delay(2200);
  }
}
