#include "OI.h"
#include "RobotMap.h"
#include "BroncoXbox.h"
#include "Commands/PrintStuff.h"
#include "Commands/DriveTrain/AutoLowBar.h"
#include "Commands/DriveTrain/AutoRockWall.h"
#include "Commands/DriveTrain/AutoPortcullis.h"
#include "Commands/DriveTrain/AutoChevalDeFrise.h"
#include "Commands/DriveTrain/ToggleDriverControls.h"
#include "Commands/Shooter/SetIntake.h"
#include "Commands/Shooter/LoadBall.h"
#include "Commands/Shooter/WaitForBall.h"
#include "Commands/Shooter/SetShooterSpeed.h"
#include "Commands/Shooter/Shoot.h"
#include "Commands/Shooter/SetHoodPosition.h"
#include "Commands/Collector/SetArmPosition.h"
#include "Commands/Collector/SetCollectorSpeed.h"
#include "Commands/Collector/CollectBall.h"
#include "Commands/Shooter/ShootFar.h"
#include "Commands/Shooter/ShootClose.h"


OI::OI()
{
	setLayout(BUTTON_LAYOUT);
	xbox = new BroncoXbox(2, 2, 2, .075);
	stick = new BroncoJoy(0, 2, 2);
	m_btnBox = new Joystick(1);

	xbox->SetX(X_AXIS);
	xbox->SetY(Y_AXIS);

	//Xbox 360 (If you don't like it make your own layout.)
	hoodNearXbox = new JoystickButton(xbox, HOOD_NEAR_XBOXBUTTON);
	hoodMiddleXbox = new JoystickButton(xbox, HOOD_MIDDLE_XBOXBUTTON);
	collectorSafeXbox = new JoystickButton(xbox, COLLECTOR_SAFE_XBOXBUTTON);
	hoodFarXbox = new JoystickButton(xbox, HOOD_FAR_XBOXBUTTON);
	collectXbox = new JoystickButton(xbox, COLLECTOR_XBOXBUTTON);
	shootXbox = new JoystickButton(xbox, SHOOT_XBOXBUTTON);
	collectorGroundXbox = new JoystickButton(xbox, COLLECTOR_GROUND_XBOXBUTTON);
	toggleReverseXboxA = new JoystickButton(xbox, TOGGLE_DRIVE_DIRECTION_XBOXBUTTON_A);
	toggleReverseXboxB = new JoystickButton(xbox, TOGGLE_DRIVE_DIRECTION_XBOXBUTTON_B);
	toggleReverseXboxC = new JoystickButton(xbox, TOGGLE_DRIVE_DIRECTION_XBOXBUTTON_C);

//	resetEncoder = new JoystickButton(stick, RESETENCODERBUTTON);
	forwardIntakeMotor = new JoystickButton(m_btnBox, FORWARD_INTAKE_MOTOR_BUTTON);
//	reverseIntakeMotor = new JoystickButton(stick, REVERSEINTAKEMOTORBUTTON);
//	stopIntakeMotor = new JoystickButton(stick, STOPINTAKEMOTORBUTTON);
//	loadBall = new JoystickButton(stick, LOAD_BALL_BUTTON);
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
	toggleReverse = new JoystickButton(m_btnBox, TOGGLE_CONTROLS);


//	shootClose = new JoystickButton(m_btnBox, SHOOT_CLOSE_BUTTON);
//	shootFar = new JoystickButton(m_btnBox, SHOOT_FAR_BUTTON);
	printStuff = new JoystickButton(m_btnBox, PRINT_STUFF_BUTTON);
	autoTestDef = new JoystickButton(m_btnBox, AUTO_DRIVE_UNTIL_RAMP_SENSOR_BUTTON);
	autoPortcullis = new JoystickButton(m_btnBox, AUTO_PORTCULLIS_BUTTON);
	autoChevalDeFrise = new JoystickButton(m_btnBox, AUTO_CHEVAL_DEFRISE_BUTTON);
	autoRockWall = new JoystickButton(m_btnBox, AUTO_ROCK_WALL_BUTTON);

	//Xbox 360 (If you don't like it make your own layout.)
	hoodNearXbox->WhenPressed(new SetHoodPosition(Shooter::kNear));
	hoodMiddleXbox->WhenPressed(new SetHoodPosition(Shooter::kMiddle));
	collectorSafeXbox->WhenPressed(new SetArmPosition(Collector::kSafe));
	hoodFarXbox->WhenPressed(new SetHoodPosition(Shooter::kFar));
	collectXbox->WhenPressed(new CollectBall());
	shootXbox->WhenPressed(new Shoot());
	collectorGroundXbox->WhenPressed(new SetArmPosition(Collector::kGround));
	toggleReverseXboxA->WhenPressed(new ToggleDriverControls());
	toggleReverseXboxB->WhenPressed(new ToggleDriverControls());
	toggleReverseXboxC->WhenPressed(new ToggleDriverControls());

	printStuff->WhenPressed(new PrintStuff());
//	resetEncoder->WhenPressed(new ResetEncoder());
	forwardIntakeMotor->WhenPressed(new SetIntake(Shooter::kIntakeForward));
	forwardIntakeMotor->WhenReleased(new SetIntake(Shooter::kIntakeOff));
//	forwardIntakeMotor->WhenReleased(new SetIntake(Shooter::kIntakeOff));
//	reverseIntakeMotor->WhileHeld(new SetIntake(Shooter::kIntakeReverse));
//	reverseIntakeMotor->WhenReleased(new SetIntake(Shooter::kIntakeOff));
//	stopIntakeMotor->WhenPressed(new SetIntake(Shooter::kIntakeOff));
//	loadBall->WhenPressed(new LoadBall());
//	spinShooter->WhenPressed(new SetShooterSpeed(3500));
//	anotherSpinShooter->WhenPressed(new SetShooterSpeed(5000));
//	stopSpinShooter->WhenPressed(new SetShooterSpeed(0));
	shoot->WhenPressed(new Shoot());
	collectorGround->WhenPressed(new SetArmPosition(Collector::kGround));
	collectorCollect->WhenPressed(new SetArmPosition(Collector::kCollect));
	collectorSafe->WhenPressed(new SetArmPosition(Collector::kSafe));
	collectorMax->WhenPressed(new SetArmPosition(Collector::kMax));
	collectorRun->WhenPressed(new SetCollectorSpeed(.15));
	collectorRun->WhenReleased(new SetCollectorSpeed(0));
	collectBall->WhenPressed(new CollectBall());
	hoodNear->WhenPressed(new SetHoodPosition(Shooter::kNear));
	hoodMiddle->WhenPressed(new SetHoodPosition(Shooter::kMiddle));
	hoodFar->WhenPressed(new SetHoodPosition(Shooter::kFar));
	autoChevalDeFrise->WhenPressed(new AutoChevalDeFrise());
	autoPortcullis->WhenPressed(new AutoPortcullis());
	autoRockWall->WhenPressed(new AutoRockWall());
	toggleReverse->WhenPressed(new ToggleDriverControls());


	//shootClose->WhenPressed(new ShootClose());
	//shootFar->WhenPressed(new ShootFar());
}

void OI::setLayout(LayoutType layout)
{
	switch(layout)
	{
	case kGTADrive:
		HOOD_NEAR_XBOXBUTTON = BroncoXbox::Button::A;
		HOOD_MIDDLE_XBOXBUTTON = BroncoXbox::Button::B;
		COLLECTOR_SAFE_XBOXBUTTON = BroncoXbox::Button::X;
		HOOD_FAR_XBOXBUTTON = BroncoXbox::Button::Y;
		COLLECTOR_XBOXBUTTON = BroncoXbox::Button::LB;
		SHOOT_XBOXBUTTON = BroncoXbox::Button::RB;
		COLLECTOR_GROUND_XBOXBUTTON = BroncoXbox::Button::BACK;
		TOGGLE_DRIVE_DIRECTION_XBOXBUTTON_A = BroncoXbox::Button::START;
		TOGGLE_DRIVE_DIRECTION_XBOXBUTTON_B = BroncoXbox::Button::LSB;
		TOGGLE_DRIVE_DIRECTION_XBOXBUTTON_C = BroncoXbox::Button::RSB;
		X_AXIS = BroncoXbox::Axis::LS_X;
		Y_AXIS = BroncoXbox::Axis::TRIGGERS;
		break;
	case kSpencerDrive:
		HOOD_NEAR_XBOXBUTTON = BroncoXbox::Button::Y;
		HOOD_MIDDLE_XBOXBUTTON = BroncoXbox::Button::B;
		COLLECTOR_SAFE_XBOXBUTTON = BroncoXbox::Button::X;
		HOOD_FAR_XBOXBUTTON = BroncoXbox::Button::A;
		COLLECTOR_XBOXBUTTON = BroncoXbox::Button::LB;
		SHOOT_XBOXBUTTON = BroncoXbox::Button::RB;
		COLLECTOR_GROUND_XBOXBUTTON = BroncoXbox::Button::BACK;
		TOGGLE_DRIVE_DIRECTION_XBOXBUTTON_A = BroncoXbox::Button::START;
		TOGGLE_DRIVE_DIRECTION_XBOXBUTTON_B = BroncoXbox::Button::LSB;
		TOGGLE_DRIVE_DIRECTION_XBOXBUTTON_C = BroncoXbox::Button::RSB;
		X_AXIS = BroncoXbox::Axis::LS_X;
		Y_AXIS = BroncoXbox::Axis::TRIGGERS;
		break;
	case kLucasDrive:
		HOOD_NEAR_XBOXBUTTON = BroncoXbox::Button::A;
		HOOD_MIDDLE_XBOXBUTTON = BroncoXbox::Button::B;
		COLLECTOR_SAFE_XBOXBUTTON = BroncoXbox::Button::X;
		HOOD_FAR_XBOXBUTTON = BroncoXbox::Button::Y;
		COLLECTOR_XBOXBUTTON = BroncoXbox::Button::LB;
		SHOOT_XBOXBUTTON = BroncoXbox::Button::RB;
		COLLECTOR_GROUND_XBOXBUTTON = BroncoXbox::Button::BACK;
		TOGGLE_DRIVE_DIRECTION_XBOXBUTTON_A = BroncoXbox::Button::START;
		TOGGLE_DRIVE_DIRECTION_XBOXBUTTON_B = BroncoXbox::Button::LSB;
		TOGGLE_DRIVE_DIRECTION_XBOXBUTTON_C = BroncoXbox::Button::RSB;
		X_AXIS = BroncoXbox::Axis::RS_X;
		Y_AXIS = BroncoXbox::Axis::LS_Y;
		break;
	}
	return;
}

Joystick* OI::getStick()
{
	return stick;
}
Joystick* OI::getXbox()
{
	return xbox;
}
Joystick* OI::getBtnBox()
{
	return m_btnBox;
}
