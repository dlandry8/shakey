#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <utility/Adafruit_MS_PWMServoDriver.h>

// Create a Motor Shield object
Adafruit_MotorShield AFMS = Adafruit_MotorShield();

// Create motor objects
Adafruit_DCMotor* leftMotor = AFMS.getMotor(1);
Adafruit_DCMotor* rightMotor = AFMS.getMotor(3);

void setup() {
  // Setup the Motor Shield
  AFMS.begin();
  leftMotor->setSpeed(0);
  rightMotor->setSpeed(0);


}

void loop() {
  
  leftMotor->run(FORWARD);
  rightMotor->run(FORWARD);
  leftMotor->setSpeed(30);
  rightMotor->setSpeed(30);
}
