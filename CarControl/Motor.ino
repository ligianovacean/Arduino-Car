#include "MoveMotor.h"
#include "ReadSensor.h"
#include "AvoidObstacles.h"
#include "ControlServo.h"
#include "Follow.h"
#include "Light.h"

int control;
int dir;

const int buzzerPin=7;

void setup() {
  initMotor();
  initSensor();
  initLight(); 
  initServo();
  rotateServo(90);
  delay(500);
  stopServo();
  
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(38400); 
  Serial.println("AT");
  Serial.println("AT+INIT");
  Serial.println("AT+CLASS=1");
  

  control=0;
}


void loop() {

  
  char c='N';
  if (Serial.available()){
    c=(char)Serial.read();

  if (c=='X' || c=='x') {
    control=2;
    stopMotor();
  }
  if (c=='U' || c=='u') {
    control=1;
    stopMotor();
  }
  if (c=='W' || c=='w')
  {
    control=0;
    stopMotor();
  }

   if (c=='V' || c=='v') {
    control=3;
    stopMotor();
  }
  
  if(control==0)
    {
      if (c=='F'){
        moveForward(70);
        delay(1000);
        stopMotor();
      }
      if (c=='L'){
        moveLeft(70);
        delay(1000);
        stopMotor();
      }
      if (c=='R'){
        moveRight(70);
        delay(1000);
        stopMotor();
      }
      if (c=='B'){
        moveBackward(70);
        delay(1000);
        stopMotor();
      } 
    }
  }
  
   if (control==1)
  {
    if (detectObstacle()==true)
    {
        stopMotor();
        avoidObstacle();
    }
    else
    {
      moveForward(70);
      delay(200);
    }
 }
  if(control==2)
  {
    if (detectObstacle()==true)
    {
        moveForward(70);
        delay(200);
    }
    else
    {
      stopMotor();
      //analogWrite(buzzerPin, 127);
      delay(100); 
      int angle=findObject();
      followObject(angle);
    }
  }

  if(control==3)
  {
    stopMotor();
    delay(5);
    int dir=getLightDirection();
    if(dir==0)
      moveForward(70);
    if(dir==1)
      moveLeft(70);  
    if(dir==2)
      moveBackward(90);
    if(dir==3)
      moveRight(70); 
    delay(100);
  }

  
  delay(5);
}


