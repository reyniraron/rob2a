#include "../headers/gyro.h"
#include "../headers/motor.h"

void gyroTurn(int deg10) {
    // Clear out any previous gyro readings
    SensorType[gyro] = sensorNone;
    wait1Msec(1000);
    // Reconfigure port as gyro sensor
    SensorType[gyro] = sensorGyro;
    wait1Msec(2000);

    int error = 5;  // Acceptable margin of error in turn

    // While gyro has turned less than deg10 - 100 (10° short of input)
    while (abs(SensorValue[gyro]) < deg10 - 100) {
        motor[rightMotor] = 60;
        motor[leftMotor] = -60;
    }
    // Brake briefly to prevent drift
    motor[rightMotor] = -5;
    motor[leftMotor] = 5;
    wait1Msec(100);

    // Finish turning the robot more slowly than before (within margin of error)
    while (abs(SensorValue[gyro]) > deg10 + error || abs(SensorValue[gyro]) < deg10 - error) {
        if (abs(SensorValue[gyro]) > deg10) {
            motor[rightMotor] = -40;
            motor[leftMotor] = 40;
        }
        else {
            motor[rightMotor] = 40;
            motor[leftMotor] = -40;
        }
    }
    stopMotors();
}