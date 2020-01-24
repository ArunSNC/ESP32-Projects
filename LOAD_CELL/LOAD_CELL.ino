#define tx A0
#define rx A1

static int val;
void setup() 
{
  Serial.begin(9600);
  pinMode(tx,INPUT);
  pinMode(rx,INPUT);
}

void loop() 
{
  val  = analogRead(tx);
  Serial.println(val * (5 / 1023));
  
}
