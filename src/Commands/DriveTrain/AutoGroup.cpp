#include "AutoGroup.h"
#include "AutoLowBar.h"
#include "DriveStraightForDistance.h"
#include "../Collector/SetArmPosition.h"
#include "AutoTurn.h"

AutoGroup::AutoGroup()
{
//	AddSequential(new AutoLowBar());
//	AddSequential(new DriveStraightForDistance(5, -0.6));
//	AddSequential(new SetArmPosition(Collector::kSafe));
//	AddSequential(new DriveStraightForDistance(67, -0.6));
	AddSequential(new AutoTurn(55));
}
