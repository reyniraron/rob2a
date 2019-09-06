
/*----------------------------------------------------------------------------------------------------*\
|*                                         - My motor functions -                                         *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|                                                 *|
|*                                                                                                    *|
|*    This file contains some basic generic functions for my robot                                      			*|
|*    NOTES:                                                                                          *|
|*
\*-----------------------------------------------------------------------------------------------4246-*/


const int full_power=127;

void drive(int dist, bool bf)
{
	while(abs(SensorValue[leftEncoder]) < (dist/WHEELBASE1)*360){
	if(bf)
	{
		motor[rightMotor] = full_power;
		motor[leftMotor]  = full_power;
	}
	else
	{
		motor[rightMotor] = -full_power;
		motor[leftMotor]  = -full_power;
	}
	}
}

void resetEncoder()
{
	SensorValue[leftEncoder]=0;
	SensorValue[rightEncoder]=0;
}

void stopMotors()
{
	motor[rightMotor] = 0;
	motor[leftMotor]  = 0;
}

void turn(int deg, bool left_right)
{
	//int encoder = (abs(SensorValue[leftEncoder])+ abs(SensorValue[rightEncoder]))/2;
	while(abs(SensorValue[leftEncoder]) < deg*TURNCONST)
		{
			if(left_right)
			{
				motor[rightMotor] = full_power;
				motor[leftMotor]  = -full_power;
			}
			else
			{
				motor[rightMotor] = -full_power;
				motor[leftMotor]  = full_power;
			}
		}
}
