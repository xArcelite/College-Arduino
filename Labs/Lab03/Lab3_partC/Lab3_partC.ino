//Positivity duty and Frequency differences
//50.6% (Measured) vs 50% (Theoretical)
//246Hz (Measured) vs 244.14Hz (Theoretical)
void setup()
{DDRB = 0b00000001;
 cli();//Interruption Disabler
 TCCR1A = 0b10000001;
 TCCR1B = 0b00001100;
 TIMSK1 = 0b00000010;
 OCR1A = 127; 
 pinMode(8, OUTPUT);
 sei();//Interruption Enabler}
void loop(){}
