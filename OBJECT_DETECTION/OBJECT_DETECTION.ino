#define OUT1   5
#define OUT2   6
static int val,val1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(OUT1,INPUT);
  pinMode(OUT2,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
val = digitalRead(OUT1);
Serial.print("OUT1 === ");
Serial.println(OUT1);

val1 = digitalRead(OUT2);
Serial.print("OUT2 === ");
Serial.println(OUT2);
}
