volatile unsigned long x;
volatile int f = 0;
void setup()
{cli();
 Serial.begin(9600);
 DDRA = 0b00000001;
 TCCR1A = 0;
 TCCR1B = 0b00000010;
 EICRA = 0b00000110;
 TIMSK1 = 0b00000001; 
 EIMSK = 0b00000011;
 sei();}
ISR(INT0_vect)
{if(PINA & (1<<PINA0)){//0 if PinA clears values)
    f = f-1;//position subtracted by 1}
    else{f = f+1;//position added 1}}
ISR(TIMER1_OVF_vect)
{x = millis();
 Serial.print(x); //Time on (ms)
 Serial.print(","); //Commma delimiter
 Serial.println(f); //Encoder Position}
void loop(){}
