
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int x = 0 ; 
  while(x <= 20)
  {
    Serial.print(x);
    Serial.print(',');
    Serial.println(x*x);
    x++;
  }
  while(1);

}
