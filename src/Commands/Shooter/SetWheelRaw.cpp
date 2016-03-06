#include "SetWheelRaw.h"

SetWheelRaw::SetWheelRaw(float speed)
{
	Requires(shooter);
	m_speed = speed;
}

// Called just before this Command runs the first time
void SetWheelRaw::Initialize()
{
	shooter->SetWheelRaw(m_speed);
}

// Called repeatedly when this Command is scheduled to run
void SetWheelRaw::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SetWheelRaw::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SetWheelRaw::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetWheelRaw::Interrupted()
{

}
