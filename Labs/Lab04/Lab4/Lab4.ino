unsigned long t;
float val=0;
float val1=0;
float val2=0;
float v;
void setup()
{
 DDRB |= (1<<5);
 ADMUX = 0b01000000; // set AVCC reference
 ADCSRA = 0b10000111; // 
 cli();
 OCR1A = 0;
 TCCR1A = 0b10101001;
 TCCR1B = 0b00001001;
 sei();
 Serial.begin(9600); // initialize serial to 9600 baud
}
void loop()
{
  ADMUX &= ~(1<<MUX0);
  ADMUX &= ~(1<<MUX1);
  ADCSRA |= (1<<ADSC);
  while(ADCSRA & (1<<ADSC)){}
  val = (float)ADC/1024*5; // read the pin

  ADMUX |= (1<<MUX0);
  ADMUX &= ~(1<<MUX1);
  ADCSRA |= (1<<ADSC);
  while(ADCSRA & (1<<ADSC)){}
  val1 = (float)ADC/1024*5; // read the pin

  ADMUX &= ~(1<<MUX0);
  ADMUX |= (1<<MUX1);
  ADCSRA |= (1<<ADSC);
  while(ADCSRA & (1<<ADSC)){}
  val2 = (float)ADC/1024*5; // read the pin
  
  Serial.print(t);
  Serial.print(',');
  Serial.print(val);
  Serial.print(',');
  Serial.print(val1);
  Serial.print(',');
  Serial.println(val2);
  delay(100); // wait for a second

  t = millis();
  
  v = 2.5 + 0.5*sin(3.1415/500.0*t);

  OCR1A = (int)(v*255)/5;
  
}


