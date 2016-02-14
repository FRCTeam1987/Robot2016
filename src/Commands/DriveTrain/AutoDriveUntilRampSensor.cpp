#include "AutoDriveUntilRampSensor.h"

AutoDriveUntilRampSensor::AutoDriveUntilRampSensor(float speed)
{
	Requires(driveTrain);
	m_speed = speed;
}

// Called just before this Command runs the first time
void AutoDriveUntilRampSensor::Initialize()
{
//	driveTrain->SetAutoMode(DriveTrain::DRIVE_STRAIGHT);
//	driveTrain->SetAutoSpeed(m_speed);
	driveTrain->ResetGyro();
//	driveTrain->Enable();
}

// Called repeatedly when this Command is scheduled to run
void AutoDriveUntilRampSensor::Execute()
{
	if (359 > driveTrain->GetGyroAngle()) {
		driveTrain->AutoDrive(-m_speed, 0.4);
	}
	if (1 > driveTrain->GetGyroAngle()) {
		driveTrain->AutoDrive(-m_speed, -0.4);
	}
	else {
		driveTrain->AutoDrive(-m_speed, 0);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDriveUntilRampSensor::IsFinished()
{
	return driveTrain->getRampSensor();
}

// Called once after isFinished returns true
void AutoDriveUntilRampSensor::End()
{
//	driveTrain->Disable();
	driveTrain->AutoDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDriveUntilRampSensor::Interrupted()
{
	driveTrain->AutoDrive(0, 0);
//	driveTrain->Disable();
}
