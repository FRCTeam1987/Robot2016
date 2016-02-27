#include "AutoDrive.h"

AutoDrive::AutoDrive()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveTrain);
}

// Called just before this Command runs the first time
void AutoDrive::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutoDrive::Execute()
{
	driveTrain->AutoDrive(0, -0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDrive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AutoDrive::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDrive::Interrupted()
{

}
