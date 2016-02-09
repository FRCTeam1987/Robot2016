#include "Shoot.h"
#include "../PrintStuff.h"
#include "SetShooterSpeed.h"
#include "SetIntake.h"
#include "WaitForNoBall.h"

Shoot::Shoot()
{
	AddSequential(new SetShooterSpeed(3500));
	AddSequential(new SetIntake(Shooter::kIntakeForward));
	AddSequential(new WaitForNoBall());
	AddSequential(new WaitCommand(1));
	AddSequential(new SetShooterSpeed(0));
	AddSequential(new SetIntake(Shooter::kIntakeOff));
}
