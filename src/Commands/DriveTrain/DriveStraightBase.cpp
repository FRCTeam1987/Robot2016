#include "DriveStraightBase.h"

DriveStraightBase::DriveStraightBase(double speed)
{
	Requires(driveTrain);
	m_speed = speed;
}

// Called just before this Command runs the first time
void DriveStraightBase::Initialize()
{
	driveTrain->setPID(-0.06, -0.004, 0.0);
	driveTrain->SetAutoSpeed(m_speed);
	driveTrain->SetAutoMode(driveTrain->DRIVE_STRAIGHT);

	driveTrain->SetOffset(0.0);
	driveTrain->Enable();
	driveTrain->ResetGyro();
	driveTrain->ResetLeftEncoder();
}

// Called repeatedly when this Command is scheduled to run
void DriveStraightBase::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraightBase::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveStraightBase::End()
{
	driveTrain->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveStraightBase::Interrupted()
{
	driveTrain->Disable();
}
