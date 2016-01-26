#ifndef DriveStraight_H
#define DriveStraight_H

#include "../../CommandBase.h"
#include "WPILib.h"

class DriveStraight: public CommandBase
{
private:
	double m_setpoint;

public:
	DriveStraight(double setpoint, double driveTime);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
