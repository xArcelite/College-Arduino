unsigned long x;
float f;
float v_i;
float v;
void setup() {pinMode(7,OUTPUT);Serial.begin(9600);}
void loop() {x = millis();
 Serial.print(x);
 Serial.print(",");
 v = 2.5 + sin(f*6.28*(x/1000.0));
 v_i = (float)analogRead(0)/1024*5; 
 f = 1.98*v_i + 0.1; // 0-5 volt -> 0.1-10 Hz 
 if (digitalRead(7))
 { if (v > 2.5) { v = 3.5; } else { v = 1.5; } } //This is a sine wave from the button being pressed.
 Serial.println(v);
 delay(20); }
