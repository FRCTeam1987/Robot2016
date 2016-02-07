#include "WaitForBall.h"

WaitForBall::WaitForBall()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(shooter);
}

// Called just before this Command runs the first time
void WaitForBall::Initialize()
{
	shooter->SetIntake(shooter->kIntakeForward);
}

// Called repeatedly when this Command is scheduled to run
void WaitForBall::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool WaitForBall::IsFinished()
{
	return shooter->HasBall();
}

// Called once after isFinished returns true
void WaitForBall::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WaitForBall::Interrupted()
{

}
