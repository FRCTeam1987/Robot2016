#ifndef AutoTurn_H
#define AutoTurn_H

#include "../../CommandBase.h"
#include "WPILib.h"

class AutoTurn: public CommandBase
{
private:
	double m_angle;
	double m_turnAngleAdjust;
	float m_headingChange;
	float m_baseTurnSpeed;
	float m_adjustSpeed;
	bool m_clockWise;
	bool m_reset;

public:
	AutoTurn(double angle, bool reset = false);
	void setAngle(double angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
