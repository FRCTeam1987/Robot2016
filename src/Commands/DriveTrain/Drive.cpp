#include "Drive.h"
#include "../../Subsystems/DriveTrain.h"

#include <iomanip>

Drive::Drive()
{
	Requires(driveTrain);
}

// Called just before this Command runs the first time
void Drive::Initialize()
{

//	driveTrain->ResetGyro();
}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute()
{
//	printf("X:%6.3f  Y:%6.3f  Z:%6.3f\n",
//			driveTrain->GetVelocityX(),
//			driveTrain->GetVelocityY(),
//			driveTrain->GetVelocityZ());
	driveTrain->DriveArcade(oi->getStick());
	//printf("Roll: %6.3f\n", driveTrain->GetRoll());
}

// Make this return true when this Command no longer needs to run execute()
bool Drive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Drive::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Drive::Interrupted()
{

}
