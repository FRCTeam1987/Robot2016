#ifndef BlinkLights_H
#define BlinkLights_H

#include "../../CommandBase.h"
#include "WPILib.h"

class BlinkLights: public CommandBase
{
public:
	BlinkLights();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
