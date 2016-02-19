#include "AutoPortcullis.h"
#include "Commands/DriveTrain/SetBrake.h"
#include "Commands/Collector/SetArmPosition.h"
#include "Commands/Collector/CheckArmPosition.h"
#include "Commands/DriveTrain/AutoTurn.h"
#include "Commands/Shooter/Shoot.h"
#include "Commands/DriveTrain/SetCoast.h"
#include "Commands/DriveTrain/SetDrive.h"
#include "Commands/DriveTrain/DriveStraightUntilRampSensor.h"
#include "Commands/DriveTrain/DriveStraightAfterRampSensor.h"
#include "DriveStraightForDistance.h"


AutoPortcullis::AutoPortcullis()
{
	AddSequential(new SetBrake());
	AddSequential(new SetArmPosition(Collector::kGround));
	AddSequential(new CheckArmPosition(Collector::kGround));
	AddSequential(new DriveStraightUntilRampSensor(-0.5));
	AddSequential(new DriveStraightForDistance(10, 0.5));
	AddSequential(new SetDrive(0));
	AddSequential(new SetArmPosition(Collector::kSafe));
	AddSequential(new CheckArmPosition(Collector::kSafe));
//	AddSequential(new WaitCommand(5));
//	AddSequential(new DriveStraight(0, -2, -0.5));
//	AddSequential(new SetDrive(0));
	AddSequential(new WaitCommand(.5));
	AddSequential(new DriveStraightForDistance(9, 0.8));
	AddSequential(new DriveStraightAfterRampSensor(-1.0));
//	AddSequential(new SetCoast());
}
