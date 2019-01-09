unsigned long x;
float v=0;
float v1=0;
float v2=0;
float v3;
void setup()
{DDRA = 0b00000000;
 PORTA = 0b00000000;
 DDRB |= (1<<5);
 ADMUX = 0b01000000; // set AVCC reference
 ADCSRA = 0b10000111; // 
 cli();
 OCR1A = 0;
 TCCR1A = 0b10101001;
 TCCR1B = 0b00001001;
 sei();
 Serial.begin(9600); // initialize serial to 9600 baud}
 
void loop() {
  ADMUX &= ~(1<<MUX0);
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
  if(PINA & (1<<PINA0))
  {v3 = 1;}
  else{v3 = 0;}

  Serial.print(x);
  Serial.print(',');
  Serial.print(v);
  Serial.print(',');
  Serial.print(v1);
  Serial.print(',');
  Serial.print(v2);
  Serial.print(',');
  Serial.println(v3);
  delay(100); //Delay for 0.1 seconds.
  x = millis();
}
