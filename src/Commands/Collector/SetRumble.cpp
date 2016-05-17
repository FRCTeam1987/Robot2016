#include "SetRumble.h"

SetRumble::SetRumble()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis(;
	SetTimeout(2);
}

// Called just before this Command runs the first time
void SetRumble::Initialize()
{
		oi->getBroncoXbox()->StartRumble();
}

// Called repeatedly when this Command is scheduled to run
void SetRumble::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SetRumble::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void SetRumble::End()
{
	oi->getBroncoXbox()->StopRumble();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetRumble::Interrupted()
{
	oi->getBroncoXbox()->StopRumble();
}
