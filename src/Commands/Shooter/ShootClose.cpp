#include "ShootClose.h"
#include "SetIntake.h"
#include "SetShooterSpeed.h"
#include "SetHoodPosition.h"

ShootClose::ShootClose()
{
	AddSequential(new SetHoodPosition(Shooter::kMiddle));
	AddSequential(new SetShooterSpeed(5050));
	AddSequential(new SetIntake(Shooter::kIntakeForward));
	AddSequential(new SetShooterSpeed(0));
	AddSequential(new SetIntake(Shooter::kIntakeOff));
	AddSequential(new SetHoodPosition(Shooter::kNear));
}
