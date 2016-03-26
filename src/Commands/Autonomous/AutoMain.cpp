#include "AutoMain.h"

AutoMain::AutoMain()
{
	/*
	 * Since all of the child objects are static we just
	 * have to call this constructor once at some point.
	 * After this then we can scope into the class and
	 * utilize any of our commands.
	 */
	commandObjects = new CommandObjects();
	autoCommandObjects = new AutoCommandObjects();


	command_number = 0;
}

void AutoMain::Initialize()
{
	/*
	 * Say we want to start by driving until the ramp
	 * sensor is tripped. We can kick off our first command in the init(), then
	 * we'll have to check and see if it is done in the execute.
	 */
	CommandObjects::setBrake->Run();

	/*
	 * Here's an example of a command where we have parameters. instead
	 * of setting them in the constructor we have to have another function
	 * to set what we'll use, then we run the command with the Run() function.
	 */
	//CommandObjects::driveStraightUntilRampSensor->setSpeed(0.5);
	CommandObjects::RunCommand(CommandObjects::driveStraightUntilRampSensor);
	//CommandObjectsdriveStraightUntilRampSensor->Run();
}

// Called repeatedly when this Command is scheduled to run
void AutoMain::Execute()
{
	/*
	 * By running the command with the "RunCommand" (above) we are able
	 * to check on its execution by checking the "active_command".
	 */
	if( CommandObjects::active_command->IsRunning() )
	{
		 // Is there anything to check while the command is running?
	}else{
		/*
		 * When the command is done running what do we do next?
		 * This might consist of switching to the next command via some kind of state
		 * counter. I've made an example here. But, there are a bunch of different ways
		 * to do this.
		 */
		switch(command_number)
		{
			case 1:
				/*
				 * Now that the first command is done, we might need to cross an obstacle.
				 * Note: This is a case where we'd want to look out to the smart dashboard
				 * to see which command to run. This could be handled in another command (other than "AutoMain"
				 * that checks the status of the button and then carries on.
				 */
				AutoCommandObjects::RunCommand(AutoCommandObjects::crossDefenseChooser);
				command_number++;
				break;
			case 2:
				break;
			case 3:
				break;

		}
	}

}

// Make this return true when this Command no longer needs to run execute()
bool AutoMain::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AutoMain::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoMain::Interrupted()
{

}
