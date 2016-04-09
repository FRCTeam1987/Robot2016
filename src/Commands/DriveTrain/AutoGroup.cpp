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
#include "../PrintStuff.h"
#include "../Collector/SetArmPosition.h"
#include "../Shooter/ShootFar.h"
#include "../Shooter/LineUpBatterShot.h"
#include "../DriveTrain/AutoPortcullis.h"
#include "../DriveTrain/AutoTargetAndTurn.h"

AutoGroup::AutoGroup()
{
//Auto Low Bar Shot
//	AddSequential(new AutoLowBar());
//	AddSequential(new SetBrake());
//	AddSequential(new PrintStuff());
//	AddSequential(new DriveSmoothForDistance(5, -0.5, 0.325, false));//test and then try drive straight
//	AddSequential(new SetArmPosition(Collector::kSafe));
//	AddSequential(new DriveSmoothForDistance(76, -0.65, 0.25, false));
//	AddSequential(new AutoTurn(57, true, 0.5, 0.47, 0.0035, 1.0));
////	AddSequential(new AutoTargetAndTurn());
//	AddSequential(new ShootFar());
////	AddSequential(new AutoTurn(123, false, 1.0, 0.46, 0.0035, 2.0));
//	AddSequential(new AutoTurn(180, false, 1.0, 0.46, 0.0035, 2.0));
//	AddSequential(new WaitCommand(0.25));
//	AddSequential(new DriveStraightForDistance(76, -0.65));
//	AddSequential(new AutoLowBar());
//	AddSequential(new SetCoast());

//Auto ChevalDeFrise (Pos 2)
//	AddSequential(new AutoChevalDeFrise());
//	AddSequential(new DriveSmoothForDistance(75, -0.5, false));
//	AddSequential(new AutoTurn (32, true, 0.2, .44));
//	AddSequential(new AutoTargetAndTurn());
//	AddSequential(new ShootFar());
//	AddSequential(new SetCoast());

//Pos 2 drive 75in and auto aim
//	AddSequential(new DriveSmoothForDistance(24, -0.5, false));
//	AddSequential(new AutoTurn (28, true, 0.5, .51)); //Lucas says try 1.0
//	AddSequential(new AutoTargetAndTurn());
//	AddSequential(new ShootFar());
//	AddSequential(new SetCoast());

//Pos 2 (port)
//	AddSequential(new AutoPortcullis());
	new AutoChevalDeFrise();
//	AddSequential(new DriveStraightForDistance(75, -0.5, false));
//	AddSequential(new AutoTurn(25, true, .50, .47, .0025));
//	AddSequential(new DriveStraightForDistance(36, 0.5, false));
//	AddSequential(new AutoTargetAndTurn());
//	AddSequential(new WaitCommand(.2));
//	AddSequential(new AutoTargetAndTurn());
//	AddSequential(new WaitCommand(.2));
//	AddSequential(new AutoTargetAndTurn());
//	AddSequential(new ShootFar());
//	AddSequential(new SetCoast());

//Pos 3
//	AddSequential(new DriveStraightForDistance(24, -0.5, false));
//	AddSequential(new AutoTurn (18.5, true, .5, .51)); //angle might be off
//	AddSequential(new AutoTargetAndTurn());
//	AddSequential(new ShootFar());
//	AddSequential(new SetCoast());

//Pos 3 (port)
//	AddSequential(new AutoPortcullis());
//	AddSequential(new AutoChevalDeFrise());
//	AddSequential(new AutoRockWall(0.8, 5.0, 2.0));
//	AddSequential(new DriveStraightForDistance(4, -0.5, false));
//	AddSequential(new AutoTurn (18.5, true, .5, .47));
//	AddSequential(new AutoTargetAndTurn());
//	AddSequential(new AutoTargetAndTurn());
//    AddSequential(new ShootFar());
//	AddSequential(new SetCoast());

//Pos 4
//	AddSequential(new AutoRockWall(0.8, 5.0, 2.0));
//	AddSequential(new DriveStraightForDistance(4.5, -0.5, false));
//	AddSequential(new AutoTurn(357, true, .50, .47, .0025));
//	AddSequential(new AutoTargetAndTurn());
//	AddSequential(new ShootFar());
//	AddSequential(new SetCoast());

//Pos 4 (port)
//	AddSequential(new AutoChevalDeFrise());
//	AddSequential(new DriveStraightForDistance(4.5, -0.5, false));
//	AddSequential(new AutoTurn(357, true, .50, .47, .0025));
//	AddSequential(new AutoTargetAndTurn());
//	AddSequential(new ShootFar());
//	AddSequential(new SetCoast());

//Pos 5 turn 5 degrees then auto aim
//	AddSequential(new DriveSmoothForDistance(4, -0.5, false));
//	AddSequential(new AutoTurn (335, true, 0.5, .450));
//	AddSequential(new AutoTargetAndTurn());
//	AddSequential(new ShootFar());
//	AddSequential(new SetCoast());

//Pos 5 (port)
//	AddSequential(new AutoChevalDeFrise());
//	AddSequential(new DriveStraightForDistance(4, -0.5, false));
//	AddSequential(new AutoTurn(335, true, .50, .47, .0025));
//	AddSequential(new WaitCommand(1));
//	AddSequential(new AutoTargetAndTurn());
//	AddSequential(new ShootFar());
//	AddSequential(new SetCoast());



}
