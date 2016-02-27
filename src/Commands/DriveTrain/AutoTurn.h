#ifndef AutoTurn_H
#define AutoTurn_H

#include "../../CommandBase.h"
#include "WPILib.h"

class AutoTurn: public CommandBase
{
private:
	double m_angle;
	double m_turnAngleAdjust;
	bool m_clockWise;

public:
	AutoTurn(double angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
