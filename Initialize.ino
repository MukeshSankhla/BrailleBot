/*  makerbrains.com
    Mukesh Sankhla
    @mukesh.diy     */
    
#include <Servo.h>

Servo myservo = Servo();

const int servo1 = 4;
const int servo2 = 5;
const int servo3 = 6;
const int servo4 = 7;
const int servo5 = 15;
const int servo6 = 16;

void setup() {

  for (int pos = 180; pos >= 0; pos--) {  // go from 180-0 degrees
    myservo.write(servo1, pos);       
    delay(15);
  }
  for (int pos = 0; pos <= 180; pos++) {  // go from 180-0 degrees
    myservo.write(servo1, pos);        
    delay(15);
  }

  for (int pos = 0; pos <= 180; pos++) {  // go from 180-0 degrees
    myservo.write(servo2, pos);        
    delay(15);
  }
  for (int pos = 180; pos >= 0; pos--) {  // go from 180-0 degrees
    myservo.write(servo2, pos);       
    delay(15);
  }

  for (int pos = 180; pos >= 0; pos--) {  // go from 180-0 degrees
    myservo.write(servo3, pos);       
    delay(15);
  }
  for (int pos = 0; pos <= 180; pos++) {  // go from 180-0 degrees
    myservo.write(servo3, pos);        
    delay(15);
  }

  for (int pos = 0; pos <= 180; pos++) {  // go from 180-0 degrees
    myservo.write(servo4, pos);        
    delay(15);
  }
  for (int pos = 180; pos >= 0; pos--) {  // go from 180-0 degrees
    myservo.write(servo4, pos);       
    delay(15);
  }

  for (int pos = 180; pos >= 0; pos--) {  // go from 180-0 degrees
    myservo.write(servo5, pos);       
    delay(15);
  }
  for (int pos = 0; pos <= 180; pos++) {  // go from 180-0 degrees
    myservo.write(servo5, pos);        
    delay(15);
  }

  for (int pos = 0; pos <= 180; pos++) {  // go from 180-0 degrees
    myservo.write(servo6, pos);        
    delay(15);
  }
  for (int pos = 180; pos >= 0; pos--) {  // go from 180-0 degrees
    myservo.write(servo6, pos);       
    delay(15);
  }
}

void loop() {
}
