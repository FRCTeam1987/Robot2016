#ifndef SetCoast_H
#define SetCoast_H

#include "../../CommandBase.h"
#include "WPILib.h"

class SetCoast: public CommandBase
{
public:
	SetCoast();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
