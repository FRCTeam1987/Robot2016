#include "DriveStraight.h"
#include "../../RobotMap.h"

DriveStraight::DriveStraight(double setpoint)
{
	Requires(driveTrain);
	m_setpoint = setpoint;
	SetTimeout(6);
}

// Called just before this Command runs the first time
void DriveStraight::Initialize()
{
	driveTrain->setPID(-0.012, 0.004, -0.023);
	driveTrain->SetAutoSpeed(AUTODRIVESTRAIGHTSPEED);
	driveTrain->SetAutoMode(driveTrain->DRIVE_STRAIGHT);

	driveTrain->SetSetpoint(m_setpoint);
	driveTrain->Enable();
	driveTrain->ResetGyro();
}

// Called repeatedly when this Command is scheduled to run
void DriveStraight::Execute()
{
	printf("Error - %f \t Output - %f\n", (m_setpoint - driveTrain->GetGyroAngle()), driveTrain->GetOutput());
}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraight::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void DriveStraight::End()
{
	driveTrain->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveStraight::Interrupted()
{
	driveTrain->Disable();
}
