#include "WaitForOuterWorks.h"

WaitForOuterWorks::WaitForOuterWorks()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveTrain);
}

// Called just before this Command runs the first time
void WaitForOuterWorks::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void WaitForOuterWorks::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool WaitForOuterWorks::IsFinished()
{

}

// Called once after isFinished returns true
void WaitForOuterWorks::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WaitForOuterWorks::Interrupted()
{

}
