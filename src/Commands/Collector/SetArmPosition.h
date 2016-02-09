#ifndef SetArmPosition_H
#define SetArmPosition_H

#include "../../CommandBase.h"
#include "WPILib.h"

class SetArmPosition: public CommandBase
{
private:
	Collector::ArmPosition m_position;

public:
	SetArmPosition(Collector::ArmPosition position);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
