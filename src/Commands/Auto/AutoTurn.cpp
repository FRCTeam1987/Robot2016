#include "AutoTurn.h"

AutoTurn::AutoTurn()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveTrain);
}

// Called just before this Command runs the first time
void AutoTurn::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutoTurn::Execute()
{
	driveTrain->AutoDrive(0, 0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoTurn::IsFinished()
{
	if ( driveTrain->GetGyroAngle() < 5 ) {
		return true;
	}
	else {
		return false;
	}
}

// Called once after isFinished returns true
void AutoTurn::End()
{
	driveTrain->AutoDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoTurn::Interrupted()
{

}
