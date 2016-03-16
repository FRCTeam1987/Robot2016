#include "CheckArmPosition.h"
#include <iostream>
using namespace std;

CheckArmPosition::CheckArmPosition()
{
	Requires(collector);
	m_position = Collector::ArmPosition::kSafe;
}

CheckArmPosition::CheckArmPosition(Collector::ArmPosition position)
{
	Requires(collector);
	m_position = position;
}

void CheckArmPosition::setPosition(Collector::ArmPosition position)
{
	m_position = position;
}

void CheckArmPosition::Initialize()
{
	SmartDashboard::PutString("Current_Command", "CheckArmPosition");
}

void CheckArmPosition::Execute()
{

}

bool CheckArmPosition::IsFinished()
{
	return collector->getArmPosition() == m_position;
}

void CheckArmPosition::End()
{
	printf("Check Arm Ended \n");
}

void CheckArmPosition::Interrupted()
{

}
