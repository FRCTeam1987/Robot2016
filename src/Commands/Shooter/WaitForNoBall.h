#ifndef WaitForNoBall_H
#define WaitForNoBall_H

#include "../../CommandBase.h"
#include "WPILib.h"

class WaitForNoBall: public CommandBase
{
public:
	WaitForNoBall();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
