#include "OI.h"
#include "RobotMap.h"
#include "BroncoJoy.h"
#include "Commands/PrintStuff.h"

OI::OI()
{
	stick = new BroncoJoy(0);
	printStuff = new JoystickButton(stick, PRINTSTUFFBUTTON);

	printStuff->WhenPressed(new PrintStuff);
}

Joystick* OI::getStick()
{
	return (Joystick *)stick;
}


