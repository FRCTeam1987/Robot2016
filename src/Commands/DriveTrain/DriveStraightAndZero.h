#ifndef DriveStraightAndZero_H
#define DriveStraightAndZero_H

#include "Commands/CommandGroup.h"
#include "SetBrake.h"
#include "SetCoast.h"
#include "DriveStraightForDistance.h"
#include "AutoTurn.h"
#include "AutoTurnPID.h"
#include "WPILib.h"

class DriveStraightAndZero: public CommandGroup
{
public:
	DriveStraightAndZero();
};

#endif
