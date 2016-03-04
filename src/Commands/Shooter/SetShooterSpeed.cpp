#include "SetShooterSpeed.h"
#include "../../RobotMap.h"

SetShooterSpeed::SetShooterSpeed(float rpm)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(shooter);
	m_rpm = rpm;
	SetTimeout(5);
	for(int i=0; i<10; i++)
	{
		m_rpmSamples[i] = 0;
	}
	m_rpmAverage = 0;
}

// Called just before this Command runs the first time
void SetShooterSpeed::Initialize()
{
	shooter->EnableWheel();
	shooter->SetWheel(m_rpm);
	if(m_rpm == 0)
	{
		shooter->DisableWheel();
	}
}

// Called repeatedly when this Command is scheduled to run
void SetShooterSpeed::Execute()
{
//	printf("Shooter Speed %f\n", shooter->GetRPM());
	std::cout << " RPM: " << shooter->GetRPM() << " Encoder Velocity: " << shooter->GetEncoderVel() << std::endl;
	SmartDashboard::PutNumber("Shooter - RPM", (double)shooter->GetRPM());
	SmartDashboard::PutNumber("Shooter - Encoder", (double)shooter->GetEncoderVel());
}

// Make this return true when this Command no longer needs to run execute()
bool SetShooterSpeed::IsFinished()
{
	for(int i = 9; i>0; i--)
	{
		m_rpmSamples[i] = m_rpmSamples[i-1];
	}

	m_rpmSamples[0] = shooter->GetRPM();
	m_rpmAverage = 0;

	for(int i = 0; i<10; i++)
	{
		m_rpmAverage += m_rpmSamples[i];
	}

	m_rpmAverage /= 10;

	return (m_rpm - RPM_TOLERANCE < m_rpmAverage && m_rpmAverage < m_rpm + RPM_TOLERANCE) || IsTimedOut();
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
