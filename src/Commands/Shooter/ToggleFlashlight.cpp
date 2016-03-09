#include "ToggleFlashlight.h"

ToggleFlashlight::ToggleFlashlight()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(shooter);
}

// Called just before this Command runs the first time
void ToggleFlashlight::Initialize()
{
	shooter->ToggleFlashlight();
}

// Called repeatedly when this Command is scheduled to run
void ToggleFlashlight::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ToggleFlashlight::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ToggleFlashlight::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleFlashlight::Interrupted()
{

}
