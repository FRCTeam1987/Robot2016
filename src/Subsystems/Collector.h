#ifndef Collector_H
#define Collector_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Collector: public Subsystem
{
private:
	Talon *roller;
	DoubleSolenoid *topCylinder;
	DoubleSolenoid *bottomCylinder;
	DigitalInput *topCylinderExtended;
	DigitalInput *bottomCylinderExtended;

public:
	enum CylinderDirection {kExtendCylinder = 0, kRetractCylinder = 1};
	enum ArmPosition {kGround = 0, kCollect = 1, kSafe = 2, kMax = 3, kUnknown = 4};

	Collector();
	void InitDefaultCommand();
	void RunRoller(float speed);
	void SetTopCylinderDirection(CylinderDirection direction);
	void SetBottomCylinderDirection(CylinderDirection direction);
	bool isTopCylinderExtended();
	bool isBottomCylinderExtended();
	Collector::ArmPosition getArmPosition();
};

#endif
