//Jung Min Bae
//Mechatronics Lab: Lab 2 (embedding systems)

void setup() 
{DDRA = 0b11111111;} //Makes all pins of port A as input pins
void loop() 
{PORTA = 0b11111111;
delay(500);
PORTA = 0b01010100; //Port A data pins... I think it's 42, 44, 46 and 48?
delay(500);
PORTA = 0b10001001; //Port A data pins (again with adifferent array)
delay(500);}
