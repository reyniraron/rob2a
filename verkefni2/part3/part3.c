#pragma config(Sensor, dgtl3,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  leftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                                     - Verkefni 2 - 3. hluti -                                      *|
|*                                                                                                    *|
|*  This program instructs the robot to move forward for 0.5 meters, using the shaft encoders,        *|
|*  and then back 0.5 meters. The robot is automatically straightened by dynamically changing power.  *|
|*  This is repeated, increasing the distance 0.5 m every time until 2.5 m is reached.                *|
|*
|*                                      - Wheel Circumference -                                       *|
|*  The wheels on the robot have a radius of 5.2 cm each. Circumference is equal to 2 * r * pi,       *|
|*  which equals about 32.67 cm.                                                                      *|
|*                                                                                                    *|
\*-----------------------------------------------------------------------------------------------4246-*/

#include "headers/motor.h"
#include "functions/motor.inc"
#include "headers/encoders.h"
#include "functions/encoders.inc"

#define NORMAL_SPEED 80
#define SLOWER_SPEED 60
#define WAIT_TIME 1000

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
	wait1Msec(2000);							// Robot waits for 2000 milliseconds before executing program

	for (int i = 0; i <= 5; i++) {
		// resetEncoders();
		driveForDistance(i * BASE_DIST, true, NORMAL_SPEED, SLOWER_SPEED);  // forwards
		stopMotors();
		wait1Msec(WAIT_TIME);
		driveForDistance(i * BASE_DIST, false, NORMAL_SPEED, SLOWER_SPEED); // backwards
		stopMotors();
		wait1Msec(WAIT_TIME);
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
