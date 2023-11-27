#include <Servo.h>
#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"

#define FPSerial Serial1

Servo myservo = Servo();

DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

const int servo1 = 4;
const int servo2 = 5;
const int servo3 = 6;
const int servo4 = 7;
const int servo5 = 15;
const int servo6 = 16;

void setup() {
  FPSerial.begin(9600, SERIAL_8N1, /*rx =*/48, /*tx =*/46);
  Serial.begin(115200);

  Serial.println(F("Hello! I am BrailleBot."));

  if (!myDFPlayer.begin(FPSerial, /*isACK = */true, /*doReset = */true)) {
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
  }
  Serial.println(F("Lets Start Learning."));
  
  myDFPlayer.volume(30);
  myDFPlayer.play(27);
  delay(5000); 
}

void loop() {
  a();
}

void zero(){
  myservo.write(servo6, 0);
}

void clear(){
    myservo.write(servo1, 0);
    myservo.write(servo2, 0); 
    myservo.write(servo3, 0); 
    myservo.write(servo4, 0); 
    myservo.write(servo5, 0); 
    myservo.write(servo6, 0);
}

void a(){
  for (int pos = 0; pos <= 10; pos++) {
    myservo.write(servo1, pos);  
    delay(10);
  }
  Serial.println(F("A"));
  myDFPlayer.play(2);
  delay(5000);
  for (int pos = 10; pos >= 0; pos--) {
    myservo.write(servo1, pos);        
    delay(10);
  }
  delay(1000);
}

void b(){
  for (int pos = 0; pos <= 17; pos++) {
    myservo.write(servo3, pos);  
    delay(10);
  }
  Serial.println(F("A"));
  myDFPlayer.play(3);
  delay(5000);
  for (int pos = 17; pos >= 0; pos--) {
    myservo.write(servo3, pos);        
    delay(10);
  }
  delay(1000);
}

void c(){
  for (int pos = 0; pos <= 17; pos++) {
    myservo.write(servo2, pos);  
    delay(10);
  }
  Serial.println(F("A"));
  myDFPlayer.play(4);
  delay(5000);
  for (int pos = 17; pos >= 0; pos--) {
    myservo.write(servo2, pos);        
    delay(10);
  }
  delay(1000);
}

void d(){
  for (int pos = 0; pos <= 10; pos++) {
    myservo.write(servo1, pos);    
    myservo.write(servo2, pos);   
    myservo.write(servo4, pos);   
    delay(10);
  }
}

void e(){
  for (int pos = 0; pos <= 10; pos++) {
    myservo.write(servo1, pos);   
    myservo.write(servo4, pos);   
    delay(10);
  }
}

void f(){
  for (int pos = 0; pos <= 10; pos++) {
    myservo.write(servo1, pos);    
    myservo.write(servo2, pos);   
    myservo.write(servo3, pos);   
    delay(10);
  }
}

void g(){
  for (int pos = 0; pos <= 10; pos++) {
    myservo.write(servo1, pos);    
    myservo.write(servo2, pos);   
    myservo.write(servo3, pos);   
    myservo.write(servo4, pos); 
    delay(10);
  }
}

void h(){
  for (int pos = 0; pos <= 10; pos++) {
    myservo.write(servo1, pos);    
    myservo.write(servo3, pos);   
    myservo.write(servo4, pos); 
    delay(10);
  }
}

void i(){
  for (int pos = 0; pos <= 10; pos++) {   
    myservo.write(servo2, pos);   
    myservo.write(servo3, pos);  
    delay(10);
  }
}

void j(){
  for (int pos = 0; pos <= 10; pos++) {  
    myservo.write(servo2, pos);   
    myservo.write(servo3, pos);   
    myservo.write(servo4, pos); 
    delay(10);
  }
}

void k(){
  for (int pos = 0; pos <= 10; pos++) {
    myservo.write(servo1, pos);    
    myservo.write(servo5, pos);  
    delay(10);
  }
}

void l(){
  for (int pos = 0; pos <= 10; pos++) {
    myservo.write(servo1, pos);   
    myservo.write(servo3, pos);   
    myservo.write(servo5, pos); 
    delay(10);
  }
}

void m(){
  for (int pos = 0; pos <= 10; pos++) {
    myservo.write(servo1, pos);    
    myservo.write(servo2, pos);   
    myservo.write(servo5, pos);   
    delay(10);
  }
}

void n(){
  for (int pos = 0; pos <= 10; pos++) {
    myservo.write(servo1, pos);    
    myservo.write(servo2, pos);   
    myservo.write(servo4, pos);   
    myservo.write(servo5, pos); 
    delay(10);
  }
}

void o(){
  for (int pos = 0; pos <= 10; pos++) {
    myservo.write(servo1, pos);    
    myservo.write(servo4, pos);   
    myservo.write(servo5, pos);   
    delay(10);
  }
}

void p(){
  for (int pos = 0; pos <= 10; pos++) {
    myservo.write(servo1, pos);    
    myservo.write(servo2, pos);   
    myservo.write(servo3, pos);   
    myservo.write(servo5, pos); 
    delay(10);
  }
}

void q(){
  for (int pos = 0; pos <= 10; pos++) {
    myservo.write(servo1, pos);    
    myservo.write(servo2, pos);   
    myservo.write(servo3, pos);   
    myservo.write(servo4, pos);
    myservo.write(servo5, pos); 
    delay(10);
  }
}

void r(){
  for (int pos = 0; pos <= 10; pos++) {
    myservo.write(servo1, pos);    
    myservo.write(servo3, pos);   
    myservo.write(servo4, pos);   
    myservo.write(servo5, pos);
    delay(10);
  }
}

void s(){
  for (int pos = 0; pos <= 10; pos++) {
    myservo.write(servo2, pos);    
    myservo.write(servo3, pos);   
    myservo.write(servo5, pos);   
    delay(10);
  }
}

void t(){
  for (int pos = 0; pos <= 10; pos++) {
    myservo.write(servo2, pos);    
    myservo.write(servo3, pos);   
    myservo.write(servo4, pos);  
    myservo.write(servo5, pos); 
    delay(10);
  }
}

void u(){
  for (int pos = 0; pos <= 10; pos++) {
    myservo.write(servo1, pos);    
    myservo.write(servo5, pos);   
    myservo.write(servo6, pos);   
    delay(10);
  }
}

void v(){
  for (int pos = 0; pos <= 10; pos++) {
    myservo.write(servo1, pos);    
    myservo.write(servo3, pos);   
    myservo.write(servo5, pos);   
    myservo.write(servo6, pos);
    delay(10);
  }
}

void w(){
  for (int pos = 0; pos <= 10; pos++) {
    myservo.write(servo2, pos);    
    myservo.write(servo3, pos);   
    myservo.write(servo4, pos);   
    myservo.write(servo6, pos);
    delay(10);
  }
}

void x(){
  for (int pos = 0; pos <= 10; pos++) {
    myservo.write(servo1, pos);    
    myservo.write(servo2, pos);   
    myservo.write(servo5, pos);   
    myservo.write(servo6, pos);
    delay(10);
  }
}

void y(){
  for (int pos = 0; pos <= 10; pos++) {
    myservo.write(servo1, pos);    
    myservo.write(servo2, pos);   
    myservo.write(servo4, pos);   
    myservo.write(servo5, pos);
    myservo.write(servo6, pos); 
    delay(10);
  }
}

void z(){
  for (int pos = 0; pos <= 10; pos++) {
    myservo.write(servo1, pos);    
    myservo.write(servo4, pos);   
    myservo.write(servo5, pos);   
    myservo.write(servo6, pos);
    delay(10);
  }
}