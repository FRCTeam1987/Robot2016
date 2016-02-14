#include "OurElectrical.h"
#include "../RobotMap.h"
#include "../Commands/PrintCurrent.h"

OurElectrical::OurElectrical() :
		Subsystem("OurElectrical")
{
	pdp = new PowerDistributionPanel();
}

void OurElectrical::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	this->SetDefaultCommand(new PrintCurrent());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
