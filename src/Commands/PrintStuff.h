#ifndef PrintStuff_H
#define PrintStuff_H

#include "../CommandBase.h"
#include "WPILib.h"

class PrintStuff: public CommandBase
{
public:
	PrintStuff();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
