#include "AutoLowBar.h"
#include "SetBrake.h"
#include "../Collector/SetArmPosition.h"
#include "DriveStraightUntilRampSensor.h"
#include "DriveUntilPitchAndDark.h"
#include "DriveSmoothForDistance.h"
#include "DriveStraightUntilRampSensor.h"
#include "../Electrical_Lights/SetLights.h"

AutoLowBar::AutoLowBar()
{
	AddSequential(new SetLights(Lights::COLOR::PURPLE));
	AddSequential(new SetBrake());
	AddSequential(new SetArmPosition(Collector::kGround));
	AddSequential(new DriveStraightUntilRampSensor(-0.75));
	AddSequential(new DriveSmoothForDistance(42, -0.75));
//	AddSequential(new DriveStraightUntilRampSensor(0.5))
	AddSequential(new SetLights(Lights::COLOR::OFF));
}

void AutoLowBar::End()
{
	AddSequential(new SetLights(Lights::COLOR::OFF));
}

void AutoLowBar::Interrupted()
{
	AddSequential(new SetLights(Lights::COLOR::OFF));
}
