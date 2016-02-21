#ifndef DriveStraightUntilRampSensor_H
#define DriveStraightUntilRampSensor_H

#include "DriveStraightBase.h"
#include "WPILib.h"

class DriveStraightUntilRampSensor: public DriveStraightBase
{
public:
	DriveStraightUntilRampSensor(double speed);
	bool IsFinished();
	void End();
};

#endif
