#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "Broncojoy.h"

class OI
{
private:
	BroncoJoy *stick;
	JoystickButton *printStuff;
	JoystickButton *resetEncoder;
	JoystickButton *forwardIntakeMotor;
	JoystickButton *reverseIntakeMotor;
	JoystickButton *stopIntakeMotor;

public:
	OI();
	Joystick *getStick();
};

#endif
