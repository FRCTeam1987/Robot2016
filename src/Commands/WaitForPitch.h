#ifndef WaitForPitch_H
#define WaitForPitch_H

#include "../CommandBase.h"
#include "WPILib.h"

class WaitForPitch: public CommandBase
{
public:
	WaitForPitch();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
