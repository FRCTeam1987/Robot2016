#include "SetBrake.h"

SetBrake::SetBrake()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveTrain);
}

// Called just before this Command runs the first time
void SetBrake::Initialize()
{
	SmartDashboard::PutString("Current_Command", "SetBrake");
	driveTrain->SetBrake();
}

// Called repeatedly when this Command is scheduled to run
void SetBrake::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SetBrake::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SetBrake::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetBrake::Interrupted()
{

}
