#ifndef AutoTurnPID_H
#define AutoTurnPID_H

#include "../../CommandBase.h"
#include "WPILib.h"

class AutoTurnPID: public CommandBase
{
private:
	double m_angle;
	bool m_reset;
public:
	AutoTurnPID(double angle = 0, bool reset = true);
	void setAngle(double angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
