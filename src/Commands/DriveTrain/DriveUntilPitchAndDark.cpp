#include "DriveUntilPitchAndDark.h"
#include "../../RobotMap.h"
#include "../PrintStuff.h"

DriveUntilPitchAndDark::DriveUntilPitchAndDark(float setPitch, float setRoll, double speed, float pitchTolerance, float rollTolerance)
{
	Requires(driveTrain);
	targetPitch = setPitch;
	targetRoll = setRoll;
	motorSpeed = speed;
	m_pitchTolerance = pitchTolerance;
	m_rollTolerance = rollTolerance;
}

// Called just before this Command runs the first time
void DriveUntilPitchAndDark::Initialize()
{
	SmartDashboard::PutString("Current_Command", "DriveUntilPitchAndDark");
	driveTrain->ResetHeadingOffset();
	driveTrain->ResetLeftEncoder();
	driveTrain->setPID(-0.06, -0.004, 0.0);
	driveTrain->SetAutoSpeed(-motorSpeed);
	driveTrain->SetAutoMode(driveTrain->DRIVE_STRAIGHT);
	driveTrain->SetOffset(0.0);
	driveTrain->Enable();
}

// Called repeatedly when this Command is scheduled to run
void DriveUntilPitchAndDark::Execute()
{
	printf(driveTrain->getRampSensor() ? "Ramp Sensor - True \t" : "Ramp Sensor - False \t");
	printf("Pitch: %f \t Roll: %f\n", driveTrain->GetRoll(), driveTrain->GetPitch());

}

// Make this return true when this Command no longer needs to run execute()
bool DriveUntilPitchAndDark::IsFinished()
{
	return driveTrain->GetRoll() <= (targetPitch + m_pitchTolerance)
			&& driveTrain->GetRoll() >= (targetPitch - m_pitchTolerance)
			&& driveTrain->GetPitch() <= (targetRoll + m_rollTolerance)
			&& driveTrain->GetPitch() >= (targetRoll - m_rollTolerance)
			&& !driveTrain->getRampSensor();
}

// Called once after isFinished returns true
void DriveUntilPitchAndDark::End()
{
	driveTrain->Disable();
	driveTrain->AutoDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveUntilPitchAndDark::Interrupted()
{
	driveTrain->Disable();
	driveTrain->AutoDrive(0, 0);
}
