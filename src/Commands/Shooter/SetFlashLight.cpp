#include "SetFlashLight.h"

SetFlashLight::SetFlashLight(bool onOff)
{
	Requires(shooter);
	m_onOff = onOff;
}

// Called just before this Command runs the first time
void SetFlashLight::Initialize()
{
	shooter->SetFlashLight(m_onOff);
}

// Called repeatedly when this Command is scheduled to run
void SetFlashLight::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SetFlashLight::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SetFlashLight::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetFlashLight::Interrupted()
{

}
