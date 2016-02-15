#include "SetDrive.h"

SetDrive::SetDrive(float speed, float angle)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveTrain);
	m_speed = speed;
	m_angle = angle;
}

// Called just before this Command runs the first time
void SetDrive::Initialize()
{
	driveTrain->AutoDrive(m_speed, m_angle);
}

// Called repeatedly when this Command is scheduled to run
void SetDrive::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SetDrive::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SetDrive::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetDrive::Interrupted()
{

}
