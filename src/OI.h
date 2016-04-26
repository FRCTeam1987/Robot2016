#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "BroncoJoy.h"
#include "BroncoXbox.h"
#include "BroncoXboxButton.h"
#include "RobotMap.h"

//#include "Commands/DriveTrain/AutoTurnPID.h"

class OI
{
private:
	bool IS_USING_JOYSTICK;
//	BroncoJoy *stick;
	BroncoXbox *xbox;
	BroncoXbox *xboxCoDriver;

	//Xbox 360 - Driver
	JoystickButton *hoodNearXbox;
	JoystickButton *hoodMiddleXbox;
	JoystickButton *collectorGroundXbox;
	JoystickButton *collectorCollectXbox;
	JoystickButton *collectorSafeXbox;
	JoystickButton *collectorMaxXbox;
	JoystickButton *hoodFarXbox;
	JoystickButton *collectXbox;

	JoystickButton *shootXbox;
	JoystickButton *shootFarXbox;
	JoystickButton *shootFarAutoXbox;
	JoystickButton *shootCloseXbox;
	JoystickButton *stopCollectXbox;
	JoystickButton *toggleReverseXboxA;
	JoystickButton *toggleReverseXboxB;
	JoystickButton *toggleReverseXboxC;
	JoystickButton *lineUpBatterShotXbox;
	JoystickButton *driver_flashlight;
	JoystickButton *autoTargetXbox;


	//Xbox 360 - Co-driver
	JoystickButton *reverseShooterAndIntake;
	JoystickButton *autoRockWall;
	JoystickButton *autoRamparts;
	JoystickButton *autoCheval;
	JoystickButton *autoPortcullis;
	JoystickButton *lowBarConfig;
	JoystickButton *stopAll;
	JoystickButton *setBrake;
	JoystickButton *setCoast;
	JoystickButton *codriver_flashlight;
	JoystickButton *shootFarCoXbox;
	JoystickButton *intakeCollect;
	JoystickButton *hoodFarXboxCo;



	int HOOD_NEAR_BUTTON;
	int HOOD_MIDDLE_BUTTON;
	int HOOD_FAR_BUTTON;
	int COLLECTOR_BUTTON;
	int STOP_COLLECT_BUTTON;
	int SHOOT_BUTTON;
	int COLLECTOR_GROUND_BUTTON;
	int COLLECTOR_COLLECT_BUTTON;
	int COLLECTOR_SAFE_BUTTON;
	int COLLECTOR_MAX_BUTTON;
	int TOGGLE_DRIVE_DIRECTION_BUTTON_A;
	int LINE_UP_BATTER_SHOT_BUTTON;

	BroncoXboxButton::Button HOOD_NEAR_XBOXBUTTON;
	BroncoXboxButton::Button HOOD_MIDDLE_XBOXBUTTON;
	BroncoXboxButton::Button COLLECTOR_GROUND_XBOXBUTTON;
	BroncoXboxButton::Button COLLECTOR_COLLECT_XBOXBUTTON;
	BroncoXboxButton::Button COLLECTOR_SAFE_XBOXBUTTON;
	BroncoXboxButton::Button COLLECTOR_MAX_XBOXBUTTON;
	BroncoXboxButton::Button HOOD_FAR_XBOXBUTTON;
	BroncoXboxButton::Button COLLECTOR_XBOXBUTTON;
	BroncoXboxButton::Button STOP_COLLECT_XBOXBUTTON;
	BroncoXboxButton::Button SHOOT_XBOXBUTTON;
	BroncoXboxButton::Button SHOOT_FAR_XBOXBUTTON;
//	BroncoXboxButton::Button SHOOT_FAR_AUTO_XBOXBUTTON;
	BroncoXboxButton::Button SHOOT_CLOSE_XBOXBUTTON;
	BroncoXboxButton::Button TOGGLE_DRIVE_DIRECTION_XBOXBUTTON_A;
	BroncoXboxButton::Button LINE_UP_BATTER_SHOT_XBOXBUTTON;
	BroncoXboxButton::Button TOGGLE_FLASHLIGHT_XBOXBUTTON;
	BroncoXboxButton::Button AUTO_TARGET_XBOXBUTTON;
	BroncoXbox::Axis X_AXIS;
	BroncoXbox::Axis Y_AXIS;

	void setLayout(LayoutType layout);

public:
	OI();
	Joystick* getControls();
	Joystick *getStick();
	Joystick *getXbox();
	Joystick *getBtnBox();

	SendableChooser *lightColorChooser;

/* ****************************** COMMAND OBJECTS ****************************** */
	/* ******************** Collector ******************** */
	//Command* checkArmPosition;
	//Command* collectBall;
	//Command* setArmPosition;
	//Command* setCollectorSpeed;
	//Command* stopIntakeAndCollector;

	/* ******************** DriveTrain ******************** */
	//AutoLowBar* autoLowBarCmd;

	//AutoTurnPID* autoTurnPID;

	//DriveStraightAndZero* driveStraightAndZero;
};

#endif
