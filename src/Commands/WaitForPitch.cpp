#include "WaitForPitch.h"

WaitForPitch::WaitForPitch()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void WaitForPitch::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void WaitForPitch::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool WaitForPitch::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void WaitForPitch::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WaitForPitch::Interrupted()
{

}
