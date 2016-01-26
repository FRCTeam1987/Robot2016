#include "ResetEncoder.h"

ResetEncoder::ResetEncoder()
{
	Requires(driveTrain);
}

// Called just before this Command runs the first time
void ResetEncoder::Initialize()
{
	driveTrain->ResetEncoder();
}

// Called repeatedly when this Command is scheduled to run
void ResetEncoder::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ResetEncoder::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ResetEncoder::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ResetEncoder::Interrupted()
{

}
