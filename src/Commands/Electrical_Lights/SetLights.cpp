#include "SetLights.h"

SetLights::SetLights(Lights::COLOR c)
{
	m_color = c;
}


// Called just before this Command runs the first time
void SetLights::Initialize()
{
	lights->Set(m_color);
}

// Called repeatedly when this Command is scheduled to run
void SetLights::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SetLights::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SetLights::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetLights::Interrupted()
{

}
