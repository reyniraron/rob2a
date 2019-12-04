#ifndef MOTOR_H_
#define MOTOR_H_

#define BASE_DIST 430
#define BASE_TURN 930

void resetEncoders();
void driveForDistance(int distance, bool direction, int normalSpeed, int slowerSpeed);
void turn(float deg, bool direction);

#endif
