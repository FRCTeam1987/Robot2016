#ifndef WaitForOuterWorks_H
#define WaitForOuterWorks_H

#include "../../CommandBase.h"
#include "WPILib.h"

class WaitForOuterWorks: public CommandBase
{
public:
	WaitForOuterWorks();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
