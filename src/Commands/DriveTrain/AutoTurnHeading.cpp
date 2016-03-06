#include "AutoTurnHeading.h"

AutoTurnHeading::AutoTurnHeading(float speed)
{
	Requires(driveTrain);
	m_headingChange = 0;
	m_actualTolerance = 1.0;
	m_speed = speed;
}

// Called just before this Command runs the first time
void AutoTurnHeading::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutoTurnHeading::Execute()
{
	m_headingChange = fabs(driveTrain->GetInitialHeading() - driveTrain->GetFusedHeading());

	if(driveTrain->GetInitialHeading() < 180)
	{
		if(m_headingChange < m_headingSetpoint)
		{
			driveTrain->Turn(-m_speed);
		}
		else
		{
			driveTrain->Turn(m_speed);
		}
	}
	else
	{
		if(m_headingChange > m_headingSetpoint || m_headingChange < 1.0)
		{
			driveTrain->Turn(m_speed);
		}
		else
		{
			driveTrain->Turn(-m_speed);
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AutoTurnHeading::IsFinished()
{
	printf("Initial Fused Heading - %f\t Current Fused Heading - %f\n", driveTrain->GetInitialHeading(), driveTrain->GetFusedHeading());
	return ((driveTrain->GetInitialHeading() - m_actualTolerance) < m_headingChange
			&& m_headingChange < (driveTrain->GetInitialHeading() + m_actualTolerance))
			|| driveTrain->InAuto() == false;
}

// Called once after isFinished returns true
void AutoTurnHeading::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoTurnHeading::Interrupted()
{

}
