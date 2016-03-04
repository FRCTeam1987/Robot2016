#ifndef CheckArmPosition_H
#define CheckArmPosition_H

#include "../../CommandBase.h"
#include "WPILib.h"

class CheckArmPosition: public CommandBase
{
private:
	Collector::ArmPosition m_position;

public:
	CheckArmPosition();
	CheckArmPosition(Collector::ArmPosition position);
	void setPosition(Collector::ArmPosition position);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
