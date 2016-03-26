#include "CommandObjects.h"

Command* CommandObjects::active_command = NULL;

AutoChevalDeFrise* CommandObjects::autoChevalDeFrise = NULL;
DriveStraightUntilRampSensor* CommandObjects::driveStraightUntilRampSensor = NULL;
SetBrake* CommandObjects::setBrake = NULL;

CommandObjects::CommandObjects()
{
	autoChevalDeFrise = new AutoChevalDeFrise();

//	driveStraightUntilRampSensor = new DriveStraightUntilRampSensor();

	setBrake = new SetBrake();

}

void CommandObjects::RunCommand(Command * cmd)
{
	active_command = cmd;
	cmd->Run();
}
