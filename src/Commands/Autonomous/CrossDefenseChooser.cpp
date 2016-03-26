#include "CrossDefenseChooser.h"

CrossDefenseChooser::CrossDefenseChooser()
{
	obstacle_number = 0;
}

void CrossDefenseChooser::SetObstacle( int obsNum )
{
	/*
	 * Instead of passing in an int or something, it'd be great if you could pass
	 * in a sendable so that it can evaluate based off of that. I just don't know the
	 * specifics of that so sticking with an int for the example.
	 */
	obstacle_number = obsNum;
}

void CrossDefenseChooser::Initialize()
{

	switch(obstacle_number)
	{
		case 1:
			CommandObjects::RunCommand(CommandObjects::autoChevalDeFrise);
			break;
	}
}

void CrossDefenseChooser::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool CrossDefenseChooser::IsFinished()
{
	return !CommandObjects::active_command->IsRunning();
}

// Called once after isFinished returns true
void CrossDefenseChooser::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CrossDefenseChooser::Interrupted()
{

}
