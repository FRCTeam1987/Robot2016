#include "AutoDrive.h"

AutoDrive::AutoDrive(float speed, float turn)
{
	Requires(driveTrain);
	m_speed = speed;
	m_turn = turn;
}

// Called just before this Command runs the first time
void AutoDrive::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutoDrive::Execute()
{
	driveTrain->AutoDrive(m_speed, m_turn);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDrive::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void AutoDrive::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDrive::Interrupted()
{

}
