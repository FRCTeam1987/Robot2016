#include "AutoGroup.h"
#include "AutoLowBar.h"
#include "AutoChevalDeFrise.h"
#include "AutoRockWall.h"
#include "AutoTurn.h"
#include "AutoTurnPID.h"
#include "DriveUntilPitchAndDark.h"
#include "DriveSmoothForDistance.h"
#include "DriveStraightForDistance.h"
#include "DriveStraightAfterRampSensor.h"
#include "DriveStraightUntilRampSensor.h"
#include "SetBrake.h"
#include "SetCoast.h"
#include "../PrintStuff.h"
#include "../Collector/SetArmPosition.h"
#include "../Shooter/ShootFar.h"
#include "../Shooter/ShootClose.h"
#include "../Shooter/LineUpBatterShot.h"
#include "../DriveTrain/AutoPortcullis.h"
#include "../DriveTrain/AutoTargetAndTurn.h"
#include "../DriveTrain/AutoTurnSmallAngle.h"

AutoGroup::AutoGroup()
{
	AddSequential(new SetBrake());
//Auto Low Bar Shot
//	AddSequential(new AutoLowBar());
//	AddSequential(new SetBrake());
//	AddSequential(new PrintStuff());
//	AddSequential(new DriveSmoothForDistance(5, -0.5, 0.325, false));//test and then try drive straight
//	AddSequential(new SetArmPosition(Collector::kSafe));
//	AddSequential(new DriveSmoothForDistance(76, -0.65, 0.25, false));
//	AddSequential(new AutoTurn(53, true, 0.5, 0.47, 0.0035, 1.0));
////	AddSequential(new AutoTurnSmallAngle(50, true));
//	AddSequential(new WaitCommand(.5));
//	AddSequential(new AutoTargetAndTurn());
//	AddSequential(new ShootFar());
//	AddSequential(new AutoTurn(126, true, 1.0, 0.46, 0.0035, 2.0));
////	AddSequential(new AutoTurnSmallAngle(119, true, false, 0.3, 0.75));//slow
//	AddSequential(new WaitCommand(0.25));
//	AddSequential(new DriveStraightForDistance(76, -0.65));
//	AddSequential(new AutoLowBar());
//	AddSequential(new SetCoast());

//Auto ChevalDeFrise (Pos 2)
//	AddSequential(new AutoChevalDeFrise());
//	AddSequential(new DriveSmoothForDistance(75, -0.5, false));
////	AddSequential(new AutoTurn(32, true, 0.2, .44));
//	AddSequential(new AutoTurnSmallAngle(32, true));
//	AddSequential(new AutoTargetAndTurn());
//	AddSequential(new ShootFar());
//	AddSequential(new SetCoast());

//Pos 2
//	AddSequential(new DriveSmoothForDistance(24, -0.5, false));
////	AddSequential(new AutoTurn (28, true, 0.5, .51)); //Lucas says try 1.0
//	AddSequential(new AutoTurnSmallAngle(28, true));
//	AddSequential(new AutoTargetAndTurn());
//	AddSequential(new ShootFar());
//	AddSequential(new SetCoast());

//Pos 2 (port)
////	AddSequential(new AutoPortcullis());
//Works but is slow
//	AddSequential(new AutoChevalDeFrise());
//	AddSequential(new DriveStraightForDistance(80, -0.5, false));
////	AddSequential(new AutoTurn(25, true, .50, .47, .0025));
//	AddSequential(new AutoTurnSmallAngle(25, true));
//	AddSequential(new DriveStraightForDistance(14, -0.5, false));
//	AddSequential(new WaitCommand(.55));
//	AddSequential(new AutoTurnSmallAngle(30, true));
//	AddSequential(new WaitCommand(.15));
//	AddSequential(new AutoTargetAndTurn());
//	AddSequential(new WaitCommand(.55));
//	AddSequential(new AutoTargetAndTurn());
//	AddSequential(new DriveStraightForDistance(3, -0.5, false));
////	AddSequential(new AutoTargetAndTurn());
////	AddSequential(new WaitCommand(.2));
////	AddSequential(new AutoTargetAndTurn());
//	AddSequential(new ShootClose());
//	AddSequential(new SetCoast());

	//works but is wierd
//Pos 2 (port)
//	AddSequential(new AutoPortcullis());
//	AddSequential(new SetBrake());
//	AddSequential(new DriveStraightForDistance(93, -0.65, false));
//	AddSequential(new WaitCommand(.5));
////	AddSequential(new AutoTurn(25, true, .50, .47, .0025));
//	AddSequential(new AutoTurn(65, true));
//	AddSequential(new WaitCommand(.5));
//	AddSequential(new SetCoast());
//	AddSequential(new DriveStraightForDistance(2, -0.5, false));
//	AddSequential(new WaitCommand(1));
//	AddSequential(new AutoTargetAndTurn());
//////	AddSequential(new DriveStraightForDistance(15, -0.5, false));
////	AddSequential(new WaitCommand(.15));
////	AddSequential(new AutoTargetAndTurn());
//////	AddSequential(new WaitCommand(.55));
//////	AddSequential(new AutoTargetAndTurn());
//////	AddSequential(new WaitCommand(.2));
//////	AddSequential(new AutoTargetAndTurn());
//	AddSequential(new ShootClose());
//	AddSequential(new SetCoast());

//Pos 2 (cheval)
//	AddSequential(new AutoChevalDeFrise());
//	AddSequential(new DriveStraightForDistance(100, -0.65, false));
////	AddSequential(new AutoTurn(25, true, .50, .47, .0025));
//	AddSequential(new AutoTurn(50, true));//test this angle
//	AddSequential(new DriveStraightForDistance(3, -0.5, false));
//	AddSequential(new WaitCommand(.75));
//	AddSequential(new AutoTargetAndTurn());
//	AddSequential(new ShootClose());
//	AddSequential(new SetCoast());

//Pos 3
//	AddSequential(new DriveStraightForDistance(24, -0.5, false));
////	AddSequential(new AutoTurn (18.5, true, .5, .51)); //angle might be off
//	AddSequential(new AutoTurnSmallAngle(18.5, true));
//	AddSequential(new AutoTargetAndTurn());
//	AddSequential(new ShootFar());
//	AddSequential(new SetCoast());

//Pos 3 (port)
//	AddSequential(new AutoPortcullis());
////	AddSequential(new AutoRockWall(0.8, 5.0, 2.0));
//	AddSequential(new DriveStraightForDistance(8, -0.5, false));
////	AddSequential(new AutoTurn (18.5, true, .5, .47));
//	AddSequential(new AutoTurnSmallAngle(12.5, true));
//	AddSequential(new WaitCommand(.55));
//	AddSequential(new AutoTargetAndTurn());
////	AddSequential(new WaitCommand(.55));
////	AddSequential(new AutoTargetAndTurn());
//    AddSequential(new ShootFar());
//	AddSequential(new SetCoast());

//Pos 3 (cheval)
//	AddSequential(new AutoChevalDeFrise());
////	AddSequential(new AutoRockWall(0.8, 5.0, 2.0));
//	AddSequential(new DriveStraightForDistance(12, -0.5, false));
////	AddSequential(new AutoTurn (18.5, true, .5, .47));
//	AddSequential(new AutoTurnSmallAngle(18.5, true));
//	AddSequential(new WaitCommand(.55));
//	AddSequential(new AutoTargetAndTurn());
//	AddSequential(new ShootFar());
//	AddSequential(new SetCoast());

//Pos 3 ramparts
//	AddSequential(new AutoRockWall(0.75, 5.0, 2.0));
//	AddSequential(new DriveStraightForDistance(4.5, -0.5, false));
//	AddSequential(new WaitCommand(.55));
//	AddSequential(new AutoTurnSmallAngle(18.5, true));
//	AddSequential(new WaitCommand(.55));
//	AddSequential(new AutoTargetAndTurn());
//	AddSequential(new ShootFar());
//	AddSequential(new WaitCommand(1.5));//Shoot Sim
//	AddSequential(new AutoTurn(161.5, false, .50, .47, .0025));
//	AddSequential(new WaitCommand(.55));
//	AddSequential(new AutoRockWall(0.77, 5.0, 2.0));
//	AddSequential(new SetCoast());

//Pos 3 moat
//	AddSequential(new AutoRockWall(0.80, 5.0, 2.0));
//	AddSequential(new DriveStraightForDistance(4.5, -0.5, false));
//	AddSequential(new WaitCommand(.55));
//	AddSequential(new AutoTurnSmallAngle(18.5, true));
//	AddSequential(new WaitCommand(.55));
//	AddSequential(new AutoTargetAndTurn());
////	AddSequential(new ShootFar());
//	AddSequential(new WaitCommand(1.5));//Shoot Sim
//	AddSequential(new AutoTurn(161.5, false, .50, .47, .0025));
//	AddSequential(new WaitCommand(.55));
//	AddSequential(new AutoRockWall(0.80, 5.0, 2.0));
//	AddSequential(new SetCoast());
//Pos 4
//	AddSequential(new AutoRockWall(0.8, 5.0, 2.0));
//	AddSequential(new DriveStraightForDistance(4.5, -0.5, false));
////	AddSequential(new AutoTurn(357, true, .50, .47, .0025));
//	AddSequential(new AutoTurnSmallAngle(357, true));
//	AddSequential(new AutoTargetAndTurn());
//	AddSequential(new ShootFar());
//	AddSequential(new SetCoast());

//Pos 4 (port)
//	AddSequential(new AutoPortcullis());
//	AddSequential(new DriveStraightForDistance(4.5, -0.5, false));
////	AddSequential(new AutoTurn(357, true, .50, .47, .0025));
//	AddSequential(new AutoTurnSmallAngle(357, true));
//	AddSequential(new WaitCommand(.55));
//	AddSequential(new AutoTargetAndTurn());
//	AddSequential(new ShootFar());
//	AddSequential(new SetCoast());

//Pos 4 (cheval)
	AddSequential(new AutoChevalDeFrise());
	AddSequential(new DriveStraightForDistance(4.5, -0.5, false));
//	AddSequential(new AutoTurn(357, true, .50, .47, .0025));
	AddSequential(new AutoTurnSmallAngle(357, true));
	AddSequential(new WaitCommand(.55));
	AddSequential(new AutoTargetAndTurn());
	AddSequential(new ShootFar());
	AddSequential(new SetCoast());

//Pos 4 Ramparts
//	AddSequential(new AutoRockWall(0.75, 5.0, 2.0));
//	AddSequential(new DriveStraightForDistance(6, -0.5, false));
//	AddSequential(new AutoTurnSmallAngle(357, true));
//	AddSequential(new WaitCommand(.55));
//	AddSequential(new AutoTargetAndTurn());
////	AddSequential(new ShootFar());
//	AddSequential(new SetCoast());

//Pos 4 Moat
//	AddSequential(new AutoRockWall(0.8, 5.0, 2.0));
//	AddSequential(new DriveStraightForDistance(6, -0.5, false));
//	AddSequential(new AutoTurnSmallAngle(357, true));
//	AddSequential(new WaitCommand(.55));
//	AddSequential(new AutoTargetAndTurn());
////	AddSequential(new ShootFar());
//	AddSequential(new SetCoast());

//Pos 5
//	AddSequential(new DriveSmoothForDistance(4, -0.5, false));
////	AddSequential(new AutoTurn (335, true, 0.5, .450));
//	AddSequential(new AutoTurnSmallAngle(335, true));
//	AddSequential(new AutoTargetAndTurn());
//	AddSequential(new ShootFar());
//	AddSequential(new SetCoast());

//Pos 5 (port)
//	AddSequential(new AutoPortcullis());
//	AddSequential(new DriveStraightForDistance(7, -0.5, false));
////	AddSequential(new AutoTurn(335, true, .50, .47, .0025));
//	AddSequential(new AutoTurnSmallAngle(330, true));
//	AddSequential(new WaitCommand(.55));
//	AddSequential(new AutoTargetAndTurn(.055, .25));
////	AddSequential(new AutoTurnSmallAngle(359, true));
//	AddSequential(new ShootFar());
//	AddSequential(new SetCoast());

//Pos 5 (cheval)
//	AddSequential(new AutoChevalDeFrise());
//	AddSequential(new DriveStraightForDistance(4, -0.5, false));
////	AddSequential(new AutoTurn(335, true, .50, .47, .0025));
//	AddSequential(new AutoTurnSmallAngle(335, true));
//	AddSequential(new WaitCommand(.55));
//	AddSequential(new AutoTargetAndTurn());
//	AddSequential(new ShootFar());
//	AddSequential(new SetCoast());

//Pos 5 Ramparts
//	AddSequential(new AutoRockWall(0.75, 5.0, 2.0));
//	AddSequential(new DriveSmoothForDistance(6, -0.5, false));
//	AddSequential(new AutoTurnSmallAngle(327, true));
//	AddSequential(new WaitCommand(.55));
//	AddSequential(new DriveStraightForDistance(12, -.5, false));
//	AddSequential(new WaitCommand(.55));
//	AddSequential(new AutoTargetAndTurn());
//	AddSequential(new ShootFar());
//	AddSequential(new SetCoast());

//Pos 5 Moat
//	AddSequential(new AutoRockWall(0.80, 5.0, 2.0));
//	AddSequential(new DriveSmoothForDistance(6, -0.5, false));
//	AddSequential(new AutoTurnSmallAngle(327, true));
//	AddSequential(new WaitCommand(.55));
//	AddSequential(new DriveStraightForDistance(8, -.5, false));
//	AddSequential(new WaitCommand(.55));
//	AddSequential(new SetBrake());
//	AddSequential(new AutoTargetAndTurn());
////	AddSequential(new ShootFar());
//	AddSequential(new SetCoast());


}
