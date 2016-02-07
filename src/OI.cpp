#include "OI.h"
#include "RobotMap.h"
#include "BroncoXbox.h"
#include "Commands/PrintStuff.h"
#include "Commands/DriveTrain/ResetEncoder.h"
#include "Commands/Shooter/SetIntake.h"

OI::OI()
{
//	stick = new BroncoXbox(0, 2, 2);
	stick = new BroncoJoy(0, 2, 2);
	printStuff = new JoystickButton(stick, PRINTSTUFFBUTTON);
	resetEncoder = new JoystickButton(stick, RESETENCODERBUTTON);
	forwardIntakeMotor = new JoystickButton(stick, FORWARDINTAKEMOTORBUTTON);
	reverseIntakeMotor = new JoystickButton(stick, REVERSEINTAKEMOTORBUTTON);
	stopIntakeMotor = new JoystickButton(stick, STOPINTAKEMOTORBUTTON);

	printStuff->WhenPressed(new PrintStuff());
	resetEncoder->WhenPressed(new ResetEncoder());
	forwardIntakeMotor->WhileHeld(new SetIntake(Shooter::kIntakeForward));
	forwardIntakeMotor->WhenReleased(new SetIntake(Shooter::kIntakeOff));
	reverseIntakeMotor->WhileHeld(new SetIntake(Shooter::kIntakeReverse));
	reverseIntakeMotor->WhenReleased(new SetIntake(Shooter::kIntakeOff));
	stopIntakeMotor->WhenPressed(new SetIntake(Shooter::kIntakeOff));
}

Joystick* OI::getStick()
{
	return (Joystick *)stick;
}
