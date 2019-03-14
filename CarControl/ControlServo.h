#include <Arduino.h>
#include <Servo.h>

const int servoPin=8; // check servo pin

void initServo();
void rotateServo(int angle);
void stopServo();
