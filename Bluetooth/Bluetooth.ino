

#include "BluetoothSerial.h" 

BluetoothSerial ESP_BT; 

int incoming;
//int LED_BUILTIN = 2;

void setup() {
  Serial.begin(9600); 
  ESP_BT.begin("ESP32_LED_Control"); 
  Serial.println("Bluetooth Device is Ready to Pair");

  pinMode (LED_BUILTIN, OUTPUT);
}

void loop() {
  
  if (ESP_BT.available()) 
  {
    incoming = ESP_BT.read(); 
    Serial.print("Received:"); Serial.println(incoming);

    if (incoming == 49)
        {
        digitalWrite(LED_BUILTIN, HIGH);
        ESP_BT.println("LED turned ON");
        }
        
    if (incoming == 48)
        {
        digitalWrite(LED_BUILTIN, LOW);
        ESP_BT.println("LED turned OFF");
        }     
  }
  delay(20);
}
