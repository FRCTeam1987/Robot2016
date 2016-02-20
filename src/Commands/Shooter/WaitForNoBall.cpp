#include "WaitForNoBall.h"

WaitForNoBall::WaitForNoBall()
{
	SetTimeout(2.0);
}

// Called just before this Command runs the first time
void WaitForNoBall::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void WaitForNoBall::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool WaitForNoBall::IsFinished()
{
	if(IsTimedOut())
	{
		shooter->setHasTimedOut(true);
		printf("No ball has timed out\n");
	}
	return !shooter->HasBall() || IsTimedOut();
}

// Called once after isFinished returns true
void WaitForNoBall::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WaitForNoBall::Interrupted()
{

}
