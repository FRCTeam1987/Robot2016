#ifndef Rainbow_H
#define Rainbow_H

#include "../../CommandBase.h"
#include "WPILib.h"

#include "../../Subsystems/Lights.h"

class Rainbow: public CommandBase
{
public:
	Rainbow();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
};

#endif
