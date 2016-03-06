#ifndef DriveStraightForDistance_H
#define DriveStraightForDistance_H

#include "DriveStraightBase.h"
#include "WPILib.h"

class DriveStraightForDistance: public DriveStraightBase
{
private:
	double m_distance;
	float m_angleSetpoint;

public:
	DriveStraightForDistance(double distance, double speed, float angleSetpoint = 0.0);
	void Initialize();
	bool IsFinished();
};

#endif
