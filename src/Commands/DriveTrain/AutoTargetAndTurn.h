#ifndef AutoTargetAndTurn_H
#define AutoTargetAndTurn_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class AutoTargetAndTurn: public CommandGroup
{
private:
//	float m_minAngleChange;
//	float m_angleTolerance;
public:
	AutoTargetAndTurn(float minAngleChange = 0.075, float angleTolerance = 0.25);
};

#endif
