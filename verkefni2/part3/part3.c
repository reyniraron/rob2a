#pragma config(Sensor, dgtl3,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  leftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                                     - Verkefni 2 - 3. hluti -                                      *|
|*                                                                                                    *|
|*  This program instructs the robot to move forward for 0.5 meters at a time, 15 times, and turn in  *|
|*  different, predetermined directions in between to solve a specific problem.                       *|
|*                                                                                                    *|
\*-----------------------------------------------------------------------------------------------4246-*/

#include "headers/motor.h"
#include "functions/motor.inc"
#include "headers/encoders.h"
#include "functions/encoders.inc"

#define NORMAL_SPEED 80
#define SLOWER_SPEED 60
#define WAIT_TIME 1000

#define RIGHT true
#define LEFT false

// Directions to turn in (in order)
short turns[15] = {
	RIGHT,
	LEFT,
	LEFT,
	RIGHT,
	RIGHT,
	LEFT,
	RIGHT,
	RIGHT,
	LEFT,
	RIGHT,
	RIGHT,
	LEFT,
	LEFT,
	RIGHT,
	-1  // Do not turn in the end
};

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
	const float TURN_DEG = BASE_TURN * 90.0 / 360.0;
	wait1Msec(2000);							// Robot waits for 2000 milliseconds before executing program
	for (int i = 0; i < 15; i++) {
		// writeDebugStream("Round %d: ", i);
		driveForDistance(BASE_DIST / 2.0, true, NORMAL_SPEED, SLOWER_SPEED);  // forwards
		stopMotors();
		// writeDebugStream("Finished moving. ");
		wait1Msec(WAIT_TIME);
		if (turns[i] != -1) {
			// writeDebugStreamLine("Turning %d in direction %d.", TURN_DEG, turns[i]);
			turn(TURN_DEG, turns[i]);
		}
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
