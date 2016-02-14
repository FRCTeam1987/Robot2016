#include "WaitForPitch.h"

WaitForPitch::WaitForPitch(float setPitch, double speed)
{
	Requires(driveTrain);
	targetPitch=setPitch;
	motorSpeed=speed;
}

// Called just before this Command runs the first time
void WaitForPitch::Initialize()
{
	driveTrain->ResetGyro();
	driveTrain->ResetLeftEncoder();
	driveTrain->setPID(-0.06, -0.004, 0.0);
	driveTrain->SetAutoSpeed(motorSpeed);
	driveTrain->SetAutoMode(driveTrain->DRIVE_STRAIGHT);
	driveTrain->SetOffset(0.0);
	driveTrain->Enable();
}

// Called repeatedly when this Command is scheduled to run
void WaitForPitch::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool WaitForPitch::IsFinished()
{
	return driveTrain->GetRoll() <= targetPitch + 1 && driveTrain->GetRoll() >= targetPitch - 1;   //using roll, not pitch, because reasons
}

// Called once after isFinished returns true
void WaitForPitch::End()
{
	driveTrain->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WaitForPitch::Interrupted()
{
	driveTrain->Disable();
}
