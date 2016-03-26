#include "AutoCommandObjects.h"

Command* AutoCommandObjects::active_command = NULL;

CrossDefenseChooser* AutoCommandObjects::crossDefenseChooser = NULL;

AutoCommandObjects::AutoCommandObjects()
{
	crossDefenseChooser = new CrossDefenseChooser();
}

void AutoCommandObjects::RunCommand(Command * cmd)
{
	active_command = cmd;
	cmd->Run();
}
