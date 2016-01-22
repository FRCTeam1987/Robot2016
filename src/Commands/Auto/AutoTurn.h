#ifndef AutoTurn_H
#define AutoTurn_H

#include "../../CommandBase.h"
#include "WPILib.h"

class AutoTurn: public CommandBase
{
public:
	AutoTurn();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
