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
	// driveTrain->setPID(-0.004, 0.0, 0.0);
	driveTrain->setPID(-0.01, 0.0, 0.0);

	driveTrain->ResetGyro();
	driveTrain->SetAutoMode(driveTrain->AUTO_TURN);

	// This offset value will change based on robot weight, may need to increase
	driveTrain->SetOffset(0.0);
	driveTrain->SetSetpoint(m_setpoint);
	driveTrain->Enable();
}

void AutoTurn::Execute()
{
	printf("Error - %f \t Output - %f \t Current Angle - %f\n", (driveTrain->GetGyroAngle() - m_setpoint), driveTrain->GetOutput(), driveTrain->GetGyroAngle());
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
