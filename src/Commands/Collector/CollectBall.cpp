#include "CollectBall.h"
#include "SetArmPosition.h"
#include "SetCollectorSpeed.h"
#include "../Shooter/SetIntake.h"
#include "../Shooter/WaitForBall.h"
#include "../Electrical_Lights/SetLights.h"

CollectBall::CollectBall()
{
	AddSequential(new SetArmPosition(Collector::kCollect));
	AddSequential(new SetCollectorSpeed(0.75));
	AddSequential(new SetIntake(Shooter::kIntakeForward));
	AddSequential(new SetLights(Lights::COLOR::YELLOW));
	AddSequential(new WaitForBall());
	AddSequential(new SetLights(Lights::COLOR::RED));
	AddSequential(new SetIntake(Shooter::kIntakeOff));
	AddSequential(new SetCollectorSpeed(0));
	AddSequential(new SetArmPosition(Collector::kCollect));
}

