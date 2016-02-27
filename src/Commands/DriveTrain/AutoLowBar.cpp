#include "AutoLowBar.h"
#include "SetBrake.h"
#include "../Collector/SetArmPosition.h"
#include "DriveStraightUntilRampSensor.h"
#include "DriveUntilPitchAndDark.h"
#include "DriveStraightUntilRampSensor.h"

AutoLowBar::AutoLowBar()
{
	AddSequential(new SetBrake());
	AddSequential(new SetArmPosition(Collector::kGround));
	AddSequential(new DriveStraightUntilRampSensor(-0.7));
	AddSequential(new DriveUntilPitchAndDark(-1.0, -1.0, 0.7, 0.5, 0.5));
	AddSequential(new DriveStraightUntilRampSensor(0.5));
}
