#include "Collector.h"
#include "../RobotMap.h"

Collector::Collector() :
		Subsystem("ExampleSubsystem")
{
	roller = new Talon(ROLLER_MOTOR);
	topCylinder = new DoubleSolenoid(TOP_CYLINDER_A, TOP_CYLINDER_B);
	bottomCylinder = new DoubleSolenoid(BOTTOM_CYLINDER_A, BOTTOM_CYLINDER_B);
	topCylinderExtended = new DigitalInput(TOP_CYLINDER_EXTENDED_SENSOR);
	bottomCylinderExtended = new DigitalInput(BOTTOM_CYLINDER_EXTENDED_SENSOR);

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

bool Collector::isTopCylinderExtended()
{
	return topCylinderExtended->Get();
}

bool Collector::isBottomCylinderExtended()
{
	return bottomCylinderExtended->Get();
}

Collector::ArmPosition Collector::getArmPosition()
{
	if(isTopCylinderExtended() == true && isBottomCylinderExtended() == true)
	{
		return Collector::kMax;
	}
	else if(isTopCylinderExtended() == false && isBottomCylinderExtended() == true)
	{
		return Collector::kSafe;
	}
	else if(isTopCylinderExtended() == true && isBottomCylinderExtended() == false)
	{
		return Collector::kCollect;
	}
	else if(isTopCylinderExtended() == false && isBottomCylinderExtended() == false)
	{
		return Collector::kGround;
	}
	else
	{
		return Collector::kUnknown;
	}

}
