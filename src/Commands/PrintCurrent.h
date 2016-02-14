#ifndef PrintCurrent_H
#define PrintCurrent_H

#include "../CommandBase.h"
#include "WPILib.h"

class PrintCurrent: public CommandBase
{
public:
	PrintCurrent();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
