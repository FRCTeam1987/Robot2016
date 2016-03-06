#include "DriveStraightForDistance.h"

DriveStraightForDistance::DriveStraightForDistance(double distance, double speed, float angleSetpoint)
: DriveStraightBase(speed, angleSetpoint)
{
	m_distance = distance;
	m_angleSetpoint = angleSetpoint;
}

void DriveStraightForDistance::Initialize()
{
	DriveStraightBase::Initialize();
}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraightForDistance::IsFinished()
{
	printf("Encoder Distance: %f\n", driveTrain->GetLeftEncoderDistance());
	return abs(driveTrain->GetLeftEncoderDistance())>= abs(m_distance);
}
