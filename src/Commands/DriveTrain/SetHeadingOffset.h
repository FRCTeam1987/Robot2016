#ifndef SetHeadingOffset_H
#define SetHeadingOffset_H

#include "../../CommandBase.h"
#include "WPILib.h"

class SetHeadingOffset: public CommandBase
{
public:
	SetHeadingOffset();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
