/*
   Project  :  BrailleBot
   Author   :  Mukesh Sankhla
   Website  :  makerbrains.com
*/

#include <ESP32Servo.h> //Search in Library Manager
#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"

#define FPSerial Serial1
#define pause 2000

const int nextPin = 45;
const int previousPin = 8;

volatile bool nextPressed = false;
volatile bool previousPressed = false;

int position = 0;

// Declare one Servo object per Braille dot
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

const int pin1 = 4;
const int pin2 = 5;
const int pin3 = 6;
const int pin4 = 7;
const int pin5 = 15;
const int pin6 = 16;

DFRobotDFPlayerMini myDFPlayer;

void setup() {
  pinMode(nextPin, INPUT_PULLUP);
  pinMode(previousPin, INPUT_PULLUP);

  // Attach servos to their pins
  servo1.attach(pin1);
  servo2.attach(pin2);
  servo3.attach(pin3);
  servo4.attach(pin4);
  servo5.attach(pin5);
  servo6.attach(pin6);

  FPSerial.begin(9600, SERIAL_8N1, 48, 46);
  Serial.begin(115200);

  Serial.println(F("Hello! I am BrailleBot."));

  attachInterrupt(digitalPinToInterrupt(nextPin), nextISR, FALLING);
  attachInterrupt(digitalPinToInterrupt(previousPin), previousISR, FALLING);

  if (!myDFPlayer.begin(FPSerial, true, true)) {
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1. Please recheck the connection!"));
    Serial.println(F("2. Please insert the SD card!"));
  }

  Serial.println(F("Let's Start Learning."));

  clear();
  delay(1000);
  myDFPlayer.volume(30);
  myDFPlayer.play(27);
  delay(4000);

  for(int i = 0; i < 5; i++){
    up();
    clear();
  }

  play();
}

void loop() {
  if (nextPressed) {
    position++;
    clear();
    play();
    nextPressed = false;
  }

  if (previousPressed) {
    position--;
    clear();
    play();
    previousPressed = false;
  }
}

// Servo control functions
void dot1Up(){ for (int pos = 180; pos >= 162; pos--) { servo1.write(pos); delay(5); } }
void dot1Down(){ for (int pos = 162; pos <= 180; pos++) { servo1.write(pos); delay(5); } }

void dot2Up(){ for (int pos = 0; pos <= 20; pos++) { servo2.write(pos); delay(5); } }
void dot2Down(){ for (int pos = 20; pos >= 0; pos--) { servo2.write(pos); delay(5); } }

void dot3Up(){ for (int pos = 180; pos >= 165; pos--) { servo3.write(pos); delay(5); } }
void dot3Down(){ for (int pos = 165; pos <= 180; pos++) { servo3.write(pos); delay(5); } }

void dot4Up(){ for (int pos = 0; pos <= 16; pos++) { servo4.write(pos); delay(5); } }
void dot4Down(){ for (int pos = 16; pos >= 0; pos--) { servo4.write(pos); delay(5); } }

void dot5Up(){ for (int pos = 180; pos >= 160; pos--) { servo5.write(pos); delay(5); } }
void dot5Down(){ for (int pos = 160; pos <= 180; pos++) { servo5.write(pos); delay(5); } }

void dot6Up(){ for (int pos = 0; pos <= 10; pos++) { servo6.write(pos); delay(5); } }
void dot6Down(){ for (int pos = 10; pos >= 0; pos--) { servo6.write(pos); delay(5); } }

void play(){
  if (position <= 0) position = 1;
  if (position > 27) position = 1;

  switch (position) {
    case 1: a(); break;
    case 2: b(); break;
    case 3: c(); break;
    case 4: d(); break;
    case 5: e(); break;
    case 6: f(); break;
    case 7: g(); break;
    case 8: h(); break;
    case 9: i(); break;
    case 10: j(); break;
    case 11: k(); break;
    case 12: l(); break;
    case 13: m(); break;
    case 14: n(); break;
    case 15: o(); break;
    case 16: p(); break;
    case 17: q(); break;
    case 18: r(); break;
    case 19: s(); break;
    case 20: t(); break;
    case 21: u(); break;
    case 22: v(); break;
    case 23: w(); break;
    case 24: x(); break;
    case 25: y(); break;
    case 26: z(); break;
  }
}

void clear(){
  dot1Down(); delay(100);
  dot2Down(); delay(100);
  dot3Down(); delay(100);
  dot4Down(); delay(100);
  dot5Down(); delay(100);
  dot6Down(); delay(100);
}

void a(){ dot1Up(); myDFPlayer.play(2); delay(pause); }
void b(){ dot1Up(); dot3Up(); myDFPlayer.play(3); delay(pause); }
void c(){ dot1Up(); dot2Up(); myDFPlayer.play(4); delay(pause); }
void d(){ dot1Up(); dot2Up(); dot4Up(); myDFPlayer.play(5); delay(pause); }
void e(){ dot1Up(); dot4Up(); myDFPlayer.play(6); delay(pause); }
void f(){ dot1Up(); dot2Up(); dot3Up(); myDFPlayer.play(7); delay(pause); }
void g(){ dot1Up(); dot2Up(); dot3Up(); dot4Up(); myDFPlayer.play(8); delay(pause); }
void h(){ dot1Up(); dot3Up(); dot4Up(); myDFPlayer.play(9); delay(pause); }
void i(){ dot2Up(); dot3Up(); myDFPlayer.play(10); delay(pause); }
void j(){ dot2Up(); dot3Up(); dot4Up(); myDFPlayer.play(11); delay(pause); }
void k(){ dot1Up(); dot5Up(); myDFPlayer.play(12); delay(pause); }
void l(){ dot1Up(); dot3Up(); dot5Up(); myDFPlayer.play(13); delay(pause); }
void m(){ dot1Up(); dot2Up(); dot5Up(); myDFPlayer.play(14); delay(pause); }
void n(){ dot1Up(); dot2Up(); dot4Up(); dot5Up(); myDFPlayer.play(15); delay(pause); }
void o(){ dot1Up(); dot4Up(); dot5Up(); myDFPlayer.play(16); delay(pause); }
void p(){ dot1Up(); dot2Up(); dot3Up(); dot5Up(); myDFPlayer.play(17); delay(pause); }
void q(){ dot1Up(); dot2Up(); dot3Up(); dot4Up(); dot5Up(); myDFPlayer.play(18); delay(pause); }
void r(){ dot1Up(); dot3Up(); dot4Up(); dot5Up(); myDFPlayer.play(19); delay(pause); }
void s(){ dot2Up(); dot3Up(); dot5Up(); myDFPlayer.play(20); delay(pause); }
void t(){ dot2Up(); dot3Up(); dot4Up(); dot5Up(); myDFPlayer.play(21); delay(pause); }
void u(){ dot1Up(); dot5Up(); dot6Up(); myDFPlayer.play(22); delay(pause); }
void v(){ dot1Up(); dot3Up(); dot5Up(); dot6Up(); myDFPlayer.play(23); delay(pause); }
void w(){ dot2Up(); dot3Up(); dot4Up(); dot6Up(); myDFPlayer.play(24); delay(pause); }
void x(){ dot1Up(); dot2Up(); dot5Up(); dot6Up(); myDFPlayer.play(25); delay(pause); }
void y(){ dot1Up(); dot2Up(); dot4Up(); dot5Up(); dot6Up(); myDFPlayer.play(26); delay(pause); }
void z(){ dot1Up(); dot4Up(); dot5Up(); dot6Up(); myDFPlayer.play(1); delay(pause); }

void up(){
  dot1Up(); dot2Up(); dot3Up();
  dot4Up(); dot5Up(); dot6Up();
}

void nextISR() {
  nextPressed = true;
}

void previousISR() {
  previousPressed = true;
}
