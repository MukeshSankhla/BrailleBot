/*
   Project  :  BrailleBot
   Author   :  Mukesh Sankhla
   Website  :  makerbrains.com
*/

#include <Servo.h>
#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"

#define FPSerial Serial1

// The delay of 2sec for the action to complete
#define pause 2000

// Pin assignments for "Next" and "Previous" buttons
const int nextPin = 45;
const int previousPin = 8;

// Flags to detect button presses
volatile bool nextPressed = false;
volatile bool previousPressed = false;

int position = 0;  // Current Braille alphabet position

// Servo motor assignments for Braille dots
Servo myservo = Servo();
const int servo1 = 4;
const int servo2 = 5;
const int servo3 = 6;
const int servo4 = 7;
const int servo5 = 15;
const int servo6 = 16;

// Declaration of the DFPlayer instance
DFRobotDFPlayerMini myDFPlayer;

void setup() {
  pinMode(nextPin, INPUT_PULLUP);
  pinMode(previousPin, INPUT_PULLUP);

  // Set up serial communication
  FPSerial.begin(9600, SERIAL_8N1, /*rx =*/48, /*tx =*/46);
  Serial.begin(115200);

  // Display welcome message
  Serial.println(F("Hello! I am BrailleBot."));

  // Attach interrupts for button presses
  attachInterrupt(digitalPinToInterrupt(nextPin), nextISR, FALLING);
  attachInterrupt(digitalPinToInterrupt(previousPin), previousISR, FALLING);

  // Initialize the DFPlayer module
  if (!myDFPlayer.begin(FPSerial, /*isACK = */true, /*doReset = */true)) {
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1. Please recheck the connection!"));
    Serial.println(F("2. Please insert the SD card!"));
  }

  // Display start message
  Serial.println(F("Let's Start Learning."));

  // Clear Braille display and play introduction audio
  clear();
  delay(1000);
  myDFPlayer.volume(30);
  myDFPlayer.play(27);
  delay(4000);

  // Perform initial setup by moving Braille dots up and down
  for(int i = 0; i < 5; i++){
    up();
    clear();
  }
  play();  // Play the audio for the current Braille letter
}

// Main loop
void loop() {
  // Check if "Next" button is pressed
  if (nextPressed) {
    position++;
    clear();
    play();  // Play the audio for the new Braille letter
    nextPressed = false;  // Reset the flag
  }

  // Check if "Previous" button is pressed
  if (previousPressed) {
    position--;
    clear();
    play();  // Play the audio for the new Braille letter
    previousPressed = false;  // Reset the flag
  }
}

// Functions to move each Braille dot up and down
void dot1Up(){
  for (int pos = 180; pos >= 162; pos--) {
    myservo.write(servo1, pos);  
    delay(5);
  }
}
void dot1Down(){
  for (int pos = 162; pos <= 180; pos++) {
    myservo.write(servo1, pos);  
    delay(5);
  }
}

void dot2Up(){
  for (int pos = 0; pos <= 20; pos++) {
    myservo.write(servo2, pos);  
    delay(5);
  }
}
void dot2Down(){
  for (int pos = 20; pos >= 0; pos--) {
    myservo.write(servo2, pos);  
    delay(5);
  }
}

void dot3Up(){
  for (int pos = 180; pos >= 165; pos--) {
    myservo.write(servo3, pos);  
    delay(5);
  }
}
void dot3Down(){
  for (int pos = 165; pos <= 180; pos++) {
    myservo.write(servo3, pos);  
    delay(5);
  }
}

void dot4Up(){
  for (int pos = 0; pos <= 16; pos++) {
    myservo.write(servo4, pos);  
    delay(5);
  }
}
void dot4Down(){
  for (int pos = 16; pos >= 0; pos--) {
    myservo.write(servo4, pos);  
    delay(5);
  }
}

void dot5Up(){
  for (int pos = 180; pos >= 160; pos--) {
    myservo.write(servo5, pos);  
    delay(5);
  }
}
void dot5Down(){
  for (int pos = 160; pos <= 180; pos++) {
    myservo.write(servo5, pos);  
    delay(5);
  }
}

void dot6Up(){
  for (int pos = 0; pos <= 10; pos++) {
    myservo.write(servo6, pos);  
    delay(5);
  }
}
void dot6Down(){
  for (int pos = 10; pos >= 0; pos--) {
    myservo.write(servo6, pos);  
    delay(5);
  }
}


// Function to play audio and move Braille dots for each letter
void play(){  
    if(position == 0){
      position = 1;
    }
    if(position == 1){
      a();
    }
    if(position == 2){
      b();
    }
    if(position == 3){
      c();
    }
    if(position == 4){
      d();
    }
    if(position == 5){
      e();
    }
    if(position == 6){
      f();
    }
    if(position == 7){
      g();
    }
    if(position == 8){
      h();
    }
    if(position == 9){
      i();
    }
    if(position == 10){
      j();
    }
    if(position == 11){
      k();
    }
    if(position == 12){
      l();
    }
    if(position == 13){
      m();
    }
    if(position == 14){
      n();
    }
    if(position == 15){
      o();
    }
    if(position == 16){
      p();
    }
    if(position == 17){
      q();
    }
    if(position == 18){
      r();
    }
    if(position == 19){
      s();
    }
    if(position == 20){
      t();
    }
    if(position == 21){
      u();
    }
    if(position == 22){
      v();
    }
    if(position == 23){
      w();
    }
    if(position == 24){
      x();
    }
    if(position == 25){
      y();
    }
    if(position == 26){
      z();
    }
    if(position == 27){
      position = 1;
    }
  }

// Function to clear Braille display by moving all dots down
void clear(){
  dot1Down();
  delay(100);
  dot2Down();
  delay(100);
  dot3Down();
  delay(100);
  dot4Down();
  delay(100);
  dot5Down();
  delay(100);
  dot6Down();
  delay(100);
}

// Functions for each Braille letter from A to Z
void a(){
  dot1Up();
  myDFPlayer.play(2);
  delay(pause);
}

void b(){
  dot1Up();
  dot3Up();
  myDFPlayer.play(3);
  delay(pause);
}

void c(){
  dot1Up();
  dot2Up();
  myDFPlayer.play(4);
  delay(pause);
}

void d(){
  dot1Up();
  dot2Up();
  dot4Up();
  myDFPlayer.play(5);
  delay(pause);
}

void e(){
  dot1Up();
  dot4Up();
  myDFPlayer.play(6);
  delay(pause);
}

void f(){
  dot1Up();
  dot2Up();
  dot3Up();
  myDFPlayer.play(7);
  delay(pause);
}

void g(){
  dot1Up();
  dot2Up();
  dot3Up();
  dot4Up();
  myDFPlayer.play(8);
  delay(pause);
}

void h(){
  dot1Up();
  dot3Up();
  dot4Up();
  myDFPlayer.play(9);
  delay(pause);
}

void i(){
  dot2Up();
  dot3Up();
  myDFPlayer.play(10);
  delay(pause);
}

void j(){
  dot2Up();
  dot3Up();
  dot4Up();
  myDFPlayer.play(11);
  delay(pause);
}

void k(){
  dot1Up();
  dot5Up();
  myDFPlayer.play(12);
  delay(pause);
}

void l(){
  dot1Up();
  dot3Up();
  dot5Up();
  myDFPlayer.play(13);
  delay(pause);
}

void m(){
  dot1Up();
  dot2Up();
  dot5Up();
  myDFPlayer.play(14);
  delay(pause);
}

void n(){
  dot1Up();
  dot2Up();
  dot4Up();
  dot5Up();
  myDFPlayer.play(15);
  delay(pause);
}

void o(){
  dot1Up();
  dot4Up();
  dot5Up();
  myDFPlayer.play(16);
  delay(pause);
}

void p(){
  dot1Up();
  dot2Up();
  dot3Up();
  dot5Up();
  myDFPlayer.play(17);
  delay(pause);
}

void q(){
  dot1Up();
  dot2Up();
  dot3Up();
  dot4Up();
  dot5Up();
  myDFPlayer.play(18);
  delay(pause);
}

void r(){
  dot1Up();
  dot3Up();
  dot4Up();
  dot5Up();
  myDFPlayer.play(19);
  delay(pause);
}

void s(){
  dot2Up();
  dot3Up();
  dot5Up();
  myDFPlayer.play(20);
  delay(pause);
}

void t(){
  dot2Up();
  dot3Up();
  dot4Up();
  dot5Up();
  myDFPlayer.play(21);
  delay(pause);
}

void u(){
  dot1Up();
  dot5Up();
  dot6Up();
  myDFPlayer.play(22);
  delay(pause);
}

void v(){
  dot1Up();
  dot3Up();
  dot5Up();
  dot6Up();
  myDFPlayer.play(23);
  delay(pause);
}

void w(){
  dot2Up();
  dot3Up();
  dot4Up();
  dot6Up();
  myDFPlayer.play(24);
  delay(pause);
}

void x(){
  dot1Up();
  dot2Up();
  dot5Up();
  dot6Up();
  myDFPlayer.play(25);
  delay(pause);
}

void y(){
  dot1Up();
  dot2Up();
  dot4Up();
  dot5Up();
  dot6Up();
  myDFPlayer.play(26);
  delay(pause);
}

void z(){
  dot1Up();
  dot4Up();
  dot5Up();
  dot6Up();
  myDFPlayer.play(1);
  delay(pause);
}

// Function to move all Braille dots up
void up(){
  dot1Up();
  dot2Up();
  dot3Up();
  dot4Up();
  dot5Up();
  dot6Up();
}

// Interrupt service routine for "Next" button
void nextISR() {
  nextPressed = true;
}

// Interrupt service routine for "Previous" button
void previousISR() {
  previousPressed = true;
}
