#include "DriveStraightUntilRampSensor.h"

DriveStraightUntilRampSensor::DriveStraightUntilRampSensor(double speed)
: DriveStraightBase(speed)
{
	Requires(driveTrain);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraightUntilRampSensor::IsFinished()
{
	return driveTrain->getRampSensor();
}
