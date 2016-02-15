#include "AutoLowBar.h"
#include "DriveStraightUntilRampSensor.h"
#include "DriveStraightAfterRampSensor.h"

AutoLowBar::AutoLowBar()
{
	AddSequential(new DriveStraightUntilRampSensor(0.6));
	AddSequential(new DriveStraightAfterRampSensor(0.6));
}
