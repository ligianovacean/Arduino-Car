#include <Arduino.h>

// Pins for motor 1
#define mpin00 5
#define mpin01 6
//Pin for motor 2
#define mpin10 11
#define mpin11 3

void initMotor();
void moveForward(int speed);
void moveBackward(int speed);
void moveLeft(int speed);
void moveRight(int speed);
void stopMotor();

