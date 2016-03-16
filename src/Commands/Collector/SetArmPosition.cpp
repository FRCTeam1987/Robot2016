#include "SetArmPosition.h"

SetArmPosition::SetArmPosition(Collector::ArmPosition position)
{
	Requires(collector);

	m_position = position;
}

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

void SetArmPosition::Execute()
{

}

bool SetArmPosition::IsFinished()
{
	return true;
}

void SetArmPosition::End()
{

}

void SetArmPosition::Interrupted()
{
	collector->SetTopCylinderDirection(Collector::kRetractCylinder);
	collector->SetBottomCylinderDirection(Collector::kExtendCylinder);
}
