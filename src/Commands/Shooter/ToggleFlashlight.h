#ifndef ToggleFlashlight_H
#define ToggleFlashlight_H

#include "../../CommandBase.h"
#include "WPILib.h"

class ToggleFlashlight: public CommandBase
{
public:
	ToggleFlashlight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
