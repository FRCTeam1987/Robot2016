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
	AddSequential(new AutoDrive(0, 0));
	AddSequential(new SetBrake());
	AddSequential(new SetArmPosition(Collector::kSafe));//test
	AddSequential(new SetHoodPosition(Shooter::kMiddle));
	AddSequential(new SetShooterSpeed(3800)); //3500
	AddSequential(new DriveStraightForDistance(7, 0.2));
	AddSequential(new SetIntake(Shooter::kIntakeForward));
	AddSequential(new WaitForNoBall());
//	AddSequential(new ReadjustBallWithIntake());
	AddSequential(new WaitCommand(1));
	AddSequential(new SetIntake(Shooter::kIntakeOff));
	AddSequential(new SetHoodPosition(Shooter::kNear));
	AddSequential(new SetShooterSpeed(0));
	AddSequential(new SetCoast());
}
