#ifndef ReadjustBall_H
#define ReadjustBall_H

#include "../../CommandBase.h"
#include "WPILib.h"

class ReadjustBall: public CommandBase
{
public:
	ReadjustBall();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
