#include "LightsOff.h"

LightsOff::LightsOff()
{
	Requires(lights);
}

// Called just before this Command runs the first time
void LightsOff::Initialize()
{
	lights->Off();
}

// Called repeatedly when this Command is scheduled to run
void LightsOff::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool LightsOff::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void LightsOff::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LightsOff::Interrupted()
{

}
