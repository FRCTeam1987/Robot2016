#include "AutoTurnSmallAngle.h"

AutoTurnSmallAngle::AutoTurnSmallAngle(float angleSetpoint, bool reset, bool useAzimuth)
{
	Requires(driveTrain);

	m_angleSetpoint = angleSetpoint;
	m_reset = reset;
	m_azimuth = useAzimuth;
	m_turnSpeed = MIN_TURN_SPEED;
	m_currentAngle = 0;
	m_lastAngle = 0;
	m_clockWise = true;
}

void AutoTurnSmallAngle::Initialize()
{
	m_turnSpeed = MIN_TURN_SPEED;
	m_currentAngle = 0;
	m_lastAngle = 0;


	if(m_angleSetpoint < 1005 && m_angleSetpoint > 1000)
	{
		m_angleSetpoint = SmartDashboard::GetNumber("Small Angle", 0);

	}

	if(m_reset || m_azimuth)
	{
		driveTrain->ResetHeadingOffset();
	}

	if(m_azimuth == true)
	{
		m_angleSetpoint = driveTrain->GetAzimuth();

		printf("Azimuth in AutoTurnSmallAngle = %f\n", m_angleSetpoint);

		if(m_angleSetpoint < 0)
		{
			m_angleSetpoint += 360;
		}
		else if(m_angleSetpoint > 360)
		{
			m_angleSetpoint -=360;
		}
	}

	if(m_angleSetpoint < 180)
	{
		m_clockWise = true;
		if(m_azimuth == true)
		{
			m_angleSetpoint -= 1.0;
			printf("Adding in clockwise offset\n");
		}
		m_turnSpeed = -m_turnSpeed;
	}
	else
	{
		m_clockWise = false;
		if(m_azimuth == true)
		{
			m_angleSetpoint -= .5;
			printf("Adding in counterclockwise offset\n");
		}

	}

	driveTrain->SetBrake();

	printf("Clockwise = %s\t Setpoint is = %f\n", (m_clockWise ? "True" : "False") , m_angleSetpoint);
}

void AutoTurnSmallAngle::Execute()
{
	m_currentAngle = driveTrain->GetHeadingChange();

	bool m_isMoving = isMoving(fabs(m_currentAngle - m_lastAngle));

	if( m_isMoving == false)
	{
		if(m_clockWise == false)
		{
			m_turnSpeed += TURN_SPEED_INCREMENT;
		}
		else
		{
			m_turnSpeed -= TURN_SPEED_INCREMENT;
		}
	}

	driveTrain->AutoDrive(0, m_turnSpeed);

	m_lastAngle = m_currentAngle;

	printf("Setpoint = %f\t Angle = %f\t Last Angle = %f\t Clockwise = %s\t Turn Speed %f\n", m_angleSetpoint, m_currentAngle, m_lastAngle, (m_clockWise ? "True" : "False"), m_turnSpeed);
}

bool AutoTurnSmallAngle::IsFinished()
{
	return (m_angleSetpoint - ANGLE_TOLERANCE) < m_currentAngle
			&& m_currentAngle < (m_angleSetpoint + ANGLE_TOLERANCE);
}

void AutoTurnSmallAngle::End()
{
	driveTrain->AutoDrive(0,0);
}

void AutoTurnSmallAngle::Interrupted()
{
	driveTrain->AutoDrive(0,0);
}

bool AutoTurnSmallAngle::isMoving(float angleChange)
{
	return angleChange > MIN_ANGLE_CHANGE;
}
