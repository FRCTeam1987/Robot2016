#include "LineUpBatterShot.h"
#include "SetShooterSpeed.h"
#include "../DriveTrain/DriveStraightForDistance.h"
#include "Shoot.h"
#include "SetIntake.h"
#include "WaitForNoBall.h"

LineUpBatterShot::LineUpBatterShot()
{
	AddSequential(new SetShooterSpeed(3800));
	AddSequential(new DriveStraightForDistance(6, 0.2));
	AddSequential(new SetIntake(Shooter::kIntakeForward));
	AddSequential(new WaitForNoBall());
	AddSequential(new WaitCommand(1));
	AddSequential(new SetIntake(Shooter::kIntakeOff));
//	AddSequential(new SetHoodPosition(Shooter::kNear));
	AddSequential(new SetShooterSpeed(0));
}
