#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>
#include <Adafruit_MotorShield.h>
#include <utility/Adafruit_MS_PWMServoDriver.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield();

Adafruit_StepperMotor* newMotor = AFMS.getMotor(1);

void setup() {
  
  // put your setup code here, to run once:
  newMotor->setSpeed(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  newMotor->onestep(FORWARD, SINGLE)
  newMotor->setSpeed(100);
  delay(3000);
  newMotor->onestep(BACKWARD, SINGLE)
  newMotor->setSpeed(100);
  delay(3000);
}
