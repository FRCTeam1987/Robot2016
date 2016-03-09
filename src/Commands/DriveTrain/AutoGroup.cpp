#include "AutoGroup.h"
#include "AutoLowBar.h"
#include "AutoChevalDeFrise.h"
#include "AutoRockWall.h"
#include "AutoTurn.h"
#include "AutoTurnPID.h"
#include "DriveSmoothForDistance.h"
#include "DriveStraightForDistance.h"
#include "DriveStraightAfterRampSensor.h"
#include "SetBrake.h"
#include "SetCoast.h"
#include "../Collector/SetArmPosition.h"
#include "../Shooter/ShootFar.h"
#include "../Shooter/LineUpBatterShot.h"
#include "../DriveTrain/AutoPortcullis.h"

AutoGroup::AutoGroup()
{
//Auto Low Bar Shot
//	AddSequential(new AutoLowBar());
//	AddSequential(new SetBrake());
//	AddSequential(new DriveSmoothForDistance(5, -0.5, false));
//	AddSequential(new SetArmPosition(Collector::kSafe));
//	AddSequential(new DriveSmoothForDistance(76, -0.65, false));
//	AddSequential(new AutoTurn(55, true, 0.5, 0.5, 0.0035, 1.0));
//	AddSequential(new ShootFar());
//	AddSequential(new SetCoast());

//Auto Cheval De Frise (Pos 2)
//	AddSequential(new AutoChevalDeFrise());
//	AddSequential(new DriveSmoothForDistance(100, 0.5, false));
//	AddSequential(new AutoTurn (215, true, 0.2));
//	AddSequential(new ShootFar());
//	AddSequential(new SetCoast());

//Pos 2
//	AddSequential(new DriveSmoothForDistance(24, -0.5, false));
//	AddSequential(new AutoTurn (28, true, 0.5, .51)); //Lucas says try 1.0
//	AddSequential(new ShootFar());
//	AddSequential(new SetCoast());

//Pos 3
//	AddSequential(new DriveStraightForDistance(24, -0.5, false));
//	AddSequential(new AutoTurn (18.5, true, .5, .51)); //angle might be off
//	AddSequential(new ShootFar());
//	AddSequential(new SetCoast());

//Pos 4
//	AddSequential(new DriveStraightForDistance(153, -0.57, 356)); //distance value is close, may need to drive more or less
//	AddSequential(new LineUpBatterShot());
//	AddSequential(new SetCoast());

//Pos 5
//	AddSequential(new DriveSmoothForDistance(4, -0.5, false));
//	AddSequential(new AutoTurn (335, true, 0.5, .450));
//	AddSequential(new ShootFar());
//	AddSequential(new SetCoast());

//Pos 5 (port)
//	AddSequential(new AutoRockWall(0.8, 5.0, 2.0));//Rough Terrain
//	AddSequential(new AutoChevalDeFrise());
//	AddSequential(new DriveStraightAfterRampSensor(-0.4));
//	AddSequential(new DriveSmoothForDistance(4, -0.5, true));
//	AddSequential(new AutoTurn(335, true, .50, .47, .0025));
//	AddSequential(new ShootFar());
//	AddSequential(new SetCoast());

}
