#include "LineUpBatterShot.h"
#include "SetShooterSpeed.h"
#include "../DriveTrain/AutoDrive.h"
#include "../DriveTrain/DriveStraightForDistance.h"
#include "Shoot.h"
#include "SetIntake.h"
#include "WaitForNoBall.h"
#include "SetHoodPosition.h"
#include "ReadjustBallWithIntake.h"
#include "../DriveTrain/SetBrake.h"
#include "../DriveTrain/SetCoast.h"
#include "../Collector/SetArmPosition.h"
#include "../../Subsystems/Collector.h"

LineUpBatterShot::LineUpBatterShot()
{
	AddSequential(new AutoDrive(-0.1, 0));
	AddSequential(new SetBrake());
	AddSequential(new SetArmPosition(Collector::kSafe));//test
	AddSequential(new SetHoodPosition(Shooter::kMiddle));
	AddSequential(new SetShooterSpeed(4000)); //3500
	AddParallel(new DriveStraightForDistance(16, 0.35));
	AddSequential(new SetIntake(Shooter::kIntakeForward));
	AddSequential(new WaitForNoBall());
//	AddSequential(new ReadjustBallWithIntake());
	AddSequential(new WaitCommand(1));
	AddSequential(new SetIntake(Shooter::kIntakeOff));
	AddSequential(new SetHoodPosition(Shooter::kNear));
	AddSequential(new SetShooterSpeed(0));
	AddSequential(new SetCoast());
}
