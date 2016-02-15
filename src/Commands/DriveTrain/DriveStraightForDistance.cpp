#include "DriveStraightForDistance.h"

DriveStraightForDistance::DriveStraightForDistance(double distance, double speed)
: DriveStraightBase(speed)
{
	m_distance = distance;
}

void DriveStraightForDistance::Initialize()
{
	DriveStraightBase::Initialize();
	driveTrain->ResetLeftEncoder();
}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraightForDistance::IsFinished()
{
	return abs(driveTrain->GetLeftEncoderDistance())>= abs(m_distance);
}
