#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(50); 
  
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(11); 

  servo1.writeMicroseconds(1500);
  servo2.writeMicroseconds(1500);
  servo3.writeMicroseconds(1500);
  servo4.writeMicroseconds(1500);
}

void loop() {
  if (Serial.available() > 0) {
    char c = Serial.read();
    
    // Ignore the LED character and wait for the bracket
    if (c == '<') {
      int s1 = Serial.parseInt();
      int s2 = Serial.parseInt();
      int s3 = Serial.parseInt();
      int s4 = Serial.parseInt();

      servo1.writeMicroseconds(s1);
      servo2.writeMicroseconds(s2);
      servo3.writeMicroseconds(s3);
      servo4.writeMicroseconds(s4);
    }
  }
}
