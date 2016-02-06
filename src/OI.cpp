#include "OI.h"
#include "RobotMap.h"
#include "BroncoXbox.h"
#include "Commands/PrintStuff.h"
#include "Commands/DriveTrain/ResetEncoder.h"

OI::OI()
{
	stick = new BroncoXbox(0, 2, 2);
	printStuff = new JoystickButton(stick, PRINTSTUFFBUTTON);
	resetEncoder = new JoystickButton(stick, RESETENCODERBUTTON);

	printStuff->WhenPressed(new PrintStuff());
	resetEncoder->WhenPressed(new ResetEncoder());
}

Joystick* OI::getStick()
{
	return (Joystick *)stick;
}
