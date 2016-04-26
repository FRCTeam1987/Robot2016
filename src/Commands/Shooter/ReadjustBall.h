#ifndef ReadjustBall_H
#define ReadjustBall_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class ReadjustBall: public CommandGroup
{
public:
	ReadjustBall();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
//	Command* command1;
};

#endif
