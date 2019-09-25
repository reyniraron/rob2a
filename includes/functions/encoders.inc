// Reset shaft encoders
void resetEncoders() {
    SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
}

// Drive based on shaft encoders
void driveForDistance(int distance, bool direction, int normalSpeed, int slowerSpeed) {
    int dir = direction ? 1 : -1;  // 1 if forward, 2 if backwards
    resetEncoders();
    // Drive until both sensors reach the target value, straightening the robot automatically
    while (abs(SensorValue[rightEncoder]) < distance || abs(SensorValue[leftEncoder]) < distance) {		// Creates an infinite loop, since "true" always evaluates to true
        // If both encoders have the same value, move at normal speed forward or backwards
        if (SensorValue[rightEncoder] == SensorValue[leftEncoder]) {
            // Move Forward
            motor[rightMotor] = normalSpeed * dir;
            motor[leftMotor]  = normalSpeed * dir;
        }
        // Turn slightly right
        else if (abs(SensorValue[rightEncoder]) > abs(SensorValue[leftEncoder])) {
            motor[rightMotor] = slowerSpeed * dir;
            motor[leftMotor]  = normalSpeed * dir;
        }
        // Turn slightly left
        else {
            motor[rightMotor] = normalSpeed * dir;
            motor[leftMotor]  = slowerSpeed * dir;
        }
    }
}

// Turn a specified number of degrees
void turn(float deg, bool direction) {
    int dir = direction ? 1 : -1;
    resetEncoders();
    while (abs(SensorValue[rightEncoder]) < deg && SensorValue[leftEncoder] > -deg) {
        motor[rightMotor] = 63 * dir;
        motor[leftMotor] = -63 * dir;
    }
    stopMotors();
}
