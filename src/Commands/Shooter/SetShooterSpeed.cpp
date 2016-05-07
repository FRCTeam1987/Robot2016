#include "SetShooterSpeed.h"
#include "../../RobotMap.h"

SetShooterSpeed::SetShooterSpeed(float rpm)
{
	Requires(shooter);
	m_rpm = rpm;
	SetTimeout(5);
//	for(int i=0; i<m_sampleSize; i++)
//	{
//		m_rpmSamples[i] = 0;
//	}
	m_rpmAverage = 0;
}

void SetShooterSpeed::Initialize()
{
	m_rpmAverage = 0;
	shooter->EnableWheel();
	shooter->SetWheel(m_rpm);
	if(m_rpm == 0)
	{
		shooter->DisableWheel();
		printf("Disabling shooter wheel PID\n");
	}
}

void SetShooterSpeed::Execute()
{
//	printf("Shooter Speed %f\n", shooter->GetRPM());
//	std::cout << " RPM: " << shooter->GetRPM() << " Encoder Velocity: " << shooter->GetEncoderVel() << std::endl;
	SmartDashboard::PutNumber("Shooter - RPM", (double)shooter->GetRPM());
	SmartDashboard::PutNumber("Shooter - Encoder", (double)shooter->GetEncoderVel());
}

bool SetShooterSpeed::IsFinished()
{
	//Sampling with array
//	for(int i = m_sampleSize-1; i>0; i--)
//	{
//		m_rpmSamples[i] = m_rpmSamples[i-1];
//	}
//
//	m_rpmSamples[0] = shooter->GetRPM();
//	m_rpmAverage = 0;
//
//	for(int i = 0; i<m_sampleSize; i++)
//	{
//		m_rpmAverage += m_rpmSamples[i];
//	}
//
//	m_rpmAverage /= m_sampleSize;

	if(m_rpm == 0)
	{
		return true;
	}

	m_rpmAverage -= m_rpmAverage / m_sampleSize;

	m_rpmAverage += shooter->GetRPM() / m_sampleSize;

	printf("m_rpmAverage - %f\t ", m_rpmAverage);
	shooter->PrintStuff();

	return (m_rpm - RPM_TOLERANCE < m_rpmAverage && m_rpmAverage < m_rpm + RPM_TOLERANCE) || IsTimedOut();
}

// Called once after isFinished returns true
void SetShooterSpeed::End()
{
	printf("SetShooterSpeed ended\n");
}

void SetShooterSpeed::Interrupted()
{
	shooter->SetWheel(0);
}
