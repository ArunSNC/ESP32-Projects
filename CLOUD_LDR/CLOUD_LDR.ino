#include <WiFi.h>
String apiKey = "VID2EX3O2GKZZMBN";                  //  Enter your Write API key from ThingSpeak
const char *ssid =  "JioFi2_166FB1";                                    // replace with your wifi ssid and wpa2 key
const char *pass =  "6t7gp4cfii";
const char* server = "api.thingspeak.com";
WiFiClient client;
void setup() 
{
    Serial.begin(115200);
    delay(10);
    Serial.println("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, pass);
    while (WiFi.status() != WL_CONNECTED) 
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected");
 
}
void loop() 
{
  int val = analogRead(A0);
  float voltage = (val) * ( 3.3 / 4096.0);
 if (client.connect(server,80))                                 //   "184.106.153.149" or api.thingspeak.com
    {  
                            
    String postStr = apiKey;
    postStr +="&field1=";
    postStr += String(voltage);
    postStr += "\r\n\r\n";

    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(postStr.length());
    client.print("\n\n");
    client.print(postStr);

    Serial.print("voltage = ");
    Serial.println(voltage);
    Serial.println("%. Send to Thingspeak.");
}
    delay(1000);
    client.stop();
    Serial.println("Waiting...");
    delay(10000);
}
