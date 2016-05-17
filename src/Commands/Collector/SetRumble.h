#ifndef SetRumble_H
#define SetRumble_H

#include "../../CommandBase.h"
#include "WPILib.h"

class SetRumble: public CommandBase
{
public:
	SetRumble();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
