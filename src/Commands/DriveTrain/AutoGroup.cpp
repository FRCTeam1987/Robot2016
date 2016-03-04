#include "AutoGroup.h"
#include "AutoLowBar.h"
#include "DriveSmoothForDistance.h"
#include "../Collector/SetArmPosition.h"
#include "../Shooter/ShootFar.h"
#include "AutoTurn.h"
#include "AutoTurnPID.h"
#include "SetBrake.h"
#include "SetCoast.h"

AutoGroup::AutoGroup()
{
//Auto Batter Shot
	AddSequential(new AutoLowBar());
	AddSequential(new SetBrake());
	AddSequential(new DriveSmoothForDistance(5, -0.5, false));
	AddSequential(new SetArmPosition(Collector::kSafe));
	AddSequential(new DriveSmoothForDistance(90, -0.65, false));
	AddSequential(new AutoTurn(53, true));
	AddSequential(new SetCoast());
	AddSequential(new ShootFar());

//Auto Low Bar Shot

//Auto Spy Box Shot

//Auto Two Ball Auto
}
