#include "AutoTurn.h"

AutoTurn::AutoTurn(double setpoint)
{
	Requires(driveTrain);
	m_setpoint = setpoint;
}

void AutoTurn::Initialize()
{
//	if(m_setpoint <= 30)
//	{
//		driveTrain->setPID(-0.018, 0.0, -0.01);
//	}
//	else if(m_setpoint <= 60)
//	{
//		//60 degrees PID: -0.015, 0.0, -0.025
//		driveTrain->setPID(-0.015, 0.0, -0.025);
//	}
//	else if(m_setpoint <= 90)
//	{
//		driveTrain->setPID(-0.015, 0.0, -0.0);
//	}
//	else if(m_setpoint <= 120)
//	{
//		driveTrain->setPID(-0.015, 0.0, -0.0);
//	}
//	else if(m_setpoint <= 150)
//	{
//		driveTrain->setPID(-0.015, 0.0, -0.0);
//	}
//	else if(m_setpoint <= 180)
//	{
//		driveTrain->setPID(-0.015, 0.0, -0.0);
//	}
//	driveTrain->setPID(-0.02, 0.0, -0.02);
	// TODO - Ask Lucas about the previous lines
	driveTrain->ResetGyro();
	driveTrain->setPID(-0.012, 0.0, -0.019);
	driveTrain->SetAutoMode(driveTrain->AUTO_TURN);

	driveTrain->SetOffset(0.2);
	driveTrain->SetSetpoint(m_setpoint);
	driveTrain->Enable();
}

void AutoTurn::Execute()
{
	printf("Error - %f       Output - %f\n", (m_setpoint - driveTrain->GetGyroAngle()), driveTrain->GetOutput());
}

bool AutoTurn::IsFinished()
{
	return driveTrain->OnTarget();
}

void AutoTurn::End()
{
	driveTrain->Disable();
}

void AutoTurn::Interrupted()
{
	driveTrain->Disable();
}
