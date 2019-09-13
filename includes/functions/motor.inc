// Generic drive function
void driveFor(int time, bool direction) {
    int dir = direction ? 1 : -1;
    motor[leftMotor] = FULL_POWER * dir;
    motor[rightMotor] = FULL_POWER * dir;
    wait1Msec(time);
}

// Stop motors from driving
void stopMotors() {
    motor[leftMotor] = 0;
    motor[rightMotor] = 0;
}

// Reset shaft encoders
void resetEncoders() {
    SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
}
