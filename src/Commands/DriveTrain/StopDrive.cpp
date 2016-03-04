#include "StopDrive.h"

StopDrive::StopDrive()
{
	Requires(driveTrain);
}

// Called just before this Command runs the first time
void StopDrive::Initialize()
{
	double m_speed = SmartDashboard::GetNumber("Stop_Speed", -0.00002);
	double m_time = SmartDashboard::GetNumber("Stop_Time",  0.00000);
	driveTrain->AutoDrive(m_speed, 0);
	SetTimeout(m_time);
}

// Called repeatedly when this Command is scheduled to run
void StopDrive::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool StopDrive::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void StopDrive::End()
{
	driveTrain->AutoDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StopDrive::Interrupted()
{
	driveTrain->AutoDrive(0, 0);
}
