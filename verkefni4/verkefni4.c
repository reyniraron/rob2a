#pragma config(Sensor, in1,    lightSensor,    sensorReflection)
#pragma config(Sensor, dgtl1,  touchSensor,    sensorTouch)
#pragma config(Sensor, dgtl3,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl7,  sonar,          sensorSONAR_cm)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                                           - Verkefni 4 -                                           *|
|*                                                                                                    *|
|*  This program instructs the robot to move forward for as long as it can while not getting closer   *|
|*  than 20 cm to any obstacles. If the robot is too close to obstacles, it will turn in a random     *|
|*  direction in an attempt to find a clear path.                                                     *|
|*                                                                                                    *|
\*-----------------------------------------------------------------------------------------------4246-*/

#include "headers/motor.h"
#include "functions/motor.inc"
#include "headers/encoders.h"
#include "functions/encoders.inc"

#include "headers/stop.h"
#include "functions/stop.inc"

#define SPEED 63
#define WAIT_TIME 1000

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
	StartTask(watchForStop);  // Watch for stop button presses
	const float TURN_DEG = BASE_TURN * 90.0 / 360.0;
	while (true) {
		int sonarValue = SensorValue(sonar);
		// Drive forward if sonar is more than 20 cm away from obstacles
		if (sonarValue > 20 || sonarValue == -1) {
			motor[leftMotor] = SPEED;
			motor[rightMotor] = SPEED;
		}
		// If sonar is within 20 cm proximity, turn in a random direction
		else {
			stopMotors();
			turn(TURN_DEG, random(2)); // 0 or 1 (right or left)
		}
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
