float val = 0;
void setup()
{
 ADMUX = 0b01000000; // set AVCC reference
 ADCSRA = 0b10000111; // enable ADC, set prescaler = 128
 Serial.begin(9600); // initialize serial to 9600 baud
}
void loop()
{
  ADCSRA |= (1<<ADSC);
  while(ADCSRA & (1<<ADSC)){}
 val = (float)ADC/1024*5; // read the pin
 Serial.println(val);
 delay(1000); // wait for a second
}
