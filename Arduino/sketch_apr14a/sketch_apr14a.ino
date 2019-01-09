unsigned long t;
float f;
float v;
float v_in;
void setup() {pinMode(8,OUTPUT);Serial.begin(9600);}
void loop() {x = millis();
 Serial.print(x);
 Serial.print(",");
 v_in = (float)analogRead(0)/1024*5; f = 1.98*v_in + 0.1; // 0-5 volt -> 0.1-10 Hz 
 v = 2.5 + sin(f*6.28*(t/1000.0));
 if (digitalRead(8))
 { if (v > 2.5) { v = 3.5; } else { v = 1.5; } }
 Serial.println(v);
 delay(30); }
