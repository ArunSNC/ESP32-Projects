#define CHANNEL0        A0  
#define NO_OF_SAMPLE    1000   

//#include "BluetoothSerial.h" 

//BluetoothSerial ESP_BT; 

void setup() {
  Serial.begin(9600); 
 // ESP_BT.begin("ESP32"); 
  Serial.println("Bluetooth Device is Ready to Pair");

  pinMode (LED_BUILTIN, OUTPUT);
}

void loop() {

   static float adc_val1, prev_val1,adc_val2,prev_val2;
  int samples;

  samples = 0;
  while (samples < NO_OF_SAMPLE )
  {
    adc_val1 = adc_val1 + analogRead(CHANNEL0);
        samples++;
  }
   adc_val1 = adc_val1 / samples;

 
   
  if (ESP_BT.available()) 
  {
  
  if ((prev_val1 != adc_val1) )//&& (prev_val2 != adc_val2))
  {
    ESP_BT.print("CHANNEL1 ADC value is: ");
    adc_val1 = (adc_val1) * 5.0 /1023.0;
    ESP_BT.print(adc_val1);
    ESP_BT.println(" volts");

    prev_val1 = adc_val1;
    
  }
    
  }
  delay(20);
}
