#include "AutoLowBar.h"
#include "../Collector/SetArmPosition.h"
#include "DriveStraightUntilRampSensor.h"
#include "DriveStraightAfterRampSensor.h"

AutoLowBar::AutoLowBar()
{
	AddSequential(new SetArmPosition(Collector::kGround));
	AddSequential(new DriveStraightUntilRampSensor(-0.6));
	AddSequential(new DriveStraightAfterRampSensor(-0.6));
}
