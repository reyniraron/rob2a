#pragma config(Sensor, in4,    lineFollowerRIGHT, sensorLineFollower)
#pragma config(Sensor, in5,    lineFollowerCENTER, sensorLineFollower)
#pragma config(Sensor, in6,    lineFollowerLEFT, sensorLineFollower)
#pragma config(Sensor, dgtl1,  touchSensor,    sensorTouch)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                             	             - Verkefni 6 -                                           *|
|*                                                                                                    *|
|*  This program tells the robot to follow a path to fetch a glass and bring it back to a basket.     *|
|*  Then it repeats this process until it has fethced all the glasses and returned them.              *|
|*                                                                                                    *|
\*-----------------------------------------------------------------------------------------------4246-*/

#include "headers/stop.h"
#include "functions/stop.inc"

#define POWER 63
#define LOW_POWER POWER / 4

void findLine(int sensorNo, int threshold, int fullPower, int lowPower) {
	// -1 = left
  // 0 = center
  // 1 = right

	// If left saw the line last, steer left
	if (sensorNo == -1) {
		// writeDebugStreamLine("Turning left");

		if (SensorValue(lineFollowerLEFT) < threshold) {
			motor[leftMotor] = lowPower;
			motor[rightMotor] = fullPower;
		}
	}
	// If right saw the line last, steer right
	else if (sensorNo == 1) {
		// writeDebugStreamLine("Turning right");

		if (SensorValue(lineFollowerRIGHT) < threshold) {
			motor[leftMotor] = fullPower;
			motor[rightMotor] = lowPower;
		}
	}
	// If center saw the line last, the function should not have been called!
	else {
		// writeDebugStreamLine("Why did this function get called?");

		motor[leftMotor] = fullPower;
		motor[rightMotor] = fullPower;
	}
}

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
  StartTask(watchForStop);  // Watch for stop button presses
  wait1Msec(2000);

  int maxSensorNo;

  int threshold = 2340;  // Found by adding sensor values for dark and light together and dividing by 2
  while (true) {
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

    int leftValue = SensorValue(lineFollowerLEFT);
    int centerValue = SensorValue(lineFollowerCENTER);
    int rightValue = SensorValue(lineFollowerRIGHT);

    bool isOnLine = false;

    // writeDebugStreamLine("Max sensor: %d", maxSensorNo);

    // If right sensor sees dark, counter-steer right
    if (rightValue > threshold) {
      motor[leftMotor]  = POWER;
      motor[rightMotor] = LOW_POWER;

      // Right has highest value
      if (rightValue > centerValue && rightValue > leftValue) {
	    	maxSensorNo = 1;
	    }
	    isOnLine = true;
    }
    // If center sensor sees dark, go straight
    if (centerValue > threshold) {
      motor[leftMotor]  = POWER;
      motor[rightMotor] = POWER;

      // Center has highest value
      if (centerValue > leftValue && centerValue > rightValue) {
    		maxSensorNo = 0;
    	}
    	isOnLine = true;
    }
    // If left sensor sees dark, counter-steer left
    if (leftValue > threshold) {
      motor[leftMotor]  = LOW_POWER;
      motor[rightMotor] = POWER;

      // Left has highest value
	    if (leftValue > centerValue && leftValue > rightValue) {
	    	maxSensorNo = -1;
	    }
	    isOnLine = true;
    }

    // If robot is not on line, find line
    if (!isOnLine) {
    	// writeDebugStreamLine("Robot lost line!");
    	findLine(maxSensorNo, threshold, POWER, LOW_POWER);
    }
  }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
