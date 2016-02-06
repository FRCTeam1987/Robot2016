#ifndef SetBrake_H
#define SetBrake_H

#include "../../CommandBase.h"
#include "WPILib.h"

class SetBrake: public CommandBase
{
public:
	SetBrake();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
