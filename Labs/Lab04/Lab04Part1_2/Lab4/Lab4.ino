unsigned long x;
float v=0;
float v1=0;
float v2=0;
float f;
void setup()
{DDRB |= (1<<5);
 ADMUX = 0b01000000; //AVCC Reference.
 ADCSRA = 0b10000111;
 cli();
 OCR1A = 0;
 TCCR1A = 0b10101001;
 TCCR1B = 0b00001001;
 sei();
 Serial.begin(9600);} //Serial to 9600 band.
void loop()
{ADMUX &= ~(1<<MUX0);
ADMUX &= ~(1<<MUX1);
ADCSRA |= (1<<ADSC);
while(ADCSRA & (1<<ADSC)){}
v = (float)ADC/1024*5;
ADMUX |= (1<<MUX0);
ADMUX &= ~(1<<MUX1);
ADCSRA |= (1<<ADSC);
while(ADCSRA & (1<<ADSC)){}
v1 = (float)ADC/1024*5;
ADMUX &= ~(1<<MUX0);
ADMUX |= (1<<MUX1);
ADCSRA |= (1<<ADSC);
while(ADCSRA & (1<<ADSC)){}
v2 = (float)ADC/1024*5;

Serial.print(x);
Serial.print(',');
Serial.print(v);
Serial.print(',');
Serial.print(v1);
Serial.print(',');
Serial.println(v2);
delay(40); //For stability
x = millis();
f = 2.5 + 0.5*sin(3.1415/500.0*x);
OCR1A = (int)(f*255)/5;}


