#include "Shoot.h"
#include "../PrintStuff.h"
#include "SetShooterSpeed.h"
#include "SetIntake.h"
#include "WaitForNoBall.h"
#include "SetHoodPosition.h"
#include "ReadjustBallWithIntake.h"

Shoot::Shoot()
{
	AddSequential(new SetHoodPosition(Shooter::kFar));
	AddSequential(new SetShooterSpeed(3800)); //Thursday = 4300
	AddSequential(new SetIntake(Shooter::kIntakeForward));
	AddSequential(new WaitForNoBall());
	AddSequential(new ReadjustBallWithIntake());
	AddSequential(new WaitCommand(1));
	AddSequential(new SetIntake(Shooter::kIntakeOff));
	AddSequential(new SetHoodPosition(Shooter::kNear));
	AddSequential(new SetShooterSpeed(0));
}
