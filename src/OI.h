#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "Broncojoy.h"

class OI
{
private:
	BroncoJoy *stick;
//	JoystickButton *printStuff;
//	JoystickButton *resetEncoder;
//	JoystickButton *forwardIntakeMotor;
//	JoystickButton *reverseIntakeMotor;
//	JoystickButton *stopIntakeMotor;
	JoystickButton *loadBall;
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


public:
	OI();
	Joystick *getStick();
};

#endif
