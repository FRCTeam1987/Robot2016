#include "ReverseShooterAndIntake.h"
#include "SetIntake.h"
#include "SetWheelRaw.h"

ReverseShooterAndIntake::ReverseShooterAndIntake()
{
	AddSequential(new SetIntake(Shooter::IntakeMode::kIntakeReverse));
//	AddSequential(new SetWheelRaw(-1.0));
}
