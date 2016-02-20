#include "ReadjustBallWithIntake.h"

ReadjustBallWithIntake::ReadjustBallWithIntake()
{
	Requires(shooter);
	SetTimeout(.2);
}

// Called just before this Command runs the first time
void ReadjustBallWithIntake::Initialize()
{
	if(shooter->getHasTimedOut())
	{
		printf("Still timed out in readjust init\n");
		shooter->SetIntake(Shooter::kIntakeReverse);
	}
}

// Called repeatedly when this Command is scheduled to run
void ReadjustBallWithIntake::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ReadjustBallWithIntake::IsFinished()
{
	if(shooter->getHasTimedOut())
		return IsTimedOut();
	else
		return true;
}

// Called once after isFinished returns true
void ReadjustBallWithIntake::End()
{
	if(shooter->getHasTimedOut())
		shooter->SetIntake(Shooter::kIntakeOff);
	shooter->setHasTimedOut(false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ReadjustBallWithIntake::Interrupted()
{

}
