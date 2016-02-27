#include "Shoot.h"
#include "../PrintStuff.h"
#include "SetShooterSpeed.h"
#include "SetIntake.h"
#include "WaitForNoBall.h"
#include "SetHoodPosition.h"

Shoot::Shoot()
{
	AddSequential(new SetShooterSpeed(4500)); //Far - 4300 :: Close - 3800
	AddSequential(new SetIntake(Shooter::kIntakeForward));
	AddSequential(new WaitForNoBall());
	AddSequential(new WaitCommand(1));
	AddSequential(new SetIntake(Shooter::kIntakeOff));
	AddSequential(new SetHoodPosition(Shooter::kNear));
	AddSequential(new SetShooterSpeed(0));
}
