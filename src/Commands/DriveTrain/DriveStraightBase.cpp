#include "DriveStraightBase.h"
#include "RobotMap.h"

DriveStraightBase::DriveStraightBase(double speed)
{
	Requires(driveTrain);
	m_speed = speed;
	m_P = 0;
	m_I = 0;
	m_D = 0;
}

// Called just before this Command runs the first time
void DriveStraightBase::Initialize()
{
	SmartDashboard::PutString("Current_Command", "DriveStraightBase");
	m_P = SmartDashboard::GetNumber("Drive_P", -0.06);
	m_I = SmartDashboard::GetNumber("Drive_I", -0.004);
	m_D = SmartDashboard::GetNumber("Drive_D", 0);

	if(CommandBase::IsPracticeBot())
	{
		driveTrain->setPID(DRIVE_STRAIGHT_P_PRAC, DRIVE_STRAIGHT_I_PRAC, DRIVE_STRAIGHT_D_PRAC);
	}
	else
	{
		driveTrain->setPIDf(m_P, m_I, m_D, 0.6);
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
	printf("Gyro - %f  PID - %f\n", driveTrain->GetGyroAngle(), driveTrain->GetOutput());
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
