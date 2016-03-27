#include "CollectIntakeOnly.h"
#include "../Shooter/SetIntake.h"
#include "../Shooter/WaitForBall.h"
#include "../Electrical_Lights/SetLights.h"

CollectIntakeOnly::CollectIntakeOnly()
{
	AddSequential(new SetIntake(Shooter::kIntakeForward));
	AddSequential(new SetLights(Lights::COLOR::YELLOW));
	AddSequential(new WaitForBall());
	AddSequential(new SetLights(Lights::COLOR::RED));
	AddSequential(new SetIntake(Shooter::kIntakeOff));
}
