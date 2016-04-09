#include "IndicateOnTarget.h"

IndicateOnTarget::IndicateOnTarget()
{
	Requires(driveTrain);
}

// Called just before this Command runs the first time
void IndicateOnTarget::Initialize()
{
	double azimuth = driveTrain->GetAzimuth();
	const double MIN_AZIMUTH = 0.2;
	const double MAX_AZIMUTH = 1.7;

	if(azimuth > MIN_AZIMUTH && azimuth < MAX_AZIMUTH)
	{
		lights->Set(Lights::COLOR::PURPLE);
	}
	else
	{
		lights->Set(Lights::COLOR::RED);
	}
}

// Called repeatedly when this Command is scheduled to run
void IndicateOnTarget::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool IndicateOnTarget::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void IndicateOnTarget::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IndicateOnTarget::Interrupted()
{

}
