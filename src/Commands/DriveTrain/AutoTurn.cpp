#include "AutoTurn.h"

AutoTurn::AutoTurn(double angle, bool reset)
{
	Requires(driveTrain);
	m_angle = angle;
	m_turnAngleAdjust = 0;
	m_clockWise = true;
	m_reset = reset;
	m_headingChange = 0;
	m_baseTurnSpeed = 0.49;
	m_adjustSpeed = .0036;
}

void AutoTurn::setAngle(double angle)
{
	m_angle = angle;
}

void AutoTurn::Initialize()
{
	if(m_reset){
		driveTrain->ResetHeadingOffset();
	}

	if(m_angle < 180)
	{
		m_clockWise = true;
	}
	else
	{
		m_clockWise = false;
	}

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

	if(m_clockWise)
	{
		driveTrain->GetHeadingChange() > 359 ? m_headingChange = 0 : m_headingChange = driveTrain->GetHeadingChange();

		if(m_headingChange < m_angle)
		{
			driveTrain->Turn(-(m_baseTurnSpeed + m_turnAngleAdjust));
		}
		else
		{
			driveTrain->Turn((m_baseTurnSpeed + m_turnAngleAdjust));
		}
	}
	else
	{
		if(m_headingChange > m_angle || m_headingChange < 1.0)
		{
			driveTrain->Turn((m_baseTurnSpeed + m_turnAngleAdjust));
		}
		else
		{
			driveTrain->Turn(-(m_baseTurnSpeed + m_turnAngleAdjust));
		}
	}

//	if(driveTrain->GetGyroAngle() > m_angle)
//	{
//		printf("Angle - %f, Other - %f IF\n", driveTrain->GetGyroAngle(), m_turnAngleAdjust);
//		driveTrain->AutoDrive(0, (AUTO_BASE_TURN_SPEED + m_turnAngleAdjust));
//	}
//	else if(driveTrain->GetGyroAngle() < m_angle)
//	{
//		printf("Angle - %f, Other - %f ELSEIF\n", driveTrain->GetGyroAngle(), m_turnAngleAdjust);
//		driveTrain->AutoDrive(0, -(AUTO_BASE_TURN_SPEED + m_turnAngleAdjust));
//	}
//	else
//	{
//		printf("Angle - %f IF\n", driveTrain->GetGyroAngle());
//		driveTrain->AutoDrive(0, 0);
//	}

	printf("HeadingChange - %f\t Target - %f\t Clockwise - %s\n", driveTrain->GetHeadingChange(), m_angle, m_clockWise ? "true" : "false");
}

bool AutoTurn::IsFinished()
{
	return driveTrain->GetHeadingChange() <= (m_angle + TURN_ANGLE_TOLERANCE)
		&& driveTrain->GetHeadingChange() >= (m_angle - TURN_ANGLE_TOLERANCE);
}

void AutoTurn::End()
{
	driveTrain->Disable();
	driveTrain->SetCoast();
}

void AutoTurn::Interrupted()
{
	driveTrain->Disable();
	driveTrain->SetCoast();
}
