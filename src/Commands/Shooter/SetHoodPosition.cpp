#include "SetHoodPosition.h"

SetHoodPosition::SetHoodPosition(Shooter::HoodPosition position)
{
	Requires(shooter);
	m_position = position;
}

// Called just before this Command runs the first time
void SetHoodPosition::Initialize()
{
	switch(m_position)
	{
	case Shooter::kNear:
		shooter->SetTopCylinderDirection(Shooter::kRetractCylinder);
		shooter->SetBottomCylinderDirection(Shooter::kRetractCylinder);
		break;
	case Shooter::kMiddle:
		shooter->SetTopCylinderDirection(Shooter::kExtendCylinder);
		shooter->SetBottomCylinderDirection(Shooter::kRetractCylinder);
		break;
	case Shooter::kFar:
		shooter->SetTopCylinderDirection(Shooter::kExtendCylinder);
		shooter->SetBottomCylinderDirection(Shooter::kExtendCylinder);
		break;
	default:
		printf("Error, enum out of bounds in SetHoodPosition\n");
		break;
	}
}

// Called repeatedly when this Command is scheduled to run
void SetHoodPosition::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SetHoodPosition::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SetHoodPosition::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetHoodPosition::Interrupted()
{

}
