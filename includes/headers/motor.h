#ifndef MOTOR_H_
#define MOTOR_H_
#endif
#define FULL_POWER 127
#define BASE_TIME 1000
#define BASE_DIST 430

void driveFor(int time, bool direction);
void stopMotors();
void resetEncoders();
void driveForDistance();
