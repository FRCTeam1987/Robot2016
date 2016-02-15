#include "DriveStraightAfterRampSensor.h"

DriveStraightAfterRampSensor::DriveStraightAfterRampSensor(double speed)
: DriveStraightBase(speed)
{

}

bool DriveStraightAfterRampSensor::IsFinished()
{
	return !driveTrain->getRampSensor();
}
