#include "AutoDrive.h"

AutoDrive::AutoDrive()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveTrain);
	SetTimeout(5);
}

// Called just before this Command runs the first time
void AutoDrive::Initialize()
{
	driveTrain->ResetGyro();
}

// Called repeatedly when this Command is scheduled to run
void AutoDrive::Execute()
{
	if (359 > driveTrain->GetGyroAngle()) {
		driveTrain->AutoDrive(0, 0.4);
	}
	if (1 > driveTrain->GetGyroAngle()) {
		driveTrain->AutoDrive(0, -0.4);
	}
	else {
		driveTrain->AutoDrive(0.5, 0);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDrive::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void AutoDrive::End()
{
	driveTrain->AutoDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDrive::Interrupted()
{
	driveTrain->AutoDrive(0,0);
}
