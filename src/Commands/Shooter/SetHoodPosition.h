#ifndef SetHoodPosition_H
#define SetHoodPosition_H

#include "../../CommandBase.h"
#include "WPILib.h"

class SetHoodPosition: public CommandBase
{
private:
	Shooter::HoodPosition m_position;

public:
	SetHoodPosition(Shooter::HoodPosition position);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
