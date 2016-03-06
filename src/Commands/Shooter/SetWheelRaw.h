#ifndef SetWheelRaw_H
#define SetWheelRaw_H

#include "../../CommandBase.h"
#include "WPILib.h"

class SetWheelRaw: public CommandBase
{
private:
	float m_speed;

public:
	SetWheelRaw(float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
