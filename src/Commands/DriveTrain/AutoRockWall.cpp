#include "AutoRockWall.h"
#include "AutoTurn.h"
#include "AutoTurnHeading.h"
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
//	AddSequential(new AutoTurn(0.5, false, .50, .450));
//	AddSequential(new AutoTurnHeading(0.5));
	AddSequential(new DriveStraightUntilRampSensor(0.5));
}
