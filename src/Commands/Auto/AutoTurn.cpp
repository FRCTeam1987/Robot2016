#include "AutoTurn.h"

AutoTurn::AutoTurn(double setpoint)
{
	Requires(driveTrain);
	m_setpoint = setpoint;
}

void AutoTurn::Initialize()
{
	driveTrain->setPID(-0.012, -0.00001, -0.01875);
	driveTrain->SetAutoMode(driveTrain->AUTO_TURN);

	driveTrain->SetSetpoint(m_setpoint);
	driveTrain->Enable();
	driveTrain->ResetGyro();
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
