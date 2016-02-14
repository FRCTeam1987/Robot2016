#include "AutoEncoderDrive.h"

AutoEncoderDrive::AutoEncoderDrive(float distance)
{
	Requires(driveTrain);
	m_distance = distance;
}

// Called just before this Command runs the first time
void AutoEncoderDrive::Initialize()
{
	driveTrain->ResetLeftEncoder();
	driveTrain->Enable();
}

// Called repeatedly when this Command is scheduled to run
void AutoEncoderDrive::Execute()
{
//	driveTrain->AutoDrive(-0.45, 0);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoEncoderDrive::IsFinished()
{
	if(driveTrain->GetLeftEncoderDistance() < m_distance) { //THE DISTANCE HAS NOT BEEN SET
		return true;
	}
	else {
		return false;
	}
}

// Called once after isFinished returns true
void AutoEncoderDrive::End()
{
	driveTrain->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoEncoderDrive::Interrupted()
{
	driveTrain->Disable();
}
