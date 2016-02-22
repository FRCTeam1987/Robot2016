#include "AutoLowBar.h"
#include "../Collector/SetArmPosition.h"
#include "DriveStraightForDistance.h"
#include "DriveStraightUntilRampSensor.h"

AutoLowBar::AutoLowBar()
{
	AddSequential(new SetArmPosition(Collector::kGround));
	AddSequential(new DriveStraightForDistance(42, -0.6));
	AddSequential(new DriveStraightUntilRampSensor(0.6));
}
