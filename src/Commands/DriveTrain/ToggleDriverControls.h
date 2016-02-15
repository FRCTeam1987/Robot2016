#ifndef ToggleDriverControls_H
#define ToggleDriverControls_H

#include "../../CommandBase.h"
#include "WPILib.h"

class ToggleDriverControls: public CommandBase
{
public:
	ToggleDriverControls();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
