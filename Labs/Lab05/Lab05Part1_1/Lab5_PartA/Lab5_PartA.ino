unsigned long x;
float v=0;
float v1=0;
float v2=0;
void setup()
{DDRB |= (1<<5);
 ADMUX = 0b01000000;//AVCC reference.
 ADCSRA = 0b10000111;
 cli();
 OCR1A = 0;
 TCCR1A = 0b10101001;
 TCCR1B = 0b00001001;
 sei();
 Serial.begin(9600);} //Serial to 9600 conversion.
void loop() //Reading the pins for each v value...
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
  Serial.print(v); //Voltage_input
  Serial.print(',');
  Serial.println(v1);//v1 = eo
  delay(12); //Delay for data optimization
  x = millis();}
//The op-amp should keep input voltage to around 5V with the code.
//Voltage drop across both diode and resistor is 3.43V (input-output)
//Forward Diode Voltage = 0.59V, which is less then the calculated value (1.1V)
//This is mostly attributed to manufacturer failure or uncertain factors.
//Current does NOT equal to 1 ampere.
