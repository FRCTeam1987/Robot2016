#ifndef DriveStraightAfterRampSensor_H
#define DriveStraightAfterRampSensor_H

#include "DriveStraightBase.h"
#include "WPILib.h"

class DriveStraightAfterRampSensor: public DriveStraightBase
{
public:
	DriveStraightAfterRampSensor(double speed);
	bool IsFinished();
};

#endif
