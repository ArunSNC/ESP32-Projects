#include<Wire.h>
const int MPU6050_addr=0x68;

int minVal=265;
int maxVal=402;
int16_t AccX,AccY,AccZ,Temp,GyroX,GyroY,GyroZ;
double x,y,z;
void setup(){
  Wire.begin();
  Wire.beginTransmission(MPU6050_addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.begin(9600);
}
void loop(){
  Wire.beginTransmission(MPU6050_addr);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_addr,14,true);
  AccX=Wire.read()<<8|Wire.read();
  AccY=Wire.read()<<8|Wire.read();
  AccZ=Wire.read()<<8|Wire.read();
  int xAng = map(AccX,minVal,maxVal,-90,90);
  int yAng = map(AccY,minVal,maxVal,-90,90);
  int zAng = map(AccZ,minVal,maxVal,-90,90);
  x= RAD_TO_DEG * (atan2(-yAng, -zAng)+PI);
  y= RAD_TO_DEG * (atan2(-xAng, -zAng)+PI);
  z= RAD_TO_DEG * (atan2(-yAng, -xAng)+PI);
  Serial.print("Angle of inclination in X axis = ");
  Serial.print(x);
  Serial.println((char)176);
    Serial.print("Angle of inclination in Y axis= ");
     Serial.print(y);
     Serial.println((char)176);
     Serial.print("Angle of inclination in Z axis= ");
     Serial.print(z);
     Serial.println((char)176);
     Serial.println("-------------------------------------------");
     delay(1000);


/*  Temp=Wire.read()<<8|Wire.read();
  GyroX=Wire.read()<<8|Wire.read();
  GyroY=Wire.read()<<8|Wire.read();
  GyroZ=Wire.read()<<8|Wire.read();
  Serial.print("AccX = "); Serial.print(AccX);
  Serial.print(" || AccY = "); Serial.print(AccY);
  Serial.print(" || AccZ = "); Serial.print(AccZ);
  Serial.print(" || Temp = "); Serial.print(Temp/340.00+36.53);
  Serial.print(" || GyroX = "); Serial.print(GyroX);
  Serial.print(" || GyroY = "); Serial.print(GyroY);
  Serial.print(" || GyroZ = "); Serial.println(GyroZ);*/
  delay(100);
}
