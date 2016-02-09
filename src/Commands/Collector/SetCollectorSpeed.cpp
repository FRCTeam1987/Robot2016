#include "SetCollectorSpeed.h"

SetCollectorSpeed::SetCollectorSpeed(float speed)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(collector);
	m_speed = speed;
}

// Called just before this Command runs the first time
void SetCollectorSpeed::Initialize()
{
	collector->RunRoller(m_speed);
}

// Called repeatedly when this Command is scheduled to run
void SetCollectorSpeed::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SetCollectorSpeed::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SetCollectorSpeed::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetCollectorSpeed::Interrupted()
{
	collector->RunRoller(0);
}
