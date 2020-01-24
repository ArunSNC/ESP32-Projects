// https://github.com/espressif/arduino-esp32/blob/af35773d65a8f328dba8090dff66ba43abe0e7be/cores/esp32/esp32-hal-timer.c#L216-L265
#define BUTTON           0
#define EDGE            true
#define UP_TICK         true
#define AUTO_RELOAD     true

static int sec;
 
hw_timer_t * timer1 = NULL; 
 
void IRAM_ATTR tmr_isr1()
{ 
  sec++;
}

void IRAM_ATTR isr()
{ 
  sec = 0;
}

void setup() 
{
 
  Serial.begin(115200);
  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(BUTTON,INPUT);
  timer1 = timerBegin(0, 40, UP_TICK);
  timerAttachInterrupt(timer1, tmr_isr1, EDGE);
  timerAlarmWrite(timer1, 2000000, AUTO_RELOAD);
  timerAlarmEnable(timer1);
  attachInterrupt(digitalPinToInterrupt(BUTTON),isr,FALLING);
}
 
void loop() 
{
  if(sec < 3)
    digitalWrite(LED_BUILTIN,HIGH);
  else if(sec > 2 && sec < 5)
  {
    for(int i = 7500 ; i--;)
    digitalWrite(LED_BUILTIN,LOW);
    for(int j = 2500; j--;)
    digitalWrite(LED_BUILTIN,HIGH);
  }
  else
  digitalWrite(LED_BUILTIN,LOW);
}
