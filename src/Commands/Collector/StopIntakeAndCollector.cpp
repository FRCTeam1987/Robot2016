#include "StopIntakeAndCollector.h"
#include "../Shooter/SetIntake.h"
#include "SetCollectorSpeed.h"

StopIntakeAndCollector::StopIntakeAndCollector()
{
	AddSequential(new SetIntake(Shooter::kIntakeOff));
	AddSequential(new SetCollectorSpeed(0));
}
