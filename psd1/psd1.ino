#define BUF     10
char ch[BUF] ;
static int i = 0;
int count = 1;
void setup() 
{
   Serial.begin(9600);
   //Serial.print("Enter the password:\n");
}

void loop() 
{
  while(Serial.available())
  {
    
     if(( ch[i] = Serial.read()) != '\n')
    ++i;
    else
    {
        Serial.println(ch);
        memset(ch , '\0' , BUF);
        i=0;
    }
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
