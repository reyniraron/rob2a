/*
this id a generic drife function that use time and it can go backward and forward
*/
void drive_time(int drive_time,bool b_f){
	int dir = (b_f)? (1):(-1);
	motor[rightMotor] = dir*127;
	motor[leftMotor]  = dir*127;
	wait1Msec(drive_time);
}
void reset_encoder(){
	SensorValue[rightEncoder]=0;
	SensorValue[leftEncoder]=0;
}
void stop_motors(int sop_time){
	motor[leftMotor]=0;
	motor[rightMotor]=0;
	wait1Msec(sop_time);
}
void drive(int dist, bool b_f){
	while(dist>SensorValue[rightEncoder])		// Creates an infinite loop, since "true" always evaluates to true
	{
		if(SensorValue[rightEncoder] == SensorValue[leftEncoder]) // If rightEncoder has counted the same amount as leftEncoder:
		{
			// Move Forward
			motor[rightMotor] = 80;		    // Right Motor is run at power level 80
			motor[leftMotor]  = 80;		    // Left Motor is run at power level 80
		}
		else if(SensorValue[rightEncoder] > SensorValue[leftEncoder])	// If rightEncoder has counted more encoder counts
		{
			// Turn slightly right
			motor[rightMotor] = 60;		    // Right Motor is run at power level 60
			motor[leftMotor]  = 80;		    // Left Motor is run at power level 80
		}
		else	// Only runs if leftEncoder has counted more encoder counts
		{
			// Turn slightly left
			motor[rightMotor] = 80;		    // Right Motor is run at power level 80
			motor[leftMotor]  = 60;		    // Left Motor is run at power level 60
		}
	}

}
