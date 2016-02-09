#include "SetShooterSpeed.h"
#include "../../RobotMap.h"

SetShooterSpeed::SetShooterSpeed(float rpm)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(shooter);
	m_rpm = rpm;
}

// Called just before this Command runs the first time
void SetShooterSpeed::Initialize()
{
	shooter->SetWheel(m_rpm);
}

// Called repeatedly when this Command is scheduled to run
void SetShooterSpeed::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SetShooterSpeed::IsFinished()
{
	return m_rpm - RPM_TOLERANCE < shooter->GetRPM() && shooter->GetRPM() > m_rpm + RPM_TOLERANCE;
}

// Called once after isFinished returns true
void SetShooterSpeed::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetShooterSpeed::Interrupted()
{
	shooter->SetWheel(0);
}
