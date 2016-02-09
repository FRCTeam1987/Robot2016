#include "OI.h"
#include "RobotMap.h"
#include "BroncoXbox.h"
#include "Commands/PrintStuff.h"
#include "Commands/DriveTrain/ResetEncoder.h"
#include "Commands/Shooter/SetIntake.h"
#include "Commands/Shooter/LoadBall.h"
#include "Commands/Shooter/WaitForBall.h"
#include "Commands/Shooter/SetShooterSpeed.h"
#include "Commands/Shooter/Shoot.h"

OI::OI()
{
//	stick = new BroncoXbox(0, 2, 2);
	stick = new BroncoJoy(0, 2, 2);
	printStuff = new JoystickButton(stick, PRINTSTUFFBUTTON);
	resetEncoder = new JoystickButton(stick, RESETENCODERBUTTON);
	forwardIntakeMotor = new JoystickButton(stick, FORWARDINTAKEMOTORBUTTON);
	reverseIntakeMotor = new JoystickButton(stick, REVERSEINTAKEMOTORBUTTON);
	stopIntakeMotor = new JoystickButton(stick, STOPINTAKEMOTORBUTTON);
	loadBall = new JoystickButton(stick, LOADBALLBUTTON);
	spinShooter = new JoystickButton(stick, SPINSHOOTERBUTTON);
	anotherSpinShooter = new JoystickButton(stick, FASTSHOOTERBUTTON);
	stopSpinShooter = new JoystickButton(stick, STOPSHOOTERBUTTON);
	shoot = new JoystickButton(stick, SHOOTBUTTON);

	printStuff->WhenPressed(new PrintStuff());
	resetEncoder->WhenPressed(new ResetEncoder());
	forwardIntakeMotor->WhileHeld(new SetIntake(Shooter::kIntakeForward));
	forwardIntakeMotor->WhenReleased(new SetIntake(Shooter::kIntakeOff));
	reverseIntakeMotor->WhileHeld(new SetIntake(Shooter::kIntakeReverse));
	reverseIntakeMotor->WhenReleased(new SetIntake(Shooter::kIntakeOff));
	stopIntakeMotor->WhenPressed(new SetIntake(Shooter::kIntakeOff));
	loadBall->WhenPressed(new LoadBall());
	spinShooter->WhenPressed(new SetShooterSpeed(3500));
	anotherSpinShooter->WhenPressed(new SetShooterSpeed(5000));
	stopSpinShooter->WhenPressed(new SetShooterSpeed(0));
	shoot->WhenPressed(new Shoot());
}

Joystick* OI::getStick()
{
	return (Joystick *)stick;
}
