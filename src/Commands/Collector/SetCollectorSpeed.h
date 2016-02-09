#ifndef SetCollectorSpeed_H
#define SetCollectorSpeed_H

#include "../../CommandBase.h"
#include "WPILib.h"

class SetCollectorSpeed: public CommandBase
{
private:
	float m_speed;
public:
	SetCollectorSpeed(float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
