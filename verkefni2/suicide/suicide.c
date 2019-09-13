#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                                            - Suicide -                                             *|
|*                                                                                                    *|
|*  This program instructs the robot to move forward at full power for 0.5 meters and then back       *|
|*  0.5 meters. This is repeated, increasing the distance 0.5 m every time until 2.5 m is reached.    *|
|*                                                                                                    *|
\*-----------------------------------------------------------------------------------------------4246-*/

#include "headers/motor.h"
#include "functions/motor.inc"

#define WAIT_TIME 500;

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
	wait1Msec(2000);
	for (int i = 0; i <= 5; i++) {
		driveFor(i * BASE_TIME, true);  // forwards
		stopMotors();
		wait1Msec(WAIT_TIME);
		driveFor(i * BASE_TIME, false); // backwards
		stopMotors();
		wait1Msec(WAIT_TIME);
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
