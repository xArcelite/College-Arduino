void setup()
{DDRA = 0b11111111;//8 pins.
 Serial.begin(9600);}
void loop()
{if (Serial.available() > 0)
{int num = Serial.readStringUntil('\n').toInt();
if (num > 255 || num < 0) {
Serial.println("Please enter another number between 0 and 255"); }
else
{PORTA = num;}}}
