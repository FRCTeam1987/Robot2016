#include "AutoDriveAfterRampSensor.h"

AutoDriveAfterRampSensor::AutoDriveAfterRampSensor(float speed)
{
	Requires(driveTrain);
	m_speed = speed;
}

// Called just before this Command runs the first time
void AutoDriveAfterRampSensor::Initialize()
{
	driveTrain->ResetGyro();
}

// Called repeatedly when this Command is scheduled to run
void AutoDriveAfterRampSensor::Execute()
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
bool AutoDriveAfterRampSensor::IsFinished()
{
	return !driveTrain->getRampSensor();
}

// Called once after isFinished returns true
void AutoDriveAfterRampSensor::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDriveAfterRampSensor::Interrupted()
{

}
