#include "Collector.h"
#include "../RobotMap.h"

Collector::Collector() :
		Subsystem("ExampleSubsystem")
{
	roller = new Talon(ROLLER_MOTOR);
	topCylinder = new DoubleSolenoid(TOP_CYLINDER_A, TOP_CYLINDER_B);
	bottomCylinder = new DoubleSolenoid(BOTTOM_CYLINDER_A, BOTTOM_CYLINDER_B);

}

void Collector::InitDefaultCommand()
{

}

void Collector::RunRoller(float speed)
{
	roller->Set(speed);
}

void Collector::SetTopCylinderDirection(CylinderDirection direction)
{
	if(direction == Collector::kExtendCylinder)
	{
		topCylinder->Set(DoubleSolenoid::kReverse);
	}
	else
	{
		topCylinder->Set(DoubleSolenoid::kForward);
	}
}

void Collector::SetBottomCylinderDirection(CylinderDirection direction)
{
	if(direction == Collector::kExtendCylinder)
	{
		bottomCylinder->Set(DoubleSolenoid::kReverse);
	}
	else
	{
		bottomCylinder->Set(DoubleSolenoid::kForward);
	}
}
