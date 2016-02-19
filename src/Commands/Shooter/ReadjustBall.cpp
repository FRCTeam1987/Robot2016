#include "ReadjustBall.h"

ReadjustBall::ReadjustBall()
{
	Requires(shooter);
}

// Called just before this Command runs the first time
void ReadjustBall::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ReadjustBall::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ReadjustBall::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ReadjustBall::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ReadjustBall::Interrupted()
{

}
