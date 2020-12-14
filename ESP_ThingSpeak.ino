#include <ThingSpeak.h>
#include <ESP8266WiFi.h>

const char* ssid     = "";
const char* password = "";
const int ldrPin = A0; // Defining LDR PIN 
int input_val = 0;  // Varible to store Input values


WiFiClient  client;
long myChannelNumber = ;
const char myWriteAPIKey[] = "";

void setup() {
   Serial.begin(9600); 
   delay(100);
   pinMode(ldrPin, INPUT);
   
   Serial.println();
   Serial.println();
   Serial.print("Connecting to ");
   Serial.println(ssid);
  
   WiFi.begin(ssid, password);
  
   while (WiFi.status() != WL_CONNECTED) {
   delay(200);
   Serial.print("...");
   }
  
   Serial.println("");
   Serial.println("WiFi connected");  
   Serial.println("IP address: ");
   Serial.println(WiFi.localIP());
   ThingSpeak.begin(client);
  }


void loop() {  
   input_val = analogRead(ldrPin);      // Reading Input
   Serial.print(input_val);
   ThingSpeak.writeField(myChannelNumber, 1,input_val, myWriteAPIKey);
}
