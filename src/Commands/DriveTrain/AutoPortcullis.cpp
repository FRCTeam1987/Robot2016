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
#include "Commands/DriveTrain/SetDrive.h"

AutoPortcullis::AutoPortcullis()
{
	AddSequential(new SetBrake());
	AddSequential(new SetArmPosition(Collector::kGround));
	AddSequential(new AutoDriveUntilRampSensor(-0.5));
	AddSequential(new DriveStraight(0, 10, 0.5));
	AddSequential(new SetDrive(0));
	AddSequential(new SetArmPosition(Collector::kSafe));
//	AddSequential(new WaitCommand(5));
//	AddSequential(new DriveStraight(0, -2, -0.5));
//	AddSequential(new SetDrive(0));
	AddSequential(new WaitCommand(.5));
	AddSequential(new DriveStraight(0, 9, 0.8));
	AddSequential(new AutoDriveAfterRampSensor(-1.0));
//	AddSequential(new SetCoast());
}
