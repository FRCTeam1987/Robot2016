#include "DriveStraightForDistance.h"

DriveStraightForDistance::DriveStraightForDistance(double distance, double speed)
: DriveStraightBase(speed)
{
	m_distance = distance;
}

void DriveStraightForDistance::Initialize()
{
	DriveStraightBase::Initialize();
	m_distance = SmartDashboard::GetNumber("Drive_Distance", 60);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraightForDistance::IsFinished()
{
	printf("Encoder Distance: %f\n", driveTrain->GetLeftEncoderDistance());
	return abs(driveTrain->GetLeftEncoderDistance())>= abs(m_distance);
}
