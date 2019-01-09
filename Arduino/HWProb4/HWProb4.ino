int v = 0;
void setup() {
 DDRA = 0b00000001;
 ADMUX = (1<<REFS0);
 ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
 cli(); //No interruptions
 TCCR1A = 0;
 TCCR1B = 0;
 TCCR1B |= (1 << WGM12);
 TCCR1B |= (1 << CS12);
 TIMSK1 = (1 << OCIE1A);
 OCR1A = 0;
 sei();} //Interruptions enabler
ISR(TIMER1_COMPA_vect){ PORTA ^=(1<<PORTA0);}
void loop() 
{ADCSRA |= (1 << ADSC);
 while
 (ADCSRA & (1 << ADSC));
 v = ADC;
 OCR1A = val*128+128;}
