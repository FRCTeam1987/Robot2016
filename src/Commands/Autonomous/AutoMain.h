#ifndef AutoMain_H
#define AutoMain_H

#include "../../CommandBase.h"
#include "WPILib.h"

#include "CommandObjects.h"
#include "AutoCommandObjects.h"

class AutoMain: public CommandBase
{

private:
	int command_number;
public:
	AutoMain();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

	CommandObjects *commandObjects;
	AutoCommandObjects *autoCommandObjects;
};

#endif
