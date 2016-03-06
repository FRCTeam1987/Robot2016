#ifndef AutoTurnHeading_H
#define AutoTurnHeading_H

#include "../../CommandBase.h"
#include "WPILib.h"

class AutoTurnHeading: public CommandBase
{
private:
	float m_headingChange;
	float m_headingSetpoint;
	float m_actualTolerance;
	float m_speed;

public:
	AutoTurnHeading(float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
