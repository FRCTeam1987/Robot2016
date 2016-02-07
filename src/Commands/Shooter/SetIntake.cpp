#include "SetIntake.h"

SetIntake::SetIntake(Shooter::IntakeMode mode)
{
	Requires(shooter);
	m_mode = mode;
}

// Called just before this Command runs the first time
void SetIntake::Initialize()
{
	shooter->SetIntake(m_mode);
}

// Called repeatedly when this Command is scheduled to run
void SetIntake::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SetIntake::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SetIntake::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetIntake::Interrupted()
{
	shooter->SetIntake(Shooter::kIntakeOff);
}
