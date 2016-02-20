#ifndef ReadjustBallWithIntake_H
#define ReadjustBallWithIntake_H

#include "../../CommandBase.h"
#include "WPILib.h"

class ReadjustBallWithIntake: public CommandBase
{
public:
	ReadjustBallWithIntake();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
