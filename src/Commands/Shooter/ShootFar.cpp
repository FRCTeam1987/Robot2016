#include "ShootFar.h"
#include "SetHoodPosition.h"
#include "SetShooterSpeed.h"
#include "SetIntake.h"

ShootFar::ShootFar()
{
	AddSequential(new SetHoodPosition(Shooter::kFar));
	AddSequential(new SetShooterSpeed(5050));
	AddSequential(new SetIntake(Shooter::kIntakeForward));
	AddSequential(new SetShooterSpeed(0));
	AddSequential(new SetIntake(Shooter::kIntakeOff));
	AddSequential(new SetHoodPosition(Shooter::kNear));
}
