#include "DriveStraightAndZero.h"
#include "StopDrive.h"
#include "../Shooter/SetHoodPosition.h"


DriveStraightAndZero::DriveStraightAndZero()
{
	AddSequential(new SetBrake());
	AddSequential(new DriveStraightForDistance(0, 0));
	AddSequential(new StopDrive());
	AddSequential(new WaitCommand(.1));
	AddSequential(new AutoTurnPID());
}
