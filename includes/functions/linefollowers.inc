#include "../headers/linefollowers.h"
#include "../headers/motor.h"

void findLine(int sensorNo, int lastEncoderValue, int threshold, int fullPower, int lowPower) {
    while (SensorValue[rightEncoder] > lastEncoderValue) {
        // Steer left
        if (sensorNo == -1) {
            motor[leftMotor]  = -lowPower;
            motor[rightMotor] = -fullPower;
        }
        // Steer right
        else if (sensorNo == 1) {
            motor[leftMotor]  = -fullPower;
            motor[rightMotor] = -lowPower;
        }
        else {
            motor[leftMotor] =  -fullPower;
            motor[rightMotor] = -fullPower;
        }
    }
    stopMotors();
}

void followLineForDistance(int distance, bool direction, int threshold, int normalSpeed, int slowerSpeed) {
    int dir = direction ? 1 : -1;  // 1 if forward, -1 if backwards
    resetEncoders();
    int lastEncoderValue = SensorValue[rightEncoder];
    int maxSensorNo;
    // Drive until both sensors reach the target value, straightening the robot automatically
    while (abs(SensorValue[rightEncoder]) < distance || abs(SensorValue[leftEncoder]) < distance) {
        bool robotIsOnLine = false;

        int leftValue = SensorValue(lineFollowerLEFT);
        int centerValue = SensorValue(lineFollowerCENTER);
        int rightValue = SensorValue(lineFollowerRIGHT);

        // If right sensor sees dark, counter-steer right
        if (rightValue > threshold) {
            motor[leftMotor]  = normalSpeed * dir;
            motor[rightMotor] = slowerSpeed * dir;
            robotIsOnLine = true;
            lastEncoderValue = SensorValue[rightEncoder];

            if (rightValue > centerValue && rightValue > leftValue) {
                maxSensorNo = 1;
            }
        }
        // If center sensor sees dark, go straight
        if (centerValue > threshold) {
            motor[leftMotor]  = normalSpeed * dir;
            motor[rightMotor] = normalSpeed * dir;
            robotIsOnLine = true;
            lastEncoderValue = SensorValue[rightEncoder];

            if (centerValue > leftValue && centerValue > rightValue) {
                maxSensorNo = 0;
            }
        }
        // If left sensor sees dark, counter-steer left
        if (leftValue > threshold) {
            motor[leftMotor]  = slowerSpeed * dir;
            motor[rightMotor] = slowerSpeed * dir;
            robotIsOnLine = true;
            lastEncoderValue = SensorValue[rightEncoder];

            if (leftValue > centerValue && leftValue > rightValue) {
                maxSensorNo = -1;
            }
        }
        if (!robotIsOnLine) {
            stopMotors();
            writeDebugStreamLine("Line not found.");
            wait1Msec(500);
            findLine(maxSensorNo, lastEncoderValue, threshold, normalSpeed / 4, slowerSpeed / 3);
            wait1Msec(500);
        }
    }
}
