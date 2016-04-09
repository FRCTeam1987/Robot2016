#include "OI.h"
#include "RobotMap.h"
#include "BroncoXbox.h"

#include "Commands/PrintStuff.h"
#include "Commands/DriveTrain/AutoLowBar.h"
#include "Commands/DriveTrain/AutoRockWall.h"
#include "Commands/DriveTrain/AutoPortcullis.h"
#include "Commands/DriveTrain/AutoChevalDeFrise.h"
#include "Commands/DriveTrain/DriveStraightForDistance.h"
#include "Commands/DriveTrain/ToggleDriverControls.h"
#include "Commands/DriveTrain/AutoGroup.h"
#include "Commands/DriveTrain/SetHeadingOffset.h"
#include "Commands/DriveTrain/AutoDrive.h"
#include "Commands/DriveTrain/AutoTurn.h"
#include "Commands/DriveTrain/AutoTurnPID.h"
#include "Commands/DriveTrain/AutoTurnHeading.h"
#include "Commands/DriveTrain/DriveStraightAndZero.h"
#include "Commands/DriveTrain/DriveSmoothForDistance.h"
#include "Commands/DriveTrain/AutoTurnPID.h"
#include "Commands/DriveTrain/AutoTarget.h"
#include "Commands/DriveTrain/AutoTargetAndTurn.h"

#include "Commands/Shooter/SetIntake.h"
#include "Commands/Shooter/LoadBall.h"
#include "Commands/Shooter/WaitForBall.h"
#include "Commands/Shooter/SetShooterSpeed.h"
#include "Commands/Shooter/Shoot.h"
#include "Commands/Shooter/ShootFar.h"
#include "Commands/Shooter/ShootClose.h"
#include "Commands/Shooter/LineUpBatterShot.h"
#include "Commands/Shooter/SetHoodPosition.h"
#include "Commands/Shooter/LineUpBatterShot.h"
#include "Commands/Shooter/ReadjustBall.h"
#include "Commands/Shooter/SetWheelRaw.h"
#include "Commands/Shooter/SetFlashLight.h"
#include "Commands/Shooter/ToggleFlashlight.h"
#include "Commands/Shooter/ReverseShooterAndIntake.h"
#include "Commands/Shooter/AutoShootFar.h"

#include "Commands/Collector/SetArmPosition.h"
#include "Commands/Collector/CheckArmPosition.h"
#include "Commands/Collector/SetCollectorSpeed.h"
#include "Commands/Collector/CollectBall.h"
#include "Commands/Collector/StopIntakeAndCollector.h"
#include "Commands/Collector/CollectIntakeOnly.h"

#include "Commands/Electrical_Lights/LightsOff.h"
#include "Commands/Electrical_Lights/SetLights.h"

#include "Commands/StopAll.h"

OI::OI()
{
	setLayout(BUTTON_LAYOUT);

//	stick = new BroncoJoy(0, 2, 2);
	xbox = new BroncoXbox(0, 2, 2, .075);
	xboxCoDriver = new BroncoXbox(1, 2, 2, .075);

	/* ******************** XBOX CONTROL MAPPING ******************** */
	xbox->SetX(X_AXIS);
	xbox->SetY(Y_AXIS);
	hoodNearXbox = new BroncoXboxButton(xbox, HOOD_NEAR_XBOXBUTTON);
	hoodMiddleXbox = new BroncoXboxButton(xbox, HOOD_MIDDLE_XBOXBUTTON);
	hoodFarXbox = new BroncoXboxButton(xbox, HOOD_FAR_XBOXBUTTON);
	collectXbox = new BroncoXboxButton(xbox, COLLECTOR_XBOXBUTTON);
	stopCollectXbox = new BroncoXboxButton(xbox, STOP_COLLECT_XBOXBUTTON);
	shootXbox = new BroncoXboxButton(xbox, SHOOT_XBOXBUTTON);
//	shootFarAutoXbox = new BroncoXboxButton(xbox, SHOOT_FAR_AUTO_XBOXBUTTON);
	shootCloseXbox = new BroncoXboxButton(xbox, SHOOT_CLOSE_XBOXBUTTON);
	collectorGroundXbox = new BroncoXboxButton(xbox, COLLECTOR_GROUND_XBOXBUTTON);
	collectorCollectXbox = new BroncoXboxButton(xbox, COLLECTOR_COLLECT_XBOXBUTTON);
	collectorSafeXbox = new BroncoXboxButton(xbox, COLLECTOR_SAFE_XBOXBUTTON);
	collectorMaxXbox = new BroncoXboxButton(xbox, COLLECTOR_MAX_XBOXBUTTON);
	toggleReverseXboxA = new BroncoXboxButton(xbox, TOGGLE_DRIVE_DIRECTION_XBOXBUTTON_A);
	lineUpBatterShotXbox = new BroncoXboxButton(xbox, LINE_UP_BATTER_SHOT_XBOXBUTTON);
//	driver_flashlight = new BroncoXboxButton(xbox, TOGGLE_FLASHLIGHT_XBOXBUTTON);
	shootFarXbox = new BroncoXboxButton(xbox, SHOOT_FAR_XBOXBUTTON);
	autoTargetXbox = new BroncoXboxButton(xbox, AUTO_TARGET_XBOXBUTTON);

	reverseShooterAndIntake = new BroncoXboxButton(xboxCoDriver, BroncoXboxButton::Button::LB);
	autoRockWall = new BroncoXboxButton(xboxCoDriver, BroncoXboxButton::Button::D_D);
	autoRamparts = new BroncoXboxButton(xboxCoDriver, BroncoXboxButton::Button::D_R);
	autoCheval = new BroncoXboxButton(xboxCoDriver, BroncoXboxButton::Button::D_L);
	autoPortcullis = new BroncoXboxButton(xboxCoDriver, BroncoXboxButton::Button::D_U);
	lowBarConfig = new BroncoXboxButton(xboxCoDriver, BroncoXboxButton::Button::A);
	stopAll = new BroncoXboxButton(xboxCoDriver, BroncoXboxButton::Button::B);
	setBrake = new BroncoXboxButton(xboxCoDriver, BroncoXboxButton::Button::BACK);
	setCoast = new BroncoXboxButton(xboxCoDriver, BroncoXboxButton::Button::START);
	codriver_flashlight = new BroncoXboxButton(xboxCoDriver, BroncoXboxButton::Button::Y);
	shootFarCoXbox = new BroncoXboxButton(xboxCoDriver, BroncoXboxButton::Button::RB);
	intakeCollect = new BroncoXboxButton(xboxCoDriver, BroncoXboxButton::Button::X);

	hoodNearXbox->WhenPressed(new SetHoodPosition(Shooter::kNear));
	hoodMiddleXbox->WhenPressed(new SetHoodPosition(Shooter::kMiddle));
	hoodFarXbox->WhenPressed(new SetHoodPosition(Shooter::kFar));
	collectXbox->WhenPressed(new CollectBall());
	stopCollectXbox->WhenPressed(new StopIntakeAndCollector());
	shootXbox->WhenPressed(new Shoot());
	shootFarXbox->WhenPressed(new ShootFar());
//	shootFarAutoXbox->WhenPressed(new AutoShootFar());
	shootCloseXbox->WhenPressed(new ShootClose());
	collectorGroundXbox->WhenPressed(new SetArmPosition(Collector::kGround));
	collectorCollectXbox->WhenPressed(new SetArmPosition(Collector::kCollect));
	collectorSafeXbox->WhenPressed(new SetArmPosition(Collector::kSafe));
	collectorMaxXbox->WhenPressed(new SetArmPosition(Collector::kMax));
	toggleReverseXboxA->WhenPressed(new ToggleDriverControls());
	lineUpBatterShotXbox->WhenPressed(new LineUpBatterShot());
//	driver_flashlight->WhenPressed(new ToggleFlashlight());
	autoTargetXbox->WhenPressed(new AutoTargetAndTurn());

	reverseShooterAndIntake->WhenPressed(new ReverseShooterAndIntake());
	reverseShooterAndIntake->WhenReleased(new StopAll);
	autoRockWall->WhenPressed(new AutoRockWall(1.0, 5.0, 2.0));
	autoRamparts->WhenPressed(new AutoRockWall(0.8, 5.0, 2.0));
	autoCheval->WhenPressed(new AutoChevalDeFrise());
	autoPortcullis->WhenPressed(new AutoPortcullis());
	lowBarConfig->WhenPressed(new SetHoodPosition(Shooter::kNear));
	lowBarConfig->WhenPressed(new SetArmPosition(Collector::kGround));
	stopAll->WhenPressed(new StopAll());
	setBrake->WhenPressed(new SetBrake());
	setCoast->WhenPressed(new SetCoast());
	codriver_flashlight->WhenPressed(new ToggleFlashlight());
	intakeCollect->WhenPressed(new CollectIntakeOnly());
	shootFarCoXbox->WhenPressed(new ShootFar());


	SmartDashboard::PutData("Print Stuff", new PrintStuff());
	SmartDashboard::PutData("Collector - Ground", new SetArmPosition(Collector::kGround));
	SmartDashboard::PutData("Collector - Collect", new SetArmPosition(Collector::kCollect));
	SmartDashboard::PutData("Collector - Safe", new SetArmPosition(Collector::kSafe));
	SmartDashboard::PutData("Collector - Max", new SetArmPosition(Collector::kMax));

	SmartDashboard::PutData("Shooter - Shoot", new Shoot());
	SmartDashboard::PutData("Shooter - Line Up Batter Shot", new LineUpBatterShot());
	SmartDashboard::PutData("Shooter - Shoot Far", new ShootFar());
	SmartDashboard::PutData("Shooter - Shoot Near", new ShootClose());
	SmartDashboard::PutData("Shooter - Set Near Hood", new SetHoodPosition(Shooter::kMiddle));
	SmartDashboard::PutData("Shooter - Reverse intake", new SetIntake(Shooter::IntakeMode::kIntakeReverse));

	SmartDashboard::PutData("DriveTrain - Drive Straight 60 in", new DriveStraightForDistance(60, -0.6));
	SmartDashboard::PutData("DriveTrain - Drive Straight 120 in", new DriveStraightForDistance(120, -0.6));
	SmartDashboard::PutData("DriveTrain - Drive Straight and Zero", new DriveStraightAndZero());
	SmartDashboard::PutData("DriveTrain - AutoPortcullis", new AutoPortcullis());
	SmartDashboard::PutData("DriveTrain - AutoChevalle", new AutoChevalDeFrise());
	SmartDashboard::PutData("DriveTrain - Rock Wall - 0.5", new AutoRockWall(0.5, 5.0, 2.0));
	SmartDashboard::PutData("DriveTrain - Rock Wall - 0.7", new AutoRockWall(0.7, 5.0, 2.0));
	SmartDashboard::PutData("DriveTrain - Rock Wall - 0.8", new AutoRockWall(0.8, 5.0, 2.0));
	SmartDashboard::PutData("DriveTrain - Rock Wall - 0.9", new AutoRockWall(0.9, 5.0, 2.0));
	SmartDashboard::PutData("DriveTrain - Rock Wall - 1.0", new AutoRockWall(1.0, 5.0, 2.0));
	SmartDashboard::PutData("DriveTrain - Auto Group", new AutoGroup());
	SmartDashboard::PutData("DriveTrain - Reset Heading", new SetHeadingOffset());
	SmartDashboard::PutData("DriveTrain - Auto Turn 005", new AutoTurn(5, true));
	SmartDashboard::PutData("DriveTrain - Auto Turn 010", new AutoTurn(10, true));
	SmartDashboard::PutData("DriveTrain - Auto Turn 045", new AutoTurn(45, true));
	SmartDashboard::PutData("DriveTrain - Auto Turn 055", new AutoTurn(55, true));
	SmartDashboard::PutData("DriveTrain - Auto Turn 090", new AutoTurn(90, true));
	SmartDashboard::PutData("DriveTrain - Auto Turn 120", new AutoTurn(120, true));
	SmartDashboard::PutData("DriveTrain - Auto Turn 150", new AutoTurn(150, true));
	SmartDashboard::PutData("DriveTrain - Auto Turn 180", new AutoTurn(180, true, 1.0, .45, .0025, 2.0));
	SmartDashboard::PutData("DriveTrain - Auto Turn 270", new AutoTurn(270, true));
	SmartDashboard::PutData("DriveTrain - Auto Turn 315", new AutoTurn(315, true));
	SmartDashboard::PutData("DriveTrain - Auto Turn 350", new AutoTurn(350, true));
	SmartDashboard::PutData("DriveTrain - Auto Turn 355", new AutoTurn(355, true));
	SmartDashboard::PutData("DriveTrain - Turn Fused Heading at 0.5", new AutoTurnHeading(0.5));
	SmartDashboard::PutData("DriveTrain - Auto Turn PID", new AutoTurnPID(90));
	SmartDashboard::PutData("DriveTrain - Drive Smooth 60 in", new DriveSmoothForDistance(60, -0.6));
	SmartDashboard::PutData("DriveTrain - Drive Smooth 76 in", new DriveSmoothForDistance(76, -0.65, 0.25, true));
	SmartDashboard::PutData("DriveTrain - Drive Smooth 120 in", new DriveSmoothForDistance(120, -0.6));
	SmartDashboard::PutData("DriveTrain - Auto Low Bar", new AutoLowBar());
	SmartDashboard::PutData("DriveTrain - Auto Target", new AutoTarget());
	SmartDashboard::PutData("DriveTrain - Turn to Target", new AutoTargetAndTurn());

	SmartDashboard::PutString("Current_Command", "");
	SmartDashboard::PutNumber("Drive_Speed", -1);
	SmartDashboard::PutNumber("Drive_Distance", 120);
	SmartDashboard::PutNumber("Drive_P", -0.15);
	SmartDashboard::PutNumber("Drive_I", 0.000);
	SmartDashboard::PutNumber("Drive_D", 0.040);
	SmartDashboard::PutNumber("Drive_F", 0.000);

	SmartDashboard::PutNumber("Smooth_Speed", -0.6);
	SmartDashboard::PutNumber("Smooth_Distance", 60);
	SmartDashboard::PutNumber("Smooth_Easing", 0.05);
	SmartDashboard::PutNumber("Smooth_Min", -0.25);
	SmartDashboard::PutNumber("Smooth_Distance_Left", 48);

	SmartDashboard::PutNumber("Turn_Angle", 0);
	SmartDashboard::PutNumber("Turn_P", -0.10000);
	SmartDashboard::PutNumber("Turn_I", -0.00000);
	SmartDashboard::PutNumber("Turn_D", -0.00002);
	SmartDashboard::PutNumber("Turn_F",  0.00000);

	SmartDashboard::PutNumber("Stop_Speed", 1);
	SmartDashboard::PutNumber("Stop_Time",  0.1);


	SmartDashboard::PutData("Set Lights - Red", new SetLights(Lights::COLOR::RED));
	SmartDashboard::PutData("Set Lights - Green", new SetLights(Lights::COLOR::GREEN));
	SmartDashboard::PutData("Set Lights - Blue", new SetLights(Lights::COLOR::BLUE));
	SmartDashboard::PutData("Set Lights - Off", new LightsOff());

	SmartDashboard::PutData("Turn On Flash light", new SetFlashLight(true));
	SmartDashboard::PutData("Turn Off Flash Light", new SetFlashLight(false));

/* ****************************** COMMAND OBJECTS ****************************** */
	/* ******************** Collector ******************** */
//	checkArmPosition = new CheckArmPosition();
//	collectBall = new CollectBall();

	// TODO: Create default constructors and setter methods for the values that need to be set in
	// these commands.
	//setArmPosition = new SetArmPosition();
	//setCollectorSpeed = new SetCollectorSpeed();

//	stopIntakeAndCollector = new StopIntakeAndCollector();

	/* ******************** DriveTrain ******************** */

//	driveStraightAndZero = new DriveStraightAndZero();
//	autoLowBarCmd = new AutoLowBar();

	//autoTurnPID = new AutoTurnPID();

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
		SHOOT_XBOXBUTTON = BroncoXboxButton::Button::UNASSIGNED;
		SHOOT_FAR_XBOXBUTTON = BroncoXboxButton::Button::LB;
		COLLECTOR_GROUND_XBOXBUTTON = BroncoXboxButton::Button::D_D;
		COLLECTOR_COLLECT_XBOXBUTTON = BroncoXboxButton::Button::D_R;
		COLLECTOR_SAFE_XBOXBUTTON = BroncoXboxButton::Button::D_L;
		COLLECTOR_MAX_XBOXBUTTON = BroncoXboxButton::Button::D_U;
		TOGGLE_DRIVE_DIRECTION_XBOXBUTTON_A = BroncoXboxButton::Button::LSB;
		LINE_UP_BATTER_SHOT_XBOXBUTTON = BroncoXboxButton::Button::RB;
//		TOGGLE_FLASHLIGHT_XBOXBUTTON = BroncoXboxButton::Button::START;
		AUTO_TARGET_XBOXBUTTON = BroncoXboxButton::Button::START;
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
		COLLECTOR_SAFE_XBOXBUTTON = BroncoXboxButton::Button::D_L;
		COLLECTOR_MAX_XBOXBUTTON = BroncoXboxButton::Button::D_U;
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
		SHOOT_XBOXBUTTON = BroncoXboxButton::Button::RSB;
		LINE_UP_BATTER_SHOT_XBOXBUTTON = BroncoXboxButton::Button::LB;
		SHOOT_FAR_XBOXBUTTON = BroncoXboxButton::Button::RB;
		COLLECTOR_GROUND_XBOXBUTTON = BroncoXboxButton::Button::D_D;
		COLLECTOR_COLLECT_XBOXBUTTON = BroncoXboxButton::Button::D_L;
		COLLECTOR_MAX_XBOXBUTTON = BroncoXboxButton::Button::D_U;
		TOGGLE_DRIVE_DIRECTION_XBOXBUTTON_A = BroncoXboxButton::Button::LSB;
		LINE_UP_BATTER_SHOT_XBOXBUTTON = BroncoXboxButton::Button::LB;
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
		TOGGLE_DRIVE_DIRECTION_BUTTON_A = 10;
		LINE_UP_BATTER_SHOT_BUTTON = 12;
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
	return xbox;
}
Joystick* OI::getXbox()
{
	return xbox;
}
