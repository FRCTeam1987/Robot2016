#include "SetHeadingOffset.h"

SetHeadingOffset::SetHeadingOffset()
{
	Requires(driveTrain);
}

// Called just before this Command runs the first time
void SetHeadingOffset::Initialize()
{
	driveTrain->ResetHeadingOffset();
}

// Called repeatedly when this Command is scheduled to run
void SetHeadingOffset::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SetHeadingOffset::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SetHeadingOffset::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetHeadingOffset::Interrupted()
{

}
