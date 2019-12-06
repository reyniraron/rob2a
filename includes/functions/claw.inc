#include "../headers/claw.h"

void openClaw() {
    motor[clawMotor] = -FULL_POWER;
    wait1Msec(1000);
    motor[clawMotor] = 0;
}
task closeClaw() {
    while (true) {
        motor[clawMotor] = FULL_POWER;
    }
}
task liftArm() {
    while (true) {
        while (SensorValue[potentiometer] < 1600) {
            motor[armMotor] = -FULL_POWER / 2;
        }
        motor[armMotor] = 0;
    }
}
