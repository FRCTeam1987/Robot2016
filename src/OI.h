#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "BroncoJoy.h"
#include "BroncoXbox.h"
#include "RobotMap.h"

class OI
{
private:
	BroncoJoy *stick;
	BroncoXbox *xbox;
	Joystick *m_btnBox;

	//Xbox 360 (If you don't like it make your own layout.)
	JoystickButton *hoodNearXbox;
	JoystickButton *hoodMiddleXbox;
	JoystickButton *collectorGroundXbox;
	JoystickButton *hoodFarXbox;
	JoystickButton *collectXbox;
	JoystickButton *shootXbox;
	JoystickButton *collectorSafeXbox;
	JoystickButton *toggleReverseXboxA;
	JoystickButton *toggleReverseXboxB;
	JoystickButton *toggleReverseXboxC;


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

	int HOOD_NEAR_XBOXBUTTON;
	int HOOD_MIDDLE_XBOXBUTTON;
	int COLLECTOR_SAFE_XBOXBUTTON;
	int HOOD_FAR_XBOXBUTTON;
	int COLLECTOR_XBOXBUTTON;
	int SHOOT_XBOXBUTTON;
	int COLLECTOR_GROUND_XBOXBUTTON;
	int TOGGLE_DRIVE_DIRECTION_XBOXBUTTON_A;
	int TOGGLE_DRIVE_DIRECTION_XBOXBUTTON_B;
	int TOGGLE_DRIVE_DIRECTION_XBOXBUTTON_C;
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
