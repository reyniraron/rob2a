#include "../headers/linefollowers.h"

void followLineForDistance(int distance, bool direction, int threshold, int normalSpeed, int slowerSpeed) {
    int dir = direction ? 1 : -1;  // 1 if forward, -1 if backwards
    resetEncoders();
    // Drive until both sensors reach the target value, straightening the robot automatically
    while (abs(SensorValue[rightEncoder]) < distance || abs(SensorValue[leftEncoder]) < distance) {		// Creates an infinite loop, since "true" always evaluates to true
        // If right sensor sees dark, counter-steer right
        if (SensorValue(lineFollowerRIGHT) > threshold) {
            motor[leftMotor]  = normalSpeed * dir;
            motor[rightMotor] = slowerSpeed * dir;
        }
        // If center sensor sees dark, go straight
        if (SensorValue(lineFollowerCENTER) > threshold) {
            motor[leftMotor]  = normalSpeed * dir;
            motor[rightMotor] = normalSpeed * dir;
        }
        // If left sensor sees dark, counter-steer left
        if (SensorValue(lineFollowerLEFT) > threshold) {
            motor[leftMotor]  = slowerSpeed * dir;
            motor[rightMotor] = slowerSpeed * dir;
        }
    }
}
