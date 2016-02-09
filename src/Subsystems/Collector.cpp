#include "Collector.h"
#include "../RobotMap.h"

Collector::Collector() :
		Subsystem("ExampleSubsystem")
{
	roller = new Talon(ROLLERMOTOR);
}

void Collector::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void Collector::RunRoller(float speed)
{
	roller->Set(speed);
}
