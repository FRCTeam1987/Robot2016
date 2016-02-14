#include "AutoPortcullis.h"
#include "Commands/DriveTrain/SetBrake.h"
#include "Commands/Collector/SetArmPosition.h"
#include "Commands/DriveTrain/AutoDriveUntilRampSensor.h"
#include "Commands/DriveTrain/AutoEncoderDrive.h"
#include "Commands/DriveTrain/AutoDriveAfterRampSensor.h"
#include "Commands/DriveTrain/AutoTurn.h"
#include "Commands/DriveTrain/DriveStraight.h"
#include "Commands/Shooter/Shoot.h"
#include "Commands/DriveTrain/SetCoast.h"

AutoPortcullis::AutoPortcullis()
{
	AddSequential(new SetBrake());
	AddSequential(new SetArmPosition(Collector::kGround));
	AddSequential(new AutoDriveUntilRampSensor(-0.5));
	AddSequential(new DriveStraight(0, 8.5, 0.5));
	AddSequential(new SetArmPosition(Collector::kSafe));
	AddSequential(new WaitCommand(0.25));
	AddSequential(new DriveStraight(0, 6, 0.5));
	AddSequential(new AutoDriveAfterRampSensor(-0.9));
//	AddSequential(new SetCoast());
}
