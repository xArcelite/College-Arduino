unsigned long x;
float v=0;
float v1=0;
float v2 = 0;
float v3 = 0;
void setup()
{ADMUX = 0b01000000;
 ADCSRA = 0b10000111;
 cli();
 OCR1A = 0;
 TCCR1A = 0b10101001;
 TCCR1B = 0b00001001;
 DDRA = 0b00000000;
 PORTA = 0b00000000;
 sei();
 Serial.begin(9600);}
void loop()
{ADMUX &= ~(1<<MUX0);
  ADMUX &= ~(1<<MUX1);
  ADCSRA |= (1<<ADSC);
  while(ADCSRA & (1<<ADSC)){}
  v = (float)ADC/1024*5;
  if(PINA & (1<<PINA0))
    {v1 = 0;}
    else{v1 = 3.75;} //high value
  if(PINA & (1<<PINA1))
    v2 = 0;}
    else{val2 = 1.25;}//low value
  if(PINA & (1<<PINA2))
    v3 = 0;}
    else{v3 = 2.5;}
  Serial.print(x);
  Serial.print(',');
  Serial.print(v);
  Serial.print(',');
  Serial.print(v1);
  Serial.print(',');
  Serial.print(v2);
  Serial.print(',');
  Serial.println(v3);
  delay(10); //10 miliseconds delay
  x = millis();
}
