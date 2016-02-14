#ifndef ReadJoystickSlider_H
#define ReadJoystickSlider_H

#include "../../CommandBase.h"
#include "WPILib.h"

class ReadJoystickSlider: public CommandBase
{
public:
	ReadJoystickSlider();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
