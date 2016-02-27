#include "AutoChevalDeFrise.h"
#include "SetBrake.h"
#include "../Collector/SetArmPosition.h"
#include "../Collector/CheckArmPosition.h"
#include "DriveUntilPitchAndDark.h"
#include "DriveStraightUntilRampSensor.h"
#include "DriveStraightAfterRampSensor.h"
#include "DriveStraightForDistance.h"


AutoChevalDeFrise::AutoChevalDeFrise()
{
	AddSequential(new SetBrake());
	AddSequential(new SetArmPosition(Collector::kSafe));
	AddSequential(new CheckArmPosition(Collector::kSafe));
	AddSequential(new DriveStraightUntilRampSensor(0.5));
//	AddSequential(new DriveStraightForDistance(1, -.50));
	AddSequential(new SetArmPosition(Collector::kGround));
//	AddSequential(new CheckArmPosition(Collector::kGround));
	AddSequential(new WaitCommand(1.5));
	AddSequential(new DriveStraightForDistance(6, .90));
	AddSequential(new SetArmPosition(Collector::kCollect));
	AddSequential(new CheckArmPosition(Collector::kCollect));
	AddSequential(new DriveUntilPitchAndDark(0.0, 0.0, -0.75, PITCH_ANGLE_TOLERANCE, ROLL_ANGLE_TOLERANCE));
}
