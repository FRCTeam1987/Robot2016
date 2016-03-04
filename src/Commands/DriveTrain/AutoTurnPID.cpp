#include "AutoTurnPID.h"

AutoTurnPID::AutoTurnPID(double angle, bool reset)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveTrain);
	m_angle = angle;
	m_reset = reset;
}

void AutoTurnPID::setAngle(double angle)
{
	m_angle = angle;
}

// Called just before this Command runs the first time
void AutoTurnPID::Initialize()
{
	if(m_reset){
		driveTrain->ResetHeadingOffset();
	}

	SmartDashboard::PutString("Current_Command", "AutoTurnPID");
	double m_speed = SmartDashboard::GetNumber("Drive_Speed", 0.01);
	m_angle = SmartDashboard::GetNumber("Turn_Angle", 60);
	double m_P = SmartDashboard::GetNumber("Turn_P", -0.10000);
	double m_I = SmartDashboard::GetNumber("Turn_I", -0.00000);
	double m_D = SmartDashboard::GetNumber("Turn_D", -0.00002);
	double m_F = SmartDashboard::GetNumber("Turn_F",  0.00000);

//	driveTrain->setPIDf(m_P, m_I, m_D, m_F);
	driveTrain->SetAutoSpeed(0); //Since we are just turning, we don't want to drive forward or backwards.

	driveTrain->SetSetpoint(m_angle);
	driveTrain->Enable();

	driveTrain->setPIDf(m_P, m_I, m_D, m_F);

	if(driveTrain->GetPIDError() <= 5)
	{
		driveTrain->setPIDf(-0.1, -0.001, 0, 0.0);
	}
	else if(driveTrain->GetPIDError() <= 10)
	{
		driveTrain->setPIDf(-0.068, 0, 0, 0.8);
	}
	else if(driveTrain->GetPIDError() <= 45)
	{
		driveTrain->setPIDf(-0.018, 0, 0, 0.5);
	}
	else if(driveTrain->GetPIDError() <= 90)
	{
		driveTrain->setPIDf(-0.011, 0, 0, 0.6);
	}

	//driveTrain->Enable();
}

void AutoTurnPID::Execute()
{
	printf("HeadingChange - %f, Target- %f \n", driveTrain->GetHeadingChange(), m_angle);

}

// Make this return true when this Command no longer needs to run execute()
bool AutoTurnPID::IsFinished()
{
	return false;
	//return driveTrain->GetHeadingChange() <= (m_angle + TURN_ANGLE_TOLERANCE)
	//	&& driveTrain->GetHeadingChange() >= (m_angle - TURN_ANGLE_TOLERANCE);
}

// Called once after isFinished returns true
void AutoTurnPID::End()
{
	driveTrain->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoTurnPID::Interrupted()
{
	driveTrain->Disable();
}
