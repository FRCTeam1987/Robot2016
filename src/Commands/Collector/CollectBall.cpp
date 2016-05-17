#include "CollectBall.h"
#include "SetArmPosition.h"
#include "SetCollectorSpeed.h"
#include "../Shooter/SetIntake.h"
#include "../Shooter/WaitForBall.h"
#include "../Electrical_Lights/SetLights.h"
#include "SetRumble.h"

CollectBall::CollectBall()
{
	AddSequential(new SetArmPosition(Collector::kCollect));
	AddSequential(new SetCollectorSpeed(.80));
	AddSequential(new SetIntake(Shooter::kIntakeForward));
	AddSequential(new SetLights(Lights::COLOR::YELLOW));
	AddSequential(new WaitForBall());
	AddParallel(new SetRumble());
	AddSequential(new SetLights(Lights::COLOR::RED));
	AddSequential(new SetIntake(Shooter::kIntakeOff));
	AddSequential(new SetCollectorSpeed(0));
	AddSequential(new SetArmPosition(Collector::kCollect));
}

