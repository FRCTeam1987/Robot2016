#ifndef DriveByEncoder_H
#define DriveByEncoder_H

#include "../../CommandBase.h"
#include "WPILib.h"

class DriveByEncoder: public CommandBase
{
public:
	DriveByEncoder();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
