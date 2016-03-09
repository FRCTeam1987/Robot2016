#ifndef SetFlashLight_H
#define SetFlashLight_H

#include "../../CommandBase.h"
#include "WPILib.h"

class SetFlashLight: public CommandBase
{
private:
	bool m_onOff;
public:
	SetFlashLight(bool onOff);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
