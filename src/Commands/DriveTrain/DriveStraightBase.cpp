#include "DriveStraightBase.h"
#include "RobotMap.h"

DriveStraightBase::DriveStraightBase(double speed, float angleSetpoint)
{
	Requires(driveTrain);
	m_speed = speed;
	m_P = 0.01;
	m_I = 0;
	m_D = 0;
	m_F = 0;
	m_angleSetpoint = angleSetpoint;
	m_reset = true;
}

// Called just before this Command runs the first time
void DriveStraightBase::Initialize()
{
	SmartDashboard::PutString("Current_Command", "DriveStraightBase");
//	m_speed = SmartDashboard::GetNumber("Drive_Speed", -0.6);
	m_P = SmartDashboard::GetNumber("Drive_P", -0.06);
	m_I = SmartDashboard::GetNumber("Drive_I", -0.004);
	m_D = SmartDashboard::GetNumber("Drive_D", 0);
	m_F = SmartDashboard::GetNumber("Drive_F", 0.6);

	if(CommandBase::IsPracticeBot())
	{
		driveTrain->setPID(DRIVE_STRAIGHT_P_PRAC, DRIVE_STRAIGHT_I_PRAC, DRIVE_STRAIGHT_D_PRAC);
	}
	else
	{
		driveTrain->setPIDf(m_P, m_I, m_D, m_F);
	}
	driveTrain->SetAutoSpeed(m_speed);
//	driveTrain->SetAutoSpeed(-0.6);
	driveTrain->SetAutoMode(driveTrain->DRIVE_STRAIGHT);

	//driveTrain->SetOffset(0.0);
	driveTrain->SetSetpoint(m_angleSetpoint);
	driveTrain->Enable();
	//driveTrain->ResetGyro();
	if(m_reset)
	{
		driveTrain->ResetHeadingOffset();
		printf("Heading Offset Reset in Base Drive\n");
	}
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
	driveTrain->AutoDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveStraightBase::Interrupted()
{
	driveTrain->Disable();
	driveTrain->AutoDrive(0, 0);
}

void DriveStraightBase::SetReset(bool reset)
{
	m_reset = reset;
}
