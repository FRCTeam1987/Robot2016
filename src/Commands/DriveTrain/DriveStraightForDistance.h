#ifndef DriveStraightForDistance_H
#define DriveStraightForDistance_H

#include "DriveStraightBase.h"
#include "WPILib.h"

class DriveStraightForDistance: public DriveStraightBase
{
private:
	double m_distance;
public:
	DriveStraightForDistance(double distance, double speed);
	void Initialize();
	bool IsFinished();
};

#endif
