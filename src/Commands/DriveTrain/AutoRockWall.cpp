#include "AutoRockWall.h"
#include "DriveStraightUntilRampSensor.h"
#include "DriveStraightAfterRampSensor.h"
#include "DriveUntilPitchAndDark.h"
#include "SetBrake.h"
#include "../PrintStuff.h"

AutoRockWall::AutoRockWall(float speed, float pitchTolerance, float rollTolerance)
{
	AddSequential(new SetBrake());
	AddSequential(new DriveStraightUntilRampSensor(-speed));
	AddSequential(new DriveUntilPitchAndDark(0.0, 0.0, speed, pitchTolerance, rollTolerance));
	AddSequential(new DriveStraightUntilRampSensor(0.5));
}
