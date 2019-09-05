void drive_time(int drive_time,bool b_f){
	int dir = (b_f)? (1):(-1);
	motor[rightMotor] = dir*127;
	motor[leftMotor]  = dir*127;
	wait1Msec(drive_time);
}
