#include "ToggleDriverControls.h"

ToggleDriverControls::ToggleDriverControls()
{
	Requires(driveTrain);
	driveTrain->ToggleReverse();
}

// Called just before this Command runs the first time
void ToggleDriverControls::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ToggleDriverControls::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ToggleDriverControls::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ToggleDriverControls::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleDriverControls::Interrupted()
{

}
