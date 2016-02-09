#include "CollectBall.h"
#include "SetArmPosition.h"
#include "SetCollectorSpeed.h"
#include "../Shooter/SetIntake.h"
#include "../Shooter/WaitForBall.h"

CollectBall::CollectBall()
{
	AddSequential(new SetArmPosition(Collector::kCollect));
	AddSequential(new SetCollectorSpeed(0.25));
	AddSequential(new SetIntake(Shooter::kIntakeForward));
	AddSequential(new WaitForBall());
	AddSequential(new SetIntake(Shooter::kIntakeOff));
	AddSequential(new SetCollectorSpeed(0));
	AddSequential(new SetArmPosition(Collector::kSafe));
}
