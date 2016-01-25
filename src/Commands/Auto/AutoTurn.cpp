#include "AutoTurn.h"

AutoTurn::AutoTurn(double setpoint)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveTrain);
	m_setpoint = setpoint;
}

// Called just before this Command runs the first time
void AutoTurn::Initialize()
{
	driveTrain->setPID(-0.012, -0.00001, -0.01875);
	driveTrain->SetAutoMode(driveTrain->AUTO_TURN);

	driveTrain->SetSetpoint(m_setpoint);
	driveTrain->Enable();
	driveTrain->ResetGyro();
}

// Called repeatedly when this Command is scheduled to run
void AutoTurn::Execute()
{
//	driveTrain->AutoDrive(0, 0.5);
	printf("Error - %f       Output - %f\n", (m_setpoint - driveTrain->GetGyroAngle()), driveTrain->GetOutput());
}

// Make this return true when this Command no longer needs to run execute()
bool AutoTurn::IsFinished()
{
	return driveTrain->OnTarget();
}

// Called once after isFinished returns true
void AutoTurn::End()
{
	driveTrain->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoTurn::Interrupted()
{
	driveTrain->Disable();
}
