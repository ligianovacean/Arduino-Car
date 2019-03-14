/* #include <Servo.h>

// Pins of motor 1
#define mpin00 5
#define mpin01 6

// Pins of motor 2
#define mpin10 11
#define mpin11 3

//Servo srv;

// defines ultrasonic pins

const int trigPin = 10;  
const int echoPin = 9;  

// defines  ultrasonic variables
long duration;
int distance;


int compDist()
{
   // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH,30000);

  // Calculating the distance
  distance= duration*0.034/2;

  return distance;
}


void setup() {
  // configuration of motor pins as output, initially 0
  digitalWrite(mpin00, 0);
  digitalWrite(mpin01, 0);
  digitalWrite(mpin10, 0);
  digitalWrite(mpin11, 0);
  pinMode (mpin00, OUTPUT);
  pinMode (mpin01, OUTPUT);
  pinMode (mpin10, OUTPUT);
  pinMode (mpin11, OUTPUT);
  
  // LED pin
  pinMode(13, OUTPUT);

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input

  Serial.begin(9600);
}
// Function to control a motor
// Input: pins m1 and m2, direction and speed
void StartMotor (int m1, int m2, int forward, int speed)
{

  if (speed == 0) // stop
  {
    digitalWrite(m1, 0);
    digitalWrite(m2, 0);
  }
  else
  {
    if (forward)
    {
      digitalWrite(m2, 0);
      analogWrite (m1, speed); // use PWM
    }
    else
    {
      digitalWrite(m1, 0);
      analogWrite(m2 , speed);
    }
  }
}
// Safety function
// Commands motors to stop, then delays
void delayStopped(int ms)
{
  StartMotor (mpin00, mpin01, 0, 0);
  StartMotor (mpin10, mpin11, 0, 0);
  delay(ms);
}

//

// Use of servo
// Set three angles
// When finished, the servo remains in the middle (90 degrees)
void playWithServo(int pin)
{
  srv.attach(pin);
  int d;

  srv.write(0);
  delay(1000);
  
  d=compDist();
  
  Serial.print("Distance right: ");
  Serial.println(d);
  srv.write(180);

   d=compDist();
   delay(1000);
   
  Serial.print("Distance left: ");
  Serial.println(d);

  
  srv.write(90);
  delay(1000);

   d=compDist();
   
  Serial.print("Distance ahead: ");
  Serial.println(d);
  
  srv.detach();
  Serial.println("Repeating");
}
void loop() {
  // Warning code
  // Slow blink
  for (int i = 0; i < 10; i++)
  {
    digitalWrite(13, 1);
    delay(200);
    digitalWrite(13, 0);
    delay(200);
  }
  // Fast blink. Remove the USB cable!!!!
  for (int i = 0; i < 10; i++)
  {
    digitalWrite(13, 1);
    delay(100);
    digitalWrite(13, 0);
    delay(100);
  }
  digitalWrite(13, 1);
  // Start the servo motor
  playWithServo(8);
  
  // Now start the DC motors
  StartMotor (mpin00, mpin01, 0, 128);
  StartMotor (mpin10, mpin11, 0, 128);

  delay (500); // How long the motors are on
  delayStopped(500); // How long the motors are off

  StartMotor (mpin00, mpin01, 1, 128);
  StartMotor (mpin10, mpin11, 1, 128);

  delay (500);
  delayStopped(500);
  StartMotor (mpin00, mpin01, 0, 128);
  StartMotor (mpin10, mpin11, 1, 128);

  delay (500);
  delayStopped(500);

  StartMotor (mpin00, mpin01, 1, 128);
  StartMotor (mpin10, mpin11, 0, 128);
  
  delay (500);
  delayStopped(500);

}*/
