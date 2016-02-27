#include "AutoTurn.h"

AutoTurn::AutoTurn(double angle)
{
	Requires(driveTrain);
	m_angle = angle;
	m_turnAngleAdjust = 0;
	m_clockWise = true;
}

void AutoTurn::Initialize()
{
	driveTrain->ResetHeadingOffset();

	if(m_angle < 180)
	{
		m_clockWise = true;
	}
	else
	{
		m_clockWise = false;
	}
}

void AutoTurn::Execute()
{

	m_turnAngleAdjust = AUTO_ADJUST_TURN_SPEED * fabs(driveTrain->GetHeadingChange() - m_angle);

	if(m_clockWise == true)
	{
		if(driveTrain->GetHeadingChange() < m_angle)
		{
			driveTrain->AutoDrive(0, -AUTO_BASE_TURN_SPEED);
		}
		else
		{
			driveTrain->AutoDrive(0, AUTO_BASE_TURN_SPEED);
		}
	}
	else
	{
		if(driveTrain->GetHeadingChange() > m_angle || driveTrain->GetHeadingChange() < 1.0)
		{
			driveTrain->AutoDrive(0, AUTO_BASE_TURN_SPEED);
		}
		else
		{
			driveTrain->AutoDrive(0, -AUTO_BASE_TURN_SPEED);
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


}

bool AutoTurn::IsFinished()
{
	return driveTrain->GetHeadingChange() <= (m_angle + TURN_ANGLE_TOLERANCE)
		&& driveTrain->GetHeadingChange() >= (m_angle - TURN_ANGLE_TOLERANCE);
}

void AutoTurn::End()
{
	driveTrain->Disable();
}

void AutoTurn::Interrupted()
{
	driveTrain->Disable();
}
