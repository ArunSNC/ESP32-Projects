#include"SPI.h"
#define button 0

int button_val,x,ss = 11;
void setup() 
{
  Serial.begin(115200);
  pinMode(button,INPUT);
  pinMode(LED_BUILTIN,OUTPUT);

  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  digitalWrite(ss,HIGH);

}

void loop() 
{
 byte master_send , master_receive;
 button_val = digitalRead(button);

  if(button_val == HIGH)
  x = 1;
  else
  x = 0;

  digitalWrite(ss,LOW);
  master_send = x ; 
  master_receive = SPI.transfer(master_send);

  if(master_receive == 1)
  {
    digitalWrite(LED_BUILTIN,HIGH);
    Serial.println("MASTER LED ON");
  }
  else
  {
   digitalWrite(LED_BUILTIN,LOW);
   Serial.println("MASTER LED OFF"); 
  }
  delay(1000);
}
