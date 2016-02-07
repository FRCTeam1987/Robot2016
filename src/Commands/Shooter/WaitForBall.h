#ifndef WaitForBall_H
#define WaitForBall_H

#include "../../CommandBase.h"
#include "WPILib.h"

class WaitForBall: public CommandBase
{
public:
	WaitForBall();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
