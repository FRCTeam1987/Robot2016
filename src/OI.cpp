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
#include "Commands/Shooter/SetHoodPosition.h"
#include "Commands/Collector/SetArmPosition.h"
#include "Commands/Collector/SetCollectorSpeed.h"
#include "Commands/Collector/CollectBall.h"

OI::OI()
{
//	stick = new BroncoXbox(0, 2, 2);
	stick = new BroncoJoy(0, 2, 2);
//	printStuff = new JoystickButton(stick, PRINT_STUFF_BUTTON);
//	resetEncoder = new JoystickButton(stick, RESETENCODERBUTTON);
//	forwardIntakeMotor = new JoystickButton(stick, FORWARDINTAKEMOTORBUTTON);
//	reverseIntakeMotor = new JoystickButton(stick, REVERSEINTAKEMOTORBUTTON);
//	stopIntakeMotor = new JoystickButton(stick, STOPINTAKEMOTORBUTTON);
	loadBall = new JoystickButton(stick, LOAD_BALL_BUTTON);
//	spinShooter = new JoystickButton(stick, SPINSHOOTERBUTTON);
//	anotherSpinShooter = new JoystickButton(stick, FASTSHOOTERBUTTON);
//	stopSpinShooter = new JoystickButton(stick, STOPSHOOTERBUTTON);
	shoot = new JoystickButton(stick, SHOOT_BUTTON);
	collectorGround = new JoystickButton(stick, COLLECTOR_GROUND_BUTTON);
	collectorCollect = new JoystickButton(stick, COLLECTOR_COLLECT_BUTTON);
	collectorSafe = new JoystickButton(stick, COLLECTOR_SAFE_BUTTON);
	collectorMax = new JoystickButton(stick, COLLECTOR_MAX_BUTTON);
	collectorRun = new JoystickButton(stick, RUN_COLLECTOR_BUTTON);
	collectBall = new JoystickButton(stick, COLLECT_BALL_BUTTON);
	hoodNear = new JoystickButton(stick, HOOD_NEAR_BUTTON);
	hoodMiddle = new JoystickButton(stick, HOOD_MIDDLE_BUTTON);
	hoodFar = new JoystickButton(stick, HOOD_FAR_BUTTON);

//	printStuff->WhenPressed(new PrintStuff());
//	resetEncoder->WhenPressed(new ResetEncoder());
//	forwardIntakeMotor->WhileHeld(new SetIntake(Shooter::kIntakeForward));
//	forwardIntakeMotor->WhenReleased(new SetIntake(Shooter::kIntakeOff));
//	reverseIntakeMotor->WhileHeld(new SetIntake(Shooter::kIntakeReverse));
//	reverseIntakeMotor->WhenReleased(new SetIntake(Shooter::kIntakeOff));
//	stopIntakeMotor->WhenPressed(new SetIntake(Shooter::kIntakeOff));
	loadBall->WhenPressed(new LoadBall());
//	spinShooter->WhenPressed(new SetShooterSpeed(3500));
//	anotherSpinShooter->WhenPressed(new SetShooterSpeed(5000));
//	stopSpinShooter->WhenPressed(new SetShooterSpeed(0));
	shoot->WhenPressed(new Shoot());
	collectorGround->WhenPressed(new SetArmPosition(Collector::kGround));
	collectorCollect->WhenPressed(new SetArmPosition(Collector::kCollect));
	collectorSafe->WhenPressed(new SetArmPosition(Collector::kSafe));
	collectorMax->WhenPressed(new SetArmPosition(Collector::kMax));
	collectorRun->WhenPressed(new SetCollectorSpeed(.25));
	collectorRun->WhenReleased(new SetCollectorSpeed(0));
	collectBall->WhenPressed(new CollectBall());
	hoodNear->WhenPressed(new SetHoodPosition(Shooter::kNear));
	hoodMiddle->WhenPressed(new SetHoodPosition(Shooter::kMiddle));
	hoodFar->WhenPressed(new SetHoodPosition(Shooter::kFar));
}

Joystick* OI::getStick()
{
	return (Joystick *)stick;
}
