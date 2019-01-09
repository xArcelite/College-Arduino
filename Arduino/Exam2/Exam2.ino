//A. Add the following two signals together: 
//1. The output of the middle pin of a rotary potentiometer
//(with the other two pins connected to ground and 5V)
//2. The waveform 0.5 sin(4𝜋𝑡) + 0.5 [volts] 
//B. Turn on a red LED if the sum of the signals is ≥ 4.5V 
//C. Turn on a green LED if the sum of the signals is ≤ 0.5V
//https://www.arduino.cc/reference/en/language/functions/digital-io/pinmode/
//https://programmingelectronics.com/make-one-button-functionality-two-arduino/
//http://forum.arduino.cc/index.php?topic=183046.0
unsigned long t;
float v;
float val;
float v_in;
void setup() 
{
pinMode(7,OUTPUT);
pinMode(9,OUTPUT);
Serial.begin(9600);
}
void loop() 
{
  t = millis();
  Serial.print(t);
  Serial.print(",");
  v_in = (float)analogRead(0)/1024*5;
  v = 0.5 + sin(12.56*(x/1000.0));
    voltageLevel = v_in + v;
{
       if (voltageLevel >= 4.5) 
{
         digitalWrite(7, HIGH);
         delay(1000)
         digitalWrite(7, LOW);
         delay(1000)
}
        if {voltageLevel <= 0.5}
{
         digitalWrite(9, HIGH);
         delay(1000)
         digitalWrite(9, LOW);
         delay(1000)
}
}
delay(1000);
}
