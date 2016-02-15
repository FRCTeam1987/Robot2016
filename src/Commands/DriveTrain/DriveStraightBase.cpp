#include "DriveStraightBase.h"
#include "RobotMap.h"

DriveStraightBase::DriveStraightBase(double speed)
{
	Requires(driveTrain);
	m_speed = speed;
}

// Called just before this Command runs the first time
void DriveStraightBase::Initialize()
{
	if(CommandBase::IsPracticeBot())
	{
		driveTrain->setPID(DRIVE_STRAIGHT_P_PRAC, DRIVE_STRAIGHT_I_PRAC, DRIVE_STRAIGHT_D_PRAC);
	}
	else
	{
		driveTrain->setPID(DRIVE_STRAIGHT_P_COMP, DRIVE_STRAIGHT_I_COMP, DRIVE_STRAIGHT_D_COMP);
	}
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
