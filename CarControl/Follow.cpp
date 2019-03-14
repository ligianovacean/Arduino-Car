#pragma once
#include "ReadSensor.h"
#include "ControlServo.h"
#include "MoveMotor.h"



int minD(int* d)
{
  int minI=0;
  int minV=d[0];
  for(int i=1;i<=4;i++)
    if(d[i]<minV)
    {
      minI=i;
      minV=d[i];
    }
   return minI*45;
}

int findObject()
{
  initServo();

  int dist[5];
  
  rotateServo(0);
  delay(600);  //try 200
  dist[0]=computeDistance();

  rotateServo(45);
  delay(300);
  dist[1]=computeDistance();
 
  
  rotateServo(90);
  delay(300);  //try 200
  dist[2]=computeDistance();

  rotateServo(135);
  delay(300);
  dist[3]=computeDistance();

  rotateServo(180);
  delay(300);
  dist[4]=computeDistance();

  rotateServo(90);
  delay(600);
  stopServo();
  return minD(dist);
}

void followObject(int angle)
{

  //ceva cu rosu
  if(angle==0)
  {
     moveRight(128);
     delay(500);
     stopMotor();
  }
  if (angle == 45) {
    moveRight(64);
    delay(500);
    stopMotor();
  }
  if (angle == 90) {
    moveForward(70);
    delay(200);
    stopMotor();
  }

   if (angle == 135) {
    moveLeft(64);
    delay(200);
    stopMotor();
  }

  if (angle == 180) {
    moveLeft(128);
    delay(500);
    stopMotor();
  }
}

  

  
