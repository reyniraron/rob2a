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

#define POWER 63
#define LOW_POWER POWER / 4

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
  StartTask(watchForStop);  // Watch for stop button presses
  wait1Msec(2000);

  int threshold = 2300;  // Found by adding sensor values for dark and light together and dividing by 2
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

    // If right sensor sees dark, counter-steer right
    if (SensorValue(lineFollowerRIGHT) > threshold) {
      motor[leftMotor]  = POWER;
      motor[rightMotor] = LOW_POWER;
    }
    // If center sensor sees dark, go straight
    if (SensorValue(lineFollowerCENTER) > threshold) {
      motor[leftMotor]  = POWER;
      motor[rightMotor] = POWER;
    }
    // If left sensor sees dark, counter-steer left
    if (SensorValue(lineFollowerLEFT) > threshold) {
      motor[leftMotor]  = LOW_POWER;
      motor[rightMotor] = POWER;
    }
  }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
