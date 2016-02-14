#include "AutoRockWall.h"
#include "AutoDriveUntilRampSensor.h"
#include "AutoDriveAfterRampSensor.h"
#include "DriveUntilPitchAndDark.h"
#include "SetBrake.h"
#include "../PrintStuff.h"

AutoRockWall::AutoRockWall()
{
	AddSequential(new SetBrake());
	AddSequential(new AutoDriveUntilRampSensor(0.80));
	AddSequential(new DriveUntilPitchAndDark(0.0, 0.0, 0.80));
	AddSequential(new AutoDriveUntilRampSensor(-.5));
}
