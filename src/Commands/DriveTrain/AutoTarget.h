#ifndef AutoTarget_H
#define AutoTarget_H

#include "../../CommandBase.h"
#include "WPILib.h"

class AutoTarget: public CommandBase
{
private:
	const double GOAL_WIDTH_INCHES = 20;
	const double GOAL_HEIGHT_INCHES = 12;
	const unsigned int IMAGE_RESOLUTION = 320;
	const double HORIZONTAL_FOV = 54.8; //54.8

public:
	AutoTarget();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	double DegreesToRadians(double degrees);
	bool IsBlobTargetRatio(double tWidth, double tHeight, double tolerance = 1.1);
};

#endif
