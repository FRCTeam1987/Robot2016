#include "AutoChevalDeFrise.h"
#include "SetBrake.h"
#include "AutoTurn.h"
#include "../Collector/SetArmPosition.h"
#include "../Collector/CheckArmPosition.h"
#include "DriveUntilPitchAndDark.h"
#include "DriveStraightUntilRampSensor.h"
#include "DriveStraightAfterRampSensor.h"
#include "DriveStraightForDistance.h"
#include "DriveStraightAfterRampSensor.h"
#include "../Electrical_Lights/SetLights.h"


AutoChevalDeFrise::AutoChevalDeFrise()
{
	AddSequential(new SetLights(Lights::COLOR::PURPLE));
	AddSequential(new SetBrake());
	AddSequential(new SetArmPosition(Collector::kSafe));
	AddSequential(new DriveStraightUntilRampSensor(0.5));
//	AddSequential(new DriveStraightForDistance(1, -.50));
	AddSequential(new SetArmPosition(Collector::kGround));
	AddSequential(new WaitCommand(1.5));
	AddSequential(new DriveStraightForDistance(10, 0.9));
	AddSequential(new SetArmPosition(Collector::kSafe));
	AddSequential(new DriveStraightForDistance(40, 0.9));
//	AddSequential(new DriveUntilPitchAndDark(5.0, -1.0, -0.75, 1.0, 1.0));
	AddSequential(new DriveStraightAfterRampSensor(0.75));
	AddSequential(new DriveStraightForDistance(9, 0.8));
	AddSequential(new AutoTurn(180, false, 1.0, .45, .0025, 2.0));
	AddSequential(new SetLights(Lights::COLOR::OFF));
}

void AutoChevalDeFrise::End()
{
	AddSequential(new SetLights(Lights::COLOR::OFF));
}

void AutoChevalDeFrise::Interrupted()
{
	AddSequential(new SetLights(Lights::COLOR::OFF));
}
