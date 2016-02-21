#include "CheckArmPosition.h"
#include <iostream>
using namespace std;

CheckArmPosition::CheckArmPosition(Collector::ArmPosition position)
{
	Requires(collector);
	m_position = position;
}

// Called just before this Command runs the first time
void CheckArmPosition::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void CheckArmPosition::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool CheckArmPosition::IsFinished()
{
	return collector->getArmPosition() == m_position;
}

// Called once after isFinished returns true
void CheckArmPosition::End()
{
	printf("Check Arm Ended \n");
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CheckArmPosition::Interrupted()
{

}
