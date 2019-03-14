#pragma once
#include "ControlServo.h"

Servo myServo;

void initServo() {
  myServo.attach(servoPin); 
}


void rotateServo(int angle) {
  myServo.write(angle);
}

void stopServo() {
  myServo.detach();
}




