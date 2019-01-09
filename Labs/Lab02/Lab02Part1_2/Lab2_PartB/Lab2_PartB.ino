//Converting letters to pins
//a = 27
//b = 25
//c = 22
//d = 23
//e = 24
//f = 28
//g = 26
void setup() 
{Serial.begin(9600); 
DDRA = 0b11111111;}

void loop() //This is to determine different arrays for different pins. When a "case" gets triggered, the array on the case is returns from 0-9.
{if (Serial.available() > 0)
  {int n = Serial.readStringUntil('\n').toInt();
    switch (n)
    {case 0:
      {PORTA = 0b1101111;
        break;}
     case 1:
      {PORTA = 0b0001001;
        break;}
     case 2:
      {PORTA = 0b0111110;
        break;}
      case 3:
      {PORTA = 0b0111011;
        break;}
      case 4:
      {PORTA = 0b1011001;
        break;}
      case 5:
      {PORTA = 0b1110011;
        break;}
      case 6:
      {PORTA = 0b1110111;
        break;}
      case 7:
      {PORTA = 0b0101001;
        break;}
      case 8:
      {PORTA = 0b1111111;
        break;}
      case 9:
      {PORTA = 0b01111011;
        break;} } } }
