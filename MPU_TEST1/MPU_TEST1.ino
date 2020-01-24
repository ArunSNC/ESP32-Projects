
#include <Wire.h>

const int MPU = 0x68; 
void setup() {
  Serial.begin(19200);
  Wire.begin();                     
  Wire.beginTransmission(MPU);      
  Wire.write(0x6B);                  
  Wire.write(0x00);    
  Wire.endTransmission(true);  
      
  delay(20);

}

void loop() 
{
  Wire.beginTransmission(MPU);
  Wire.write(0x19);
  Wire.endTransmission();
  Wire.requestFrom(MPU,1);
  unsigned char data = Wire.read();
  float sample_rate = 8.0 + ( 1  / data );
  Serial.print("sample_rate = ");
  Serial.println(sample_rate);
}
