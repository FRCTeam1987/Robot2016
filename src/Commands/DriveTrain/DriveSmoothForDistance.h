#ifndef DriveSmooth_H
#define DriveSmooth_H

#include "../../CommandBase.h"
#include "DriveStraightBase.h"
#include "WPILib.h"

class DriveSmoothForDistance: public DriveStraightBase
{
private:
	double m_distance;
	double m_speed;
	double m_easing;
	double m_minSpeed;
	double m_easingDistance;
	bool m_positiveDrive;
	bool m_reset;

public:
	DriveSmoothForDistance(double distance, double speed, double easing = 0.325, bool reset = true);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};


#endif
