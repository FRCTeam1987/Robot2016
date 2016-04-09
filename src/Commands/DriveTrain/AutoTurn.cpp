#include "AutoTurn.h"

AutoTurn::AutoTurn(double angle, bool reset, float averageAngleTolerance, float baseTurnSpeed, float baseAdjustSpeed, float actualAngleTolerance, bool useAzimuth)
{
	Requires(driveTrain);
	m_angle = angle;
	m_turnAngleAdjust = 0;
	m_clockWise = true;
	m_reset = reset;
	m_headingChange = 0;
	m_baseTurnSpeed = baseTurnSpeed;
	m_adjustSpeed = baseAdjustSpeed;
	m_averageTolerance = averageAngleTolerance;
	m_actualTolerance = actualAngleTolerance;
	m_useAzimuth = useAzimuth;

//	for(int i=0; i<SAMPLE_SIZE; i++)
//	{
//		m_angleSamples[i] = 0;
//	}
	m_angleAverage = 0;
}

void AutoTurn::setAngle(double angle)
{
	m_angle = angle;
}

void AutoTurn::Initialize()
{
	m_angleAverage = 0;

	if(m_reset){
		driveTrain->ResetHeadingOffset();
	}

	if(m_useAzimuth == true)
	{
		m_angle = driveTrain->GetAzimuth();
		printf("Azimuth in autoTurn = %f\n", m_angle);

		if(m_angle < 0)
		{
			m_angle += 360;
		}
	}


	if(m_angle < 180)
	{
		m_clockWise = true;
		if(m_useAzimuth == true)
		{
			m_angle += .5;
		}
	}
	else
	{
		m_clockWise = false;
		if(m_useAzimuth == true)
		{
			m_angle -= .5;
		}
	}

	printf("Clockwise = %s\t Setpoint is = %f\n", (m_clockWise ? "True" : "False") ,m_angle);

	driveTrain->SetBrake();
}

void AutoTurn::Execute()
{
	m_headingChange = driveTrain->GetHeadingChange();

	if(m_angle < 180)
	{
		m_turnAngleAdjust = m_adjustSpeed * fabs(m_angle - m_headingChange);
	}
	else
	{
		m_turnAngleAdjust = m_adjustSpeed * fabs(m_headingChange - m_angle);
	}

	//Old Version of the stuff below this
//	if(m_clockWise)
//	{
//		driveTrain->GetHeadingChange() > 359 ? m_headingChange = 0 : m_headingChange = driveTrain->GetHeadingChange();
//
//		if(m_headingChange < m_angle)
//		{
//			driveTrain->Turn(-(m_baseTurnSpeed + m_turnAngleAdjust));
//		}
//		else
//		{
//			driveTrain->Turn((m_baseTurnSpeed + m_turnAngleAdjust));
//		}
//	}
//	else
//	{
//		if(m_headingChange > m_angle || m_headingChange < 1.0)
//		{
//			driveTrain->Turn((m_baseTurnSpeed + m_turnAngleAdjust));
//		}
//		else
//		{
//			driveTrain->Turn(-(m_baseTurnSpeed + m_turnAngleAdjust));
//		}
//	}

	if(m_clockWise)
	{
		driveTrain->GetHeadingChange() > 359 ? m_headingChange = 0 : m_headingChange = driveTrain->GetHeadingChange();

		if(m_headingChange < m_angle - m_actualTolerance)
		{
			driveTrain->Turn(-(m_baseTurnSpeed + m_turnAngleAdjust));
		}
		else if(m_headingChange > m_angle + m_actualTolerance)
		{
			driveTrain->Turn((m_baseTurnSpeed + m_turnAngleAdjust));
		}
		else
		{
			driveTrain->Turn(0);
		}
	}
	else
	{
		if(m_headingChange > m_angle + m_actualTolerance || m_headingChange < 10.0)
		{
			driveTrain->Turn((m_baseTurnSpeed + m_turnAngleAdjust));
		}
		else if(m_headingChange < m_angle - m_actualTolerance)
		{
			driveTrain->Turn(-(m_baseTurnSpeed + m_turnAngleAdjust));
		}
		else
		{
			driveTrain->Turn(0);
		}
	}
}

bool AutoTurn::IsFinished()
{
//	if(m_angleSamples[SAMPLE_SIZE-1] == 0)
//	{
//		for(int i=0; i<SAMPLE_SIZE; i++)
//		{
//			m_angleSamples[i] = m_headingChange;
//		}
//	}
//
//	for(int i = SAMPLE_SIZE-1; i>0; i--)
//	{
//		m_angleSamples[i] = m_angleSamples[i-1];
//	}
//
//	m_angleSamples[0] = m_headingChange;
//	m_angleAverage = 0;
//
//	for(int i = 0; i<SAMPLE_SIZE; i++)
//	{
//		m_angleAverage += m_angleSamples[i];
//	}
//
//	m_angleAverage /= SAMPLE_SIZE;

	m_angleAverage -= m_angleAverage / SAMPLE_SIZE;

	m_angleAverage += driveTrain->GetHeadingChange() / SAMPLE_SIZE;

	printf("m_angleAverage = %f\t Current Angle = %f\n", m_angleAverage, driveTrain->GetHeadingChange());

	SmartDashboard::PutNumber("Please", driveTrain->GetHeadingChange());

//	return (m_angle - m_averageTolerance) < m_angleAverage
//		&& m_angleAverage < (m_angle + m_averageTolerance)
//		&& (m_angle - m_actualTolerance) < m_headingChange
//		&& m_headingChange < (m_angle + m_actualTolerance);

	return (m_angleAverage - m_averageTolerance) < m_headingChange
		&& m_headingChange < (m_angleAverage + m_averageTolerance)
		&& (m_angle - m_actualTolerance) < m_headingChange
		&& m_headingChange < (m_angle + m_actualTolerance);

//	return driveTrain->GetHeadingChange() <= (m_angle + m_tolerance)
//		&& driveTrain->GetHeadingChange() >= (m_angle - m_tolerance);
}

void AutoTurn::End()
{
	SmartDashboard::PutNumber("Turn Degrees", driveTrain->GetHeadingChange());
	SmartDashboard::PutNumber("Turn Degree Average", m_angleAverage);
	printf("Set Point = %f\t Current Angle = %f\n", m_angle, m_headingChange);
	driveTrain->Disable();
	driveTrain->Turn(0);
	driveTrain->SetCoast();
}

void AutoTurn::Interrupted()
{

	driveTrain->Disable();
	driveTrain->SetCoast();
}
