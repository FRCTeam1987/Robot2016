#include "DriveByEncoder.h"

DriveByEncoder::DriveByEncoder()
{
	Requires(driveTrain);
}

// Called just before this Command runs the first time
void DriveByEncoder::Initialize()
{
	driveTrain->ResetLeftEncoder();
	printf("Reset Encoder \n");
}

// Called repeatedly when this Command is scheduled to run
void DriveByEncoder::Execute()
{
	driveTrain->AutoDrive(0.5, 0);
	printf("Encoder - %f\n", driveTrain->GetLeftEncoderDistance());
}

// Make this return true when this Command no longer needs to run execute()
bool DriveByEncoder::IsFinished()
{
	if(driveTrain->GetLeftEncoderDistance() >= 120) {
		return true;
	}
	else {
		return false;
	}
}

// Called once after isFinished returns true
void DriveByEncoder::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveByEncoder::Interrupted()
{
	driveTrain->AutoDrive(0, 0);
}
