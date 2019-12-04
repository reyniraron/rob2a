#include "../headers/gyro.h"
#include "../headers/motor.h"

void gyroTurn(int deg10) {
    int error = 5;  // Acceptable error in turn

    // While gyro has turned less than deg10 - 100 (10° short of input)
    while (abs(SensorValue[gyro]) < deg10 - 100) {
        motor[rightMotor] = 30;
        motor[leftMotor] = -30;
    }
    // Brake briefly to prevent drift
    motor[rightMotor] = -5;
    motor[leftMotor] = 5;
    wait1Msec(100);

    // Finish turning the robot more slowly than before (within margin of error)
    while (abs(SensorValue[gyro]) > deg10 + error || abs(SensorValue[gyro]) < deg10 - error) {
        if (abs(SensorValue[gyro]) > deg10) {
            motor[rightMotor] = -20;
            motor[leftMotor] = 20;
        }
        else {
            motor[rightMotor] = 20;
            motor[leftMotor] = -20;
        }
    }
    stopMotors();
}