#ifndef SetLights_H
#define SetLights_H

#include "../../CommandBase.h"
#include "WPILib.h"

#include "../../Subsystems/Lights.h"

class SetLights: public CommandBase
{
public:
	SetLights(Lights::COLOR c);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	int m_color;
};

#endif
