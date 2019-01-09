//Again, Frequency/Scalar = new Frequency (16MHz/1024)
//Count Value (7813) = New Freq (15625Hz) * new Period (0.5)
void setup()
{DDRA = 0b00000001;
 cli();//Interruption Disabler
 TCCR1A = 0;
 TCCR1B = 0b00001101;
 TIMSK1 = 0b0000010;
 OCR1A = 1111010000101;
 sei();} //Iterruption Enabler
ISR(TIMER1_COMPA_vect)
{ PORTA = PORTA^=(1<<DDA0);} //Toggling the Register
void loop(){}
