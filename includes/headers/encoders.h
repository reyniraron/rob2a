#define BASE_DIST 430
#define FULL_TURN 935

#ifndef MOTOR_H_
#define MOTOR_H_

void resetEncoders();
void driveForDistance(int distance, bool direction, int normalSpeed, int slowerSpeed);
void turn(float deg, bool direction);

#endif
