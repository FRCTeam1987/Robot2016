#include "AutoTurnSmallAngle.h"

AutoTurnSmallAngle::AutoTurnSmallAngle(float angleSetpoint, bool reset, bool useAzimuth, float minAngleChange, float angleTolerance)
{
	Requires(driveTrain);

	m_minAngleChange = minAngleChange;
	m_angleTolerance = angleTolerance;
	m_angleSetpoint = angleSetpoint;
	m_reset = reset;
	m_azimuth = useAzimuth;
	m_turnSpeed = MIN_TURN_SPEED;
	m_currentAngle = 0;
	m_lastAngle = 0;
	m_clockWise = true;
//	m_microseconds = 0;
//	m_lastMicroseconds = 0;
	m_degreesPerSecond = 0;
	m_isSlow = false;
}

void AutoTurnSmallAngle::Initialize()
{
	m_turnSpeed = MIN_TURN_SPEED;
	m_currentAngle = 0;
	m_lastAngle = 0;
//	m_microseconds = std::chrono::high_resolution_clock::now();
	m_degreesPerSecond = 0;
	m_isSlow = false;

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
			m_angleSetpoint -= 1.5; // +2.0 for close
			printf("Adding in clockwise offset\n");
		}
		m_turnSpeed = -m_turnSpeed;
	}
	else
	{
		m_clockWise = false;
		if(m_azimuth == true)
		{
			m_angleSetpoint -= 0.5; // -.5 for close
			printf("Adding in counterclockwise offset\n");
		}

	}

	driveTrain->SetBrake();

	printf("Clockwise = %s\t Setpoint is = %f\n", (m_clockWise ? "True" : "False") , m_angleSetpoint);
}

void AutoTurnSmallAngle::Execute()
{
	m_currentAngle = driveTrain->GetHeadingChange();

//	m_microseconds = std::chrono::high_resolution_clock::now();

	bool m_isMoving = isMoving(fabs(m_currentAngle - m_lastAngle));

	if(m_isMoving == false) //&& m_isSlow == false)
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
	else if(m_isMoving == true && m_angleSetpoint > 2)
	{
		if(m_clockWise == true)
		{
			if(m_angleSetpoint - (m_angleTolerance + 2) < m_currentAngle && m_currentAngle < 358)
			{
//				m_isSlow = true;
				if(m_turnSpeed < 0)
					m_turnSpeed += 0.1;
				printf("Reducing speed\n");
			}
		}
		else
		{
			if(m_currentAngle < (m_angleSetpoint + m_angleTolerance + 2) && m_currentAngle > 2)
			{
//				m_isSlow = true;
				if(m_turnSpeed > 0)
					m_turnSpeed -= 0.1;
				printf("Reducing speed\n");
			}
		}
	}

	driveTrain->AutoDrive(0, m_turnSpeed);

	m_degreesPerSecond = (m_currentAngle - m_lastAngle)/(0.02);

	printf("Setpoint = %f\t Angle = %f\t Last Angle = %f\t Clockwise = %s\t Turn Speed %f\t Degrees/Second %f\n", m_angleSetpoint, m_currentAngle, m_lastAngle, (m_clockWise ? "True" : "False"), m_turnSpeed, m_degreesPerSecond);

	m_lastAngle = m_currentAngle;

//	m_lastMicroseconds = m_microseconds;
}

bool AutoTurnSmallAngle::IsFinished()
{
	if(m_clockWise == true)
	{
		return (m_angleSetpoint - m_angleTolerance) < m_currentAngle && m_currentAngle < 358;
	}
	else
	{
		return m_currentAngle < (m_angleSetpoint + m_angleTolerance) && m_currentAngle > 2;
	}

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
	return angleChange > m_minAngleChange;
}
