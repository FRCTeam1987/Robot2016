#include "BlinkLights.h"

BlinkLights::BlinkLights()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void BlinkLights::Initialize()
{
	lights->Flash(Lights::COLOR::RED);
}

// Called repeatedly when this Command is scheduled to run
void BlinkLights::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool BlinkLights::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void BlinkLights::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BlinkLights::Interrupted()
{

}
