#pragma once
#include "ReadSensor.h"

void initSensor() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}


int computeDistance() {
   // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  long duration = pulseIn(echoPin, HIGH, 30000);
  int distance= duration*0.034/2;
  delay(100);

  return distance;
}





