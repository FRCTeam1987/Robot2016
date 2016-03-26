#ifndef AutoTarget_H
#define AutoTarget_H

#include "../../CommandBase.h"
#include "WPILib.h"

class AutoTarget: public CommandBase
{
public:
	AutoTarget();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
