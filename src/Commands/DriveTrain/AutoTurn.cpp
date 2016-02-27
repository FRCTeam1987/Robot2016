#include "AutoTurn.h"

AutoTurn::AutoTurn(double angle)
{
	Requires(driveTrain);
	m_angle = angle;
	m_turnAngleAdjust = 0;
}

void AutoTurn::Initialize()
{
	driveTrain->ResetGyro();
}

void AutoTurn::Execute()
{

	m_turnAngleAdjust = AUTO_ADJUST_TURN_SPEED * fabs(driveTrain->GetGyroAngle() - m_angle);

	if(driveTrain->GetGyroAngle() > m_angle)
	{
		printf("Angle - %f, Other - %f IF\n", driveTrain->GetGyroAngle(), m_turnAngleAdjust);
		driveTrain->AutoDrive(0, (AUTO_BASE_TURN_SPEED + m_turnAngleAdjust));
	}
	else if(driveTrain->GetGyroAngle() < m_angle)
	{
		printf("Angle - %f, Other - %f ELSEIF\n", driveTrain->GetGyroAngle(), m_turnAngleAdjust);
		driveTrain->AutoDrive(0, -(AUTO_BASE_TURN_SPEED + m_turnAngleAdjust));
	}
	else
	{
		printf("Angle - %f IF\n", driveTrain->GetGyroAngle());
		driveTrain->AutoDrive(0, 0);
	}
}

bool AutoTurn::IsFinished()
{
	return driveTrain->GetGyroAngle() <= (m_angle + PITCH_ANGLE_TOLERANCE)
		&& driveTrain->GetGyroAngle() >= (m_angle - PITCH_ANGLE_TOLERANCE);
}

void AutoTurn::End()
{
	driveTrain->Disable();
}

void AutoTurn::Interrupted()
{
	driveTrain->Disable();
}
