#include "SPI.h"
#define button 0

volatile boolean received;
volatile byte slave_send , slave_received;
int miso  = 7,button_val,x;
void setup()
{
 Serial.begin(115200);
 pinMode(button ,INPUT);
 pinMode(LED_BUILTIN , OUTPUT);

 pinMode(miso,OUTPUT);

 SPCR |= _BV(SPE);

 received = false;
 SPI.attachInterrupt();
}

ISR::ISR(SPI_STC_vect)
{
  slave_received  = SPDR;
  received = true;
}

void loop()
{
  if(received)
  {
    if(slave_received == 1)
    {
      digitalWrite(LED_BUILTIN,HIGH);
      Serial.println("SLAVE LED ON");
    }
    else
    {
      digitalWrite(LED_BUILTIN , LOW);
      Serial.println("SLAVE LED OFF");
    }
    
  button_val = digitalRead(button);

  if(button_val == 1)
  x = 1;
  else
  x = 0;

  slave_send  =  x;
  SPDR = slave_send;
  delay(1000);
  }
}
