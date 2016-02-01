#include "AutoTurn.h"

AutoTurn::AutoTurn(double setpoint)
{
	Requires(driveTrain);
	m_setpoint = setpoint;
}

void AutoTurn::Initialize()
{
	// 60 degrees PID: -0.015, 0.0, -0.025
    // driveTrain->setPID(-0.02, 0.0, -0.02);
	driveTrain->setPID(-0.012, 0.0, -0.0);

	driveTrain->ResetGyro();
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
