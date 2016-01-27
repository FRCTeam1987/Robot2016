#ifndef AutoTurn_H
#define AutoTurn_H

#include "../../CommandBase.h"
#include "WPILib.h"

class AutoTurn: public CommandBase
{
private:
	double m_setpoint;
public:
	AutoTurn(double setpoint);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
