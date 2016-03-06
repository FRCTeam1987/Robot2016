#ifndef LightsOff_H
#define LightsOff_H

#include "../../CommandBase.h"
#include "WPILib.h"

class LightsOff: public CommandBase
{
public:
	LightsOff();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
