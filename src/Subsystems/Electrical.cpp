#include "Electrical.h"
#include "../RobotMap.h"
#include "../Commands/PrintCurrent.h"

Electrical::Electrical() :
		Subsystem("Electrical")
{
	pdp = new PowerDistributionPanel();
}

void Electrical::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
