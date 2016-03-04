#include "AutoLowBar.h"
#include "SetBrake.h"
#include "../Collector/SetArmPosition.h"
#include "DriveStraightUntilRampSensor.h"
#include "DriveUntilPitchAndDark.h"
#include "DriveSmoothForDistance.h"
#include "DriveStraightUntilRampSensor.h"

AutoLowBar::AutoLowBar()
{
	AddSequential(new SetBrake());
	AddSequential(new SetArmPosition(Collector::kGround));
	AddSequential(new DriveStraightUntilRampSensor(-0.65));
	AddSequential(new DriveSmoothForDistance(42, -0.7));
//	AddSequential(new DriveStraightUntilRampSensor(0.5))
}
