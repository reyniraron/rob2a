#pragma config(Sensor, in4,    lineFollowerRIGHT, sensorLineFollower)
#pragma config(Sensor, in5,    lineFollowerCENTER, sensorLineFollower)
#pragma config(Sensor, in6,    lineFollowerLEFT, sensorLineFollower)
#pragma config(Sensor, dgtl1,  touchSensor,    sensorTouch)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                             	             - Verkefni 5 -                                           *|
|*                                                                                                    *|
|*  This program uses 3 line followers to track and follow a dark line on a light surface.            *|
|*  There is a two second pause at the beginning of the program.                                      *|
|*                                                                                                    *|
\*-----------------------------------------------------------------------------------------------4246-*/
#include "headers/stop.h"
#include "functions/stop.inc"
#include "headers/motor.h"
#include "functions/motor.inc"
#include "headers/gyro.h"
#include "functions/gyro.inc"
#include "headers/claw.h"
#include "functions/claw.inc"

#define POWER FULL_POWER
#define LOW_POWER POWER / 4

#define RIGHT_SENSOR 1
#define CENTER_SENSOR 0
#define LEFT_SENSOR -1

void findLine(int lastSensorNo) {
  // TODO: Find line using number of sensor that saw line last
  if (lastSensorNo == RIGHT_SENSOR) {

  }
  else if (lastSensorNo == LEFT_SENSOR) {

  }
  else {

  }
}

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
  StartTask(watchForStop);  // Watch for stop button presses
  wait1Msec(2000);

  const int threshold = 2340;  // Found by adding sensor values for dark and light together and dividing by 2
  int sawLineLast;

  while (true) {
    const int rightValue = SensorValue(lineFollowerRIGHT);
    const int centerValue = SensorValue(lineFollowerCENTER);
    const int leftValue = SensorValue(lineFollowerLEFT);

    int sensorsOnLine = 0;
  	// Show sensor values on LCD
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -+
    displayLCDCenteredString(0, "LEFT  CNTR  RGHT");        //            |
    displayLCDPos(1, 0);                                    //            |
    displayNextLCDNumber(SensorValue(lineFollowerLEFT));    //            |
    displayLCDPos(1, 6);                                    //            |
    displayNextLCDNumber(SensorValue(lineFollowerCENTER));  //            |
    displayLCDPos(1, 12);                                   //  L  C  R   |
    displayNextLCDNumber(SensorValue(lineFollowerRIGHT));   //  x  x  x   |
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -+

    // If right sensor sees dark, counter-steer right
    if (rightValue > threshold) {
      motor[leftMotor]  = POWER;
      motor[rightMotor] = LOW_POWER;
      isOnLine = true;
      // Keep track of which sensor has the highest value in order to find line if robot goes off track
      if (rightValue > centerValue && rightValue > leftValue) {
        sawLineLast = RIGHT_SENSOR;
      }
      sensorsOnLine++;
    }
    // If center sensor sees dark, go straight
    if (centerValue > threshold) {
      motor[leftMotor]  = POWER;
      motor[rightMotor] = POWER;
      isOnLine = true;
      if (centerValue > rightValue && centerValue > leftValue) {
        sawLineLast = CENTER_SENSOR;
      }
      sensorsOnLine++;
    }
    // If left sensor sees dark, counter-steer left
    if (leftValue > threshold) {
      motor[leftMotor]  = LOW_POWER;
      motor[rightMotor] = POWER;
      isOnLine = true;
      if (leftvalue > centerValue && leftValue > rightValue) {
        sawLineLast = LEFT_SENSOR;
      }
      sensorsOnLine++;
    }
    // If no sensors saw line, find it
    if (sensorsOnLine == 0) {
    	findLine(sawLineLast);
    	stopMotors();
    }
    // If all sensor saw line, robot has reached the end of the path
    else if (sensorsOnLine == 3) {
      stopMotors();
      // TODO: Grab glass
      gyroTurn(1800);  // Turn 180°
      wait1Msec(500);
    }
  }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
