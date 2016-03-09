#include "Rainbow.h"

Rainbow::Rainbow()
{

}


// Called just before this Command runs the first time
void Rainbow::Initialize()
{
	lights->Rainbow();
}

// Called repeatedly when this Command is scheduled to run
void Rainbow::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool Rainbow::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void Rainbow::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Rainbow::Interrupted()
{

}
