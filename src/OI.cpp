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
#include "Commands/Shooter/LineUpBatterShot.h"
#include "Commands/Shooter/ReadjustBall.h"
#include "Commands/Collector/SetArmPosition.h"
#include "Commands/Collector/SetCollectorSpeed.h"
#include "Commands/Collector/CollectBall.h"
#include "Commands/Collector/StopIntakeAndCollector.h"
#include "Commands/Shooter/ShootFar.h"
#include "Commands/Shooter/ShootClose.h"


OI::OI()
{
	setLayout(BUTTON_LAYOUT);

	stick = new BroncoJoy(0, 2, 2);
	xbox = new BroncoXbox(2, 2, 2, .075);

	m_btnBox = new Joystick(1);

	if(IS_USING_JOYSTICK){

		/* ******************** JOYSTICK CONTROL MAPPING ******************** */
		hoodNearXbox = new JoystickButton(stick, HOOD_NEAR_BUTTON);
		hoodMiddleXbox = new JoystickButton(stick, HOOD_MIDDLE_BUTTON);
		hoodFarXbox = new JoystickButton(stick, HOOD_FAR_BUTTON);
		collectXbox = new JoystickButton(stick, COLLECTOR_BUTTON);
		stopCollectXbox = new JoystickButton(stick, STOP_COLLECT_BUTTON);
		shootXbox = new JoystickButton(stick, SHOOT_BUTTON);
		collectorGroundXbox = new JoystickButton(stick, COLLECTOR_GROUND_BUTTON);
		collectorCollectXbox = new JoystickButton(stick, COLLECTOR_COLLECT_BUTTON);
		collectorSafeXbox = new JoystickButton(stick, COLLECTOR_SAFE_BUTTON);
		collectorMaxXbox = new JoystickButton(stick, COLLECTOR_MAX_BUTTON);
		toggleReverseXboxA = new JoystickButton(stick, TOGGLE_DRIVE_DIRECTION_BUTTON_A);
		lineUpBatterShotXbox = new JoystickButton(stick, LINE_UP_BATTER_SHOT_BUTTON);
	}else{
		/* ******************** XBOX CONTROL MAPPING ******************** */
		xbox->SetX(X_AXIS);
		xbox->SetY(Y_AXIS);
		hoodNearXbox = new BroncoXboxButton(xbox, HOOD_NEAR_XBOXBUTTON);
		hoodMiddleXbox = new BroncoXboxButton(xbox, HOOD_MIDDLE_XBOXBUTTON);
		hoodFarXbox = new BroncoXboxButton(xbox, HOOD_FAR_XBOXBUTTON);
		collectXbox = new BroncoXboxButton(xbox, COLLECTOR_XBOXBUTTON);
		stopCollectXbox = new BroncoXboxButton(xbox, STOP_COLLECT_XBOXBUTTON);
		shootXbox = new BroncoXboxButton(xbox, SHOOT_XBOXBUTTON);
		collectorGroundXbox = new BroncoXboxButton(xbox, COLLECTOR_GROUND_XBOXBUTTON);
		collectorCollectXbox = new BroncoXboxButton(xbox, COLLECTOR_COLLECT_XBOXBUTTON);
		collectorSafeXbox = new BroncoXboxButton(xbox, COLLECTOR_SAFE_XBOXBUTTON);
		collectorMaxXbox = new BroncoXboxButton(xbox, COLLECTOR_MAX_XBOXBUTTON);
		toggleReverseXboxA = new BroncoXboxButton(xbox, TOGGLE_DRIVE_DIRECTION_XBOXBUTTON_A);
		lineUpBatterShotXbox = new BroncoXboxButton(xbox, LINE_UP_BATTER_SHOT_XBOXBUTTON);
	}


	forwardIntakeMotor = new JoystickButton(m_btnBox, FORWARD_INTAKE_MOTOR_BUTTON);
//	toggleReverse = new JoystickButton(m_btnBox, TOGGLE_CONTROLS);

	printStuff = new JoystickButton(m_btnBox, PRINT_STUFF_BUTTON);
	autoTestDef = new JoystickButton(m_btnBox, AUTO_DRIVE_UNTIL_RAMP_SENSOR_BUTTON);
	autoPortcullis = new JoystickButton(m_btnBox, AUTO_PORTCULLIS_BUTTON);
	autoChevalDeFrise = new JoystickButton(m_btnBox, AUTO_CHEVAL_DEFRISE_BUTTON);
	autoRockWall = new JoystickButton(m_btnBox, AUTO_ROCK_WALL_BUTTON);
	autoLowBar = new JoystickButton(m_btnBox, AUTO_ROCK_WALL_BUTTON);
	readjustBall = new JoystickButton(m_btnBox, READJUST_BALL_BUTTON);

	hoodNearXbox->WhenPressed(new SetHoodPosition(Shooter::kNear));
	hoodMiddleXbox->WhenPressed(new SetHoodPosition(Shooter::kMiddle));
	hoodFarXbox->WhenPressed(new SetHoodPosition(Shooter::kFar));
	collectXbox->WhenPressed(new CollectBall());
	stopCollectXbox->WhenPressed(new StopIntakeAndCollector());
	shootXbox->WhenPressed(new Shoot());
	collectorGroundXbox->WhenPressed(new SetArmPosition(Collector::kGround));
	collectorCollectXbox->WhenPressed(new SetArmPosition(Collector::kCollect));
	collectorSafeXbox->WhenPressed(new SetArmPosition(Collector::kSafe));
	collectorMaxXbox->WhenPressed(new SetArmPosition(Collector::kMax));
	toggleReverseXboxA->WhenPressed(new ToggleDriverControls());
//	lineUpBatterShotXbox->WhenPressed(new LineUpBatterShot());

	printStuff->WhenPressed(new PrintStuff());
	forwardIntakeMotor->WhenPressed(new SetIntake(Shooter::kIntakeForward));
	forwardIntakeMotor->WhenReleased(new SetIntake(Shooter::kIntakeOff));
	autoChevalDeFrise->WhenPressed(new AutoChevalDeFrise());
	autoPortcullis->WhenPressed(new AutoPortcullis());
	autoRockWall->WhenPressed(new AutoRockWall());
	autoLowBar->WhenPressed(new AutoLowBar());
//	readjustBall->WhenPressed(new ReadjustBall());

//	shoot->WhenPressed(new Shoot());
//	collectorGround->WhenPressed(new SetArmPosition(Collector::kGround));
//	collectorCollect->WhenPressed(new SetArmPosition(Collector::kCollect));
//	collectorSafe->WhenPressed(new SetArmPosition(Collector::kSafe));
//	collectorMax->WhenPressed(new SetArmPosition(Collector::kMax));
//	collectorRun->WhenPressed(new SetCollectorSpeed(.15));
//	collectorRun->WhenReleased(new SetCollectorSpeed(0));
//	collectBall->WhenPressed(new CollectBall());
//	hoodNear->WhenPressed(new SetHoodPosition(Shooter::kNear));
//	hoodMiddle->WhenPressed(new SetHoodPosition(Shooter::kMiddle));
//	hoodFar->WhenPressed(new SetHoodPosition(Shooter::kFar));
//	toggleReverse->WhenPressed(new ToggleDriverControls());
}

void OI::setLayout(LayoutType layout)
{
	switch(layout)
	{
	case kGTADrive:
		IS_USING_JOYSTICK = false;
		HOOD_NEAR_XBOXBUTTON = BroncoXboxButton::Button::A;
		HOOD_MIDDLE_XBOXBUTTON = BroncoXboxButton::Button::B;
		COLLECTOR_SAFE_XBOXBUTTON = BroncoXboxButton::Button::X;
		HOOD_FAR_XBOXBUTTON = BroncoXboxButton::Button::Y;
		COLLECTOR_XBOXBUTTON = BroncoXboxButton::Button::LB;
		SHOOT_XBOXBUTTON = BroncoXboxButton::Button::RB;
		COLLECTOR_GROUND_XBOXBUTTON = BroncoXboxButton::Button::BACK;
		COLLECTOR_COLLECT_XBOXBUTTON = BroncoXboxButton::Button::UNASSIGNED;
		COLLECTOR_MAX_XBOXBUTTON = BroncoXboxButton::Button::UNASSIGNED;
		TOGGLE_DRIVE_DIRECTION_XBOXBUTTON_A = BroncoXboxButton::Button::START;
		X_AXIS = BroncoXbox::Axis::LS_X;
		Y_AXIS = BroncoXbox::Axis::TRIGGERS;
		break;
	case kSpencerDrive:
		IS_USING_JOYSTICK = false;
		HOOD_NEAR_XBOXBUTTON = BroncoXboxButton::Button::A;
		HOOD_MIDDLE_XBOXBUTTON = BroncoXboxButton::Button::UNASSIGNED;
		HOOD_FAR_XBOXBUTTON = BroncoXboxButton::Button::Y;
		STOP_COLLECT_XBOXBUTTON = BroncoXboxButton::Button::B;
		COLLECTOR_XBOXBUTTON = BroncoXboxButton::Button::X;
		SHOOT_XBOXBUTTON = BroncoXboxButton::Button::LB;
		COLLECTOR_GROUND_XBOXBUTTON = BroncoXboxButton::Button::D_D;
		COLLECTOR_COLLECT_XBOXBUTTON = BroncoXboxButton::Button::D_R;
		COLLECTOR_SAFE_XBOXBUTTON = BroncoXboxButton::Button::D_L;
		COLLECTOR_MAX_XBOXBUTTON = BroncoXboxButton::Button::D_U;
		TOGGLE_DRIVE_DIRECTION_XBOXBUTTON_A = BroncoXboxButton::Button::LSB;
		LINE_UP_BATTER_SHOT_XBOXBUTTON = BroncoXboxButton::Button::RB;
		X_AXIS = BroncoXbox::Axis::LS_X;
		Y_AXIS = BroncoXbox::Axis::TRIGGERS;
		break;
	case kLucasDrive:
		IS_USING_JOYSTICK = false;
		HOOD_NEAR_XBOXBUTTON = BroncoXboxButton::Button::A;
		HOOD_MIDDLE_XBOXBUTTON = BroncoXboxButton::Button::X;
		HOOD_FAR_XBOXBUTTON = BroncoXboxButton::Button::Y;
		COLLECTOR_XBOXBUTTON = BroncoXboxButton::Button::LB;
		STOP_COLLECT_XBOXBUTTON = BroncoXboxButton::Button::B;
		SHOOT_XBOXBUTTON = BroncoXboxButton::Button::RT;
		LINE_UP_BATTER_SHOT_XBOXBUTTON = BroncoXboxButton::Button::LT;
		COLLECTOR_GROUND_XBOXBUTTON = BroncoXboxButton::Button::D_D;
		COLLECTOR_COLLECT_XBOXBUTTON = BroncoXboxButton::Button::D_R;
		COLLECTOR_SAFE_XBOXBUTTON = BroncoXboxButton::Button::D_U;
		COLLECTOR_MAX_XBOXBUTTON = BroncoXboxButton::Button::D_L;
		TOGGLE_DRIVE_DIRECTION_XBOXBUTTON_A = BroncoXboxButton::Button::START;
		X_AXIS = BroncoXbox::Axis::RS_X;
		Y_AXIS = BroncoXbox::Axis::LS_Y;
		break;
	case kOliviaDrive:
		IS_USING_JOYSTICK = false;
		HOOD_NEAR_XBOXBUTTON = BroncoXboxButton::Button::B;
		HOOD_MIDDLE_XBOXBUTTON = BroncoXboxButton::Button::A;
		COLLECTOR_SAFE_XBOXBUTTON = BroncoXboxButton::Button::D_R;
		STOP_COLLECT_XBOXBUTTON = BroncoXboxButton::Button::BACK;
		HOOD_FAR_XBOXBUTTON = BroncoXboxButton::Button::Y;
		COLLECTOR_XBOXBUTTON = BroncoXboxButton::Button::X;
		SHOOT_XBOXBUTTON = BroncoXboxButton::Button::RB;
		COLLECTOR_GROUND_XBOXBUTTON = BroncoXboxButton::Button::D_D;
		COLLECTOR_COLLECT_XBOXBUTTON = BroncoXboxButton::Button::D_L;
		COLLECTOR_MAX_XBOXBUTTON = BroncoXboxButton::Button::D_U;
		TOGGLE_DRIVE_DIRECTION_XBOXBUTTON_A = BroncoXboxButton::Button::LSB;
		LINE_UP_BATTER_SHOT_XBOXBUTTON = BroncoXboxButton::Button::START;
		X_AXIS = BroncoXbox::Axis::RS_X;
		Y_AXIS = BroncoXbox::Axis::LS_Y;
		break;
	case kConnieDrive:
		IS_USING_JOYSTICK = true;
		HOOD_NEAR_BUTTON = 11;
		HOOD_MIDDLE_BUTTON = 9;
		STOP_COLLECT_BUTTON = 8;
		HOOD_FAR_BUTTON = 7;
		COLLECTOR_BUTTON = 2;
		SHOOT_BUTTON = 1;
		COLLECTOR_GROUND_BUTTON = 5;
		COLLECTOR_COLLECT_BUTTON = 3;
		COLLECTOR_SAFE_BUTTON = 4;
		COLLECTOR_MAX_BUTTON = 6;
		TOGGLE_DRIVE_DIRECTION_BUTTON_A = 12;
		LINE_UP_BATTER_SHOT_BUTTON = 10;
		break;
	case kKenzieDrive:
		IS_USING_JOYSTICK = false;
		HOOD_NEAR_XBOXBUTTON = BroncoXboxButton::Button::D_D;
		HOOD_MIDDLE_XBOXBUTTON = BroncoXboxButton::Button::UNASSIGNED;
		COLLECTOR_SAFE_XBOXBUTTON = BroncoXboxButton::Button::A;
		STOP_COLLECT_XBOXBUTTON = BroncoXboxButton::Button::BACK;
		HOOD_FAR_XBOXBUTTON = BroncoXboxButton::Button::Y;
		COLLECTOR_XBOXBUTTON = BroncoXboxButton::Button::X;
		SHOOT_XBOXBUTTON = BroncoXboxButton::Button::RT;
		COLLECTOR_GROUND_XBOXBUTTON = BroncoXboxButton::Button::D_D;
		COLLECTOR_COLLECT_XBOXBUTTON = BroncoXboxButton::Button::D_L;
		COLLECTOR_MAX_XBOXBUTTON = BroncoXboxButton::Button::UNASSIGNED;
		TOGGLE_DRIVE_DIRECTION_XBOXBUTTON_A = BroncoXboxButton::Button::LB;
		LINE_UP_BATTER_SHOT_XBOXBUTTON = BroncoXboxButton::Button::Y;
		X_AXIS = BroncoXbox::Axis::RS_X;
		Y_AXIS = BroncoXbox::Axis::RS_Y;
		break;
	case kSierraDrive:
		IS_USING_JOYSTICK = false;
		HOOD_NEAR_XBOXBUTTON = BroncoXboxButton::Button::LSB;
		HOOD_MIDDLE_XBOXBUTTON = BroncoXboxButton::Button::LT;
		HOOD_FAR_XBOXBUTTON = BroncoXboxButton::Button::RT;
		COLLECTOR_XBOXBUTTON = BroncoXboxButton::Button::D_U;
		STOP_COLLECT_XBOXBUTTON = BroncoXboxButton::Button::D_D;
		SHOOT_XBOXBUTTON = BroncoXboxButton::Button::START;
		LINE_UP_BATTER_SHOT_XBOXBUTTON = BroncoXboxButton::Button::BACK;
		COLLECTOR_GROUND_XBOXBUTTON = BroncoXboxButton::Button::X;
		COLLECTOR_COLLECT_XBOXBUTTON = BroncoXboxButton::Button::A;
		COLLECTOR_SAFE_XBOXBUTTON = BroncoXboxButton::Button::B;
		COLLECTOR_MAX_XBOXBUTTON = BroncoXboxButton::Button::Y;
		TOGGLE_DRIVE_DIRECTION_XBOXBUTTON_A = BroncoXboxButton::Button::RB;
		X_AXIS = BroncoXbox::Axis::RS_X;
		Y_AXIS = BroncoXbox::Axis::RS_Y;
		break;
	case kLeviDrive:
		IS_USING_JOYSTICK = false;
		HOOD_NEAR_XBOXBUTTON = BroncoXboxButton::Button::UNASSIGNED;
		HOOD_MIDDLE_XBOXBUTTON = BroncoXboxButton::Button::UNASSIGNED;
		HOOD_FAR_XBOXBUTTON = BroncoXboxButton::Button::UNASSIGNED;
		COLLECTOR_XBOXBUTTON = BroncoXboxButton::Button::X;
		STOP_COLLECT_XBOXBUTTON = BroncoXboxButton::Button::START;
		SHOOT_XBOXBUTTON = BroncoXboxButton::Button::LT;
		LINE_UP_BATTER_SHOT_XBOXBUTTON = BroncoXboxButton::Button::LB;
		COLLECTOR_GROUND_XBOXBUTTON = BroncoXboxButton::Button::A;
		COLLECTOR_COLLECT_XBOXBUTTON = BroncoXboxButton::Button::B;
		COLLECTOR_SAFE_XBOXBUTTON = BroncoXboxButton::Button::Y;
		COLLECTOR_MAX_XBOXBUTTON = BroncoXboxButton::Button::UNASSIGNED;
		TOGGLE_DRIVE_DIRECTION_XBOXBUTTON_A = BroncoXboxButton::Button::RT;
		X_AXIS = BroncoXbox::Axis::LS_X;
		Y_AXIS = BroncoXbox::Axis::LS_Y;
		break;
	case kIanDrive:
		IS_USING_JOYSTICK = true;
		HOOD_NEAR_BUTTON = 7;
		HOOD_MIDDLE_BUTTON = 8;
		STOP_COLLECT_BUTTON = 3;
		HOOD_FAR_BUTTON = 9;
		COLLECTOR_BUTTON = 2;
		SHOOT_BUTTON = 1;
		COLLECTOR_GROUND_BUTTON = 5;
		COLLECTOR_COLLECT_BUTTON = 6;
		COLLECTOR_SAFE_BUTTON = 4;
		COLLECTOR_MAX_BUTTON = 10;
		TOGGLE_DRIVE_DIRECTION_BUTTON_A = 12;
		LINE_UP_BATTER_SHOT_BUTTON = 11;
		break;
	case kTreyDrive:
		IS_USING_JOYSTICK = false;
		HOOD_NEAR_XBOXBUTTON = BroncoXboxButton::Button::D_D;
		HOOD_MIDDLE_XBOXBUTTON = BroncoXboxButton::Button::D_R;
		HOOD_FAR_XBOXBUTTON = BroncoXboxButton::Button::D_U;
		COLLECTOR_XBOXBUTTON = BroncoXboxButton::Button::RB;
		STOP_COLLECT_XBOXBUTTON = BroncoXboxButton::Button::LB;
		SHOOT_XBOXBUTTON = BroncoXboxButton::Button::X;
		LINE_UP_BATTER_SHOT_XBOXBUTTON = BroncoXboxButton::Button::Y;
		COLLECTOR_GROUND_XBOXBUTTON = BroncoXboxButton::Button::START;
		COLLECTOR_COLLECT_XBOXBUTTON = BroncoXboxButton::Button::A;
		COLLECTOR_SAFE_XBOXBUTTON = BroncoXboxButton::Button::B;
		COLLECTOR_MAX_XBOXBUTTON = BroncoXboxButton::Button::UNASSIGNED;
		TOGGLE_DRIVE_DIRECTION_XBOXBUTTON_A = BroncoXboxButton::Button::BACK;
		X_AXIS = BroncoXbox::Axis::LS_X;
		Y_AXIS = BroncoXbox::Axis::TRIGGERS;
		break;
	}
	return;
}

Joystick* OI::getControls()
{
	if(IS_USING_JOYSTICK){
		return stick;
	}else{
		return xbox;
	}
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
