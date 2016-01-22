#ifndef AutoDrive_H
#define AutoDrive_H

#include "../../CommandBase.h"
#include "WPILib.h"

class AutoDrive: public CommandBase
{
public:
	AutoDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
