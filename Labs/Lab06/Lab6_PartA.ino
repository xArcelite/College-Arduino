unsigned long x;
float v=0;
float v1=0;
void setup() //Almost the same.
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
{ ADMUX &= ~(1<<MUX0);
  ADMUX &= ~(1<<MUX1);
  ADCSRA |= (1<<ADSC);
  while(ADCSRA & (1<<ADSC)){}
  v = (float)ADC/1024*5;
   
  if
  (PINA & (1<<PINA0))  //PinA clears the values (Input/A0 = low value (0))
    {v1 = 0;}//v1 = 0
    else
    {v1 = 2.5;}//v1 = 2.5 if not (A0 = high value)
  Serial.print(x);
  Serial.print(',');
  Serial.print(v);
  Serial.print(',');
  Serial.println(v1);
  delay(20); //Delay 20 milisec for accuracy.
  x = millis();
}
