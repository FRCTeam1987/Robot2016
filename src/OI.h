#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "BroncoJoy.h"
#include "BroncoXbox.h"
#include "BroncoXboxButton.h"
#include "RobotMap.h"

class OI
{
private:
	BroncoJoy *stick;
	BroncoXbox *xbox;
	Joystick *m_btnBox;

	//Xbox 360 (If you don't like it make your own layout.)

	BroncoXboxButton *hoodNearXbox;
	BroncoXboxButton *hoodMiddleXbox;
	BroncoXboxButton *collectorGroundXbox;
	BroncoXboxButton *hoodFarXbox;
	BroncoXboxButton *collectXbox;
	BroncoXboxButton *shootXbox;
	BroncoXboxButton *stopCollectXbox;
	BroncoXboxButton *collectorSafeXbox;
	BroncoXboxButton *toggleReverseXboxA;
	BroncoXboxButton *toggleReverseXboxB;
	BroncoXboxButton *toggleReverseXboxC;


	JoystickButton *printStuff;
//	JoystickButton *resetEncoder;
	JoystickButton *forwardIntakeMotor;
//	JoystickButton *reverseIntakeMotor;
//	JoystickButton *stopIntakeMotor;
//	JoystickButton *loadBall;
//	JoystickButton *spinShooter;
//	JoystickButton *anotherSpinShooter;
//	JoystickButton *stopSpinShooter;
	JoystickButton *shoot;
	JoystickButton *collectorGround;
	JoystickButton *collectorCollect;
	JoystickButton *collectorSafe;
	JoystickButton *collectorMax;
	JoystickButton *collectorRun;
	JoystickButton *collectBall;
	JoystickButton *hoodNear;
	JoystickButton *hoodMiddle;
	JoystickButton *hoodFar;
//	JoystickButton *readJoystickSlider;

//	JoystickButton *shootFar;
//	JoystickButton *shootClose;
	JoystickButton *autoTestDef;
	JoystickButton *autoPortcullis;
	JoystickButton *autoChevalDeFrise;
	JoystickButton *autoRockWall;
	JoystickButton *toggleReverse;

	BroncoXboxButton::Button HOOD_NEAR_XBOXBUTTON;
	BroncoXboxButton::Button HOOD_MIDDLE_XBOXBUTTON;
	BroncoXboxButton::Button COLLECTOR_SAFE_XBOXBUTTON;
	BroncoXboxButton::Button HOOD_FAR_XBOXBUTTON;
	BroncoXboxButton::Button COLLECTOR_XBOXBUTTON;
	BroncoXboxButton::Button STOP_COLLECT_XBOXBUTTON;
	BroncoXboxButton::Button SHOOT_XBOXBUTTON;
	BroncoXboxButton::Button COLLECTOR_GROUND_XBOXBUTTON;
	BroncoXboxButton::Button TOGGLE_DRIVE_DIRECTION_XBOXBUTTON_A;
	BroncoXboxButton::Button TOGGLE_DRIVE_DIRECTION_XBOXBUTTON_B;
	BroncoXboxButton::Button TOGGLE_DRIVE_DIRECTION_XBOXBUTTON_C;
	BroncoXbox::Axis X_AXIS;
	BroncoXbox::Axis Y_AXIS;

	void setLayout(LayoutType layout);

public:
	OI();
	Joystick *getStick();
	Joystick *getXbox();
	Joystick *getBtnBox();
};

#endif
