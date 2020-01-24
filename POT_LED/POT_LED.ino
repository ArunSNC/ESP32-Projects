#define POT A0
static int val,writeval;
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(POT,INPUT);
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
val = analogRead(POT);
writeval = val *(255 / 1023);
analogWrite(LED_BUILTIN,val);
}
