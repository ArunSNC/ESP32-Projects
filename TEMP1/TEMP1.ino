#include"BluetoothSerial.h"
#include "DHTesp.h"

#define DHTpin 15   

DHTesp dht;
BluetoothSerial BT;
float humidity,temperature;
void dht_11();
void setup()
{
  Serial.begin(115200);
  BT.begin("ESP32");
  Serial.println();
 
  dht.setup(DHTpin, DHTesp::DHT11); 
  
}

void loop()
{
  if(BT.available());
  {
  dht_11();
  BT.println("Status\t\tHumidity (%)\t\tCelsius(c)");
  BT.print(dht.getStatusString());
  BT.print("\t\t\t\t\t\t");
  BT.print(humidity);
  BT.print("\t\t\t\t\t\t\t\t\t\t");
  BT.println(temperature);
  }
}

void dht_11()
{
  delay(dht.getMinimumSamplingPeriod());

  humidity = dht.getHumidity();
  temperature = dht.getTemperature();
}
