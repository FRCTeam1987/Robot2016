#ifndef DriveStraight_H
#define DriveStraight_H

#include "../../CommandBase.h"
#include "WPILib.h"

class DriveStraight: public CommandBase
{
private:
	double angleSetpoint;
	double distanceSetpoint;
	double motorSpeed;
public:
	DriveStraight(double angle, double distance,double motorSpeed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
