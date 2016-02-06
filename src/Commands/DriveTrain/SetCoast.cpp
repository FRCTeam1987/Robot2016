#include "SetCoast.h"

SetCoast::SetCoast()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveTrain);
}

// Called just before this Command runs the first time
void SetCoast::Initialize()
{
	driveTrain->SetCoast();
}

// Called repeatedly when this Command is scheduled to run
void SetCoast::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SetCoast::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SetCoast::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetCoast::Interrupted()
{

}
