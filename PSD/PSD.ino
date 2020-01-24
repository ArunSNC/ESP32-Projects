#define BUF     10
char ch[BUF] ;
static int i = 0;
int count = 1;
char opt = 0;
void setup() 
{
   Serial.begin(9600);
   Serial.print("1. SHADOW\n2. HIDE\n");

   delay(2000);
   Serial.print("Enter the password:\n");
}

void loop() 
{
	while(Serial.available())
	{
		opt = Serial.read();
		Serial.flush();
   Serial.println(opt);
   while(Serial.available())
   {
   //   Serial.flush();
			if(opt == 49)
			{
        Serial.println("1");
     		if(( ch[i] = Serial.read()) != '\n' && (ch[i] >= 33 && ch[i] <= 126))
					++i;
				else
				{
					Serial.println(ch);
					memset(ch , '\0' , BUF);
					i=0;
				}
			}
     
			else if(opt == 50)
			{
        Serial.println("2");
				if((ch [i] = Serial.read())!= '\n' && (ch[i] >= 33 && ch[i] <= 126) )
				{
					Serial.print('*');
					++i;
				}
				else
				{
					Serial.print("\n");
					Serial.print("Your password is : " );
					Serial.println(ch);
					memset(ch , '\0' ,BUF);
					i=0;
				}

			}
		}
	}
}
