#include "AutoRockWall.h"
#include "DriveStraightUntilRampSensor.h"
#include "DriveStraightAfterRampSensor.h"
#include "DriveUntilPitchAndDark.h"
#include "SetBrake.h"
#include "../PrintStuff.h"

AutoRockWall::AutoRockWall()
{
	AddSequential(new SetBrake());
	AddSequential(new DriveStraightUntilRampSensor(0.80));
	AddSequential(new DriveUntilPitchAndDark(0.0, 0.0, 0.80));
	AddSequential(new DriveStraightUntilRampSensor(-.5));
}
