#ifndef DriveStraight_H
#define DriveStraight_H

#include "../../CommandBase.h"
#include "WPILib.h"

class DriveStraight: public CommandBase
{
private:
	double m_setpoint;

public:
	DriveStraight(double m_setpoint);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
