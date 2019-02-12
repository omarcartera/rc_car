/*****************************
*     LaFerrari control      *
*  with Arduino and 1Sheeld  *
*                            *
*        7 Aug 2016          *
*      By: Omar Gamal        *
*    c.omargamal@gmail.com   *
******************************/

//pins for each controller
#define MOVE 8
#define BACK 9
#define RIGHT 10
#define LEFT 11

//to use just the data for the needed sensor and avoid too much usage of the memory
#define CUSTOM_SETTINGS
#define INCLUDE_ACCELEROMETER_SENSOR_SHIELD

#include <OneSheeld.h>

void setup()
{
  OneSheeld.begin();
  
  pinMode(MOVE, OUTPUT);
  pinMode(BACK, OUTPUT);
  pinMode(RIGHT, OUTPUT);
  pinMode(LEFT, OUTPUT);

//putting the car in neutral mode
  digitalWrite(MOVE, HIGH);
  digitalWrite(BACK, HIGH);
  digitalWrite(RIGHT, HIGH);
  digitalWrite(LEFT, HIGH);
}

void loop()
{
  //moving forward
  if(AccelerometerSensor.getZ() > 3)
  {
    digitalWrite(MOVE, LOW);
    digitalWrite(BACK, HIGH);
  }

  //moving backward
  if(AccelerometerSensor.getZ() < -3)
  {
    digitalWrite(MOVE, HIGH);
    digitalWrite(BACK, LOW);
  }

  //neither forward nor backward
  if(AccelerometerSensor.getZ() < 3 && AccelerometerSensor.getZ() > -3)
  {
    digitalWrite(MOVE, HIGH);
    digitalWrite(BACK, HIGH);
  }

  //move forward with steering to the right
  if((AccelerometerSensor.getZ() > 3) && (AccelerometerSensor.getY() > 3))
  {
    digitalWrite(MOVE, LOW);
    digitalWrite(BACK, HIGH);
    digitalWrite(RIGHT, LOW);
    digitalWrite(LEFT, HIGH);
  }

  //moving forward with steering to the left
  if((AccelerometerSensor.getZ() > 3) && (AccelerometerSensor.getY() < -3))
  {
    digitalWrite(MOVE, LOW);
    digitalWrite(BACK, HIGH);
    digitalWrite(RIGHT, HIGH);
    digitalWrite(LEFT, LOW);
  }

  //moving back with steering to the right
  if((AccelerometerSensor.getZ() < -3) && (AccelerometerSensor.getY() > 3))
  {
    digitalWrite(MOVE, HIGH);
    digitalWrite(BACK, LOW);
    digitalWrite(RIGHT, LOW);
    digitalWrite(LEFT, HIGH);
  }

  //moving back with steering to the left
  if((AccelerometerSensor.getZ() < -3) && (AccelerometerSensor.getY() < -3))
  {
    digitalWrite(MOVE, HIGH);
    digitalWrite(BACK, LOW);
    digitalWrite(RIGHT, HIGH);
    digitalWrite(LEFT, LOW);
  }

  //don't steer
  if((AccelerometerSensor.getY() < 3) && (AccelerometerSensor.getY() > -3))
  {
    digitalWrite(RIGHT, HIGH);
    digitalWrite(LEFT, HIGH);
  }
}
