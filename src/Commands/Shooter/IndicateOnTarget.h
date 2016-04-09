#ifndef IndicateOnTarget_H
#define IndicateOnTarget_H

#include "../../CommandBase.h"
#include "WPILib.h"

class IndicateOnTarget: public CommandBase
{
public:
	IndicateOnTarget();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
