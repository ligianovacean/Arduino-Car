#pragma once
#include "MoveMotor.h"

void initMotor() {
  digitalWrite(mpin00, 0);
  digitalWrite(mpin01, 0);
  digitalWrite(mpin10, 0);
  digitalWrite(mpin11, 0);
  pinMode (mpin00, OUTPUT);
  pinMode (mpin01, OUTPUT);
  pinMode (mpin10, OUTPUT);
  pinMode (mpin11, OUTPUT);
}

void moveForward(int speed) {
  analogWrite(mpin00, speed); // use PWM
  digitalWrite(mpin01, 0);

  digitalWrite(mpin10, 0);
  analogWrite(mpin11, speed*0.95);
}


void moveBackward(int speed) {
  digitalWrite(mpin00, 0);
  analogWrite(mpin01, speed);

  analogWrite(mpin10, speed);
  digitalWrite(mpin11, 0);
  
}


void moveLeft(int speed) {
 analogWrite(mpin00, speed);
  digitalWrite(mpin01, 0);

  digitalWrite(mpin10, 0);
  digitalWrite(mpin11, 0);
}


void moveRight(int speed) {
  digitalWrite(mpin00, 0);
  digitalWrite(mpin01, 0);

  digitalWrite(mpin10, 0);
  analogWrite(mpin11, speed);
}


void stopMotor() {
  digitalWrite(mpin00, 0);
  digitalWrite(mpin01, 0);

  digitalWrite(mpin10, 0);
  digitalWrite(mpin11, 0);
}

