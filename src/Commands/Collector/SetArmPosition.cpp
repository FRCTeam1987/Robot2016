#include "SetArmPosition.h"

SetArmPosition::SetArmPosition(Collector::ArmPosition position)
{
	Requires(collector);

	m_position = position;
}

// Called just before this Command runs the first time
void SetArmPosition::Initialize()
{

	switch(m_position)
	{
	case Collector::kGround:
		SmartDashboard::PutString("Current_Command", "SetArmPosition - kGround");
		collector->SetTopCylinderDirection(Collector::kRetractCylinder);
		collector->SetBottomCylinderDirection(Collector::kRetractCylinder);
		break;
	case Collector::kCollect:
		SmartDashboard::PutString("Current_Command", "SetArmPosition - kCollect");
		collector->SetTopCylinderDirection(Collector::kExtendCylinder);
		collector->SetBottomCylinderDirection(Collector::kRetractCylinder);
		break;
	case Collector::kSafe:
		SmartDashboard::PutString("Current_Command", "SetArmPosition - kSafe");
		collector->SetTopCylinderDirection(Collector::kRetractCylinder);
		collector->SetBottomCylinderDirection(Collector::kExtendCylinder);
		break;
	case Collector::kMax:
		SmartDashboard::PutString("Current_Command", "SetArmPosition - kMax");
		collector->SetTopCylinderDirection(Collector::kExtendCylinder);
		collector->SetBottomCylinderDirection(Collector::kExtendCylinder);
		break;
	default:
		printf("Error, enum out of bounds in SetArmPosition\n");
		break;
	}
}

// Called repeatedly when this Command is scheduled to run
void SetArmPosition::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SetArmPosition::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SetArmPosition::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetArmPosition::Interrupted()
{
	collector->SetTopCylinderDirection(Collector::kRetractCylinder);
	collector->SetBottomCylinderDirection(Collector::kExtendCylinder);
}
