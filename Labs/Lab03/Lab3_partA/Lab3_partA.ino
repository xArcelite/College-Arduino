//Frequency/Scalar = new Frequency (16MHz/1024)
//Inverse of new frequency = new period (4.194 seconds)
//Using the new 256 scale
//The new calculated period should be 1.049 seconds
void setup()
{DDRA = 0b00000001;
 cli(); //Interruption Disabler
 TCCR1A = 0;
 TCCR1B = 0b00000100;
 TIMSK1 = 0b0000001;
 sei();} //Iterruption Enabler
ISR(TIMER1_OVF_vect)
{PORTA = PORTA^=(1<<DDA0);} //Toggling the register
void loop(){}

