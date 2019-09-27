#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port4,           armMotor,      tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port5,           clawMotor,     tmotorServoContinuousRotation, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                                     - Verkefni 3 - 1. hluti -                                      *|
|*                                                                                                    *|
|*  This program uses the left joystick to move the robot forward and backward and the right joystick *|
|*  to turn. Button 8R lifts the arm, 8D lowers the arm, 8U opens the claw and 8L closes it.          *|
|*                                                                                                    *|
\*----------------------------------------------------------------------------------------------------*/

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main ()
{
	short rightJoyXValue;
	short leftJoyYValue;
  while (true) {
  	/* ==============
  	   Robot movement
  	   ============== */
  	rightJoyXValue = vexRT[Ch1];  // Right joystick X axis
  	leftJoyYValue = vexRT[Ch3];   // Left joystick Y axis
  	// Turning sideways
    if (rightJoyXValue != 0) {
    	motor[leftMotor]  =  rightJoyXValue;
    	motor[rightMotor] = -rightJoyXValue;
    }
    // Going forward
    else {
    	motor[leftMotor]  = leftJoyYValue;
    	motor[rightMotor] = leftJoyYValue;
    }
    /* ===
       Arm
       === */
    // Arm up
    if (vexRT[Btn8R]) {
    	motor[armMotor] = 63;
    }
    // Arm down
    else if (vexRT[Btn8D]) {
    	motor[armMotor] = -32;
    }
    // Arm stationary
    else {
    	motor[armMotor] = 0;
    }
    /* ====
       Claw
       ==== */
    if (vexRT[Btn8U]) {
    	motor[clawMotor] = 60;
    }
    else if (vexRT[Btn8L]) {
    	motor[clawMotor] = -60;
    }
    else {
    	motor[clawMotor] = 0;
    }
  }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
