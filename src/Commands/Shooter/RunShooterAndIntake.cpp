#include "RunShooterAndIntake.h"
#include "SetIntake.h"
#include "SetShooterSpeed.h"

RunShooterAndIntake::RunShooterAndIntake()
{
	AddSequential(new SetIntake(Shooter::kIntakeForward));
	AddSequential(new SetShooterSpeed(4650));
}
