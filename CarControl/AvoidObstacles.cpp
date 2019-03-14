#pragma once
#include "ReadSensor.h"
#include "ControlServo.h"
#include "MoveMotor.h"

bool detectObstacle() {
    int distances[3];
    int ok = 0;
    for (int i = 0; i < 3; i++) {
      distances[i] = computeDistance();
      if ((distances[i] != 0) && (distances[i] < 25))
      {  
         ok++;
      }
    }

    if (ok >= 2)
      return true;

    return false;
}


int avoidanceType() {
  initServo();
  // Right rotation
  rotateServo(0);
  delay(1000);
  int rightDist = computeDistance();

  //Left rotation
  rotateServo(180);
  delay(500);
  int leftDist = computeDistance();

  rotateServo(90);
  delay(500);
  stopServo();

  if (leftDist > rightDist)
    return 0;

  return 1;
}


void avoidObstacle() {
  int dir = avoidanceType();
  if (dir == 0) {
    moveLeft(128);
    delay(500);
    stopMotor();
  }

  if(dir==1)
  {
    moveRight(128);
    delay(500);
    stopMotor();
  }
}
