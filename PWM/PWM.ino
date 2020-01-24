void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

 
void loop() 
{
  static int dc;
  volatile int i ,j;
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
 
  for(i = 10000 - dc ; i-- ; );
//  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
 for(j = dc ; j-- ; );
  if(digitalRead(0) == 48)
  {
    Serial.print("Hello\n");
   if(dc != 1000)
     dc ++ ;
  }
 delay(1000);                       // wait for a second
}
