#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>
#include <Adafruit_MotorShield.h>
#include <utility/Adafruit_MS_PWMServoDriver.h>

// Create a Motor Shield object
Adafruit_MotorShield AFMS = Adafruit_MotorShield();

// Create motor objects
Adafruit_DCMotor* leftMotor = AFMS.getMotor(1);
Adafruit_DCMotor* rightMotor = AFMS.getMotor(3);

/* Assign a unique ID to this sensor at the same time */
Adafruit_LSM303_Accel_Unified accel = Adafruit_LSM303_Accel_Unified(54321);

void setup(void) 
{
  Serial.begin(115200);
  Serial.println("Accelermoeter Test"); Serial.println("");

  // Setup the Motor Shield
  AFMS.begin();
  leftMotor->setSpeed(0);
  rightMotor->setSpeed(0);
  
  /* Initialise the sensor */
  if(!accel.begin())
  {
    /* There was a problem detecting the ADXL345 ... check your connections */
    Serial.println("Ooops, no LSM303 detected ... Check your wiring!");
    //while(1);
  }
}

void loop(void) 
{  
  /* Get a new sensor event */ 
  sensors_event_t event; 
  accel.getEvent(&event);
  
  Serial.print("X: "); Serial.print(event.acceleration.x); Serial.print("  "); Serial.print("m/s^2 ");

  float compensation = event.acceleration.x * -1;
  
  
  if(compensation < 0){
      leftMotor->run(FORWARD);
      rightMotor->run(FORWARD);
      compensation *= -1;
    }
  else{
     leftMotor->run(BACKWARD);
     rightMotor->run(BACKWARD);
    }
  int speedMod = (compensation * 5) - 2;
  int finalSpeed = (speedMod < 0) ? 0 : speedMod;
  Serial.print("Comp: "); Serial.println(finalSpeed);
  leftMotor->setSpeed(finalSpeed);
  rightMotor->setSpeed(finalSpeed);
  
}
