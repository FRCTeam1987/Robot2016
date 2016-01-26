#include "OI.h"
#include "RobotMap.h"
#include "BroncoJoy.h"
#include "Commands/PrintStuff.h"
#include "Commands/DriveTrain/ResetEncoder.h"

OI::OI()
{
	stick = new BroncoJoy(0);
	printStuff = new JoystickButton(stick, PRINTSTUFFBUTTON);
	resetEncoder = new JoystickButton(stick, RESETENCODERBUTTON);

	printStuff->WhenPressed(new PrintStuff());
	resetEncoder->WhenPressed(new ResetEncoder());
}

Joystick* OI::getStick()
{
	return (Joystick *)stick;
}


