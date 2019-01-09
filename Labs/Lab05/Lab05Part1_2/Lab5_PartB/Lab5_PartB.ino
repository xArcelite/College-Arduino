unsigned long x;
float v=0;
float v1=0;
float v2=0;
float f=0;
void setup() //repeat of before parts...
{DDRB |= (1<<5);
 ADMUX = 0b01000000;
 ADCSRA = 0b10000111;
 cli();
 OCR1A = 0;
 TCCR1A = 0b10101001;
 TCCR1B = 0b00001001;
 sei();
 Serial.begin(9600);}
void loop() //again, repeat of past parts...
{ ADMUX &= ~(1<<MUX0);
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
  Serial.println(v1);
  Serial.print(',');
  Serial.println(v2);
  delay(80); //Data optimization.
  x=millis();
  f=2.5 + 2.5*sin((3.1415)/1000.0*x);
  OCR1A = (int)(f*255)/5;}'
//When Potentiometer's Resistance is at max, the limiter diode regulates the output voltage.
//Which results in a constant 5V coming from the elctronic source.
//This is caused by the reverse bias diode closing, which creats an open circuit.
//This also results in the input sine wave to become the output voltage.
//Because of this, when an electronic source is little, the output becomes cut/closed due to the limited circuit's design.
