char ch;
void setup() {
	// put your setup code here, to run once:
	pinMode(LED_BUILTIN,OUTPUT);
	pinMode(6,OUTPUT);
	Serial.begin(9600);
	Serial.print("A : ON LED\nB : OFF LED\nC: ON BUZZER\n D: OFF BUZZER");

}

void loop() {
	ch = Serial.read();
	// put your main code here, to run repeatedly:
	if(ch == 'a' || ch == 'A')
		digitalWrite(LED_BUILTIN,HIGH);
	else if(ch == 'b' || ch == 'B')
		digitalWrite(LED_BUILTIN,LOW);
	else if(ch == 'c' || ch == 'C')
		digitalWrite(6,HIGH);
	else if(ch == 'd' || ch == 'D')
		digitalWrite(6,LOW);
}
