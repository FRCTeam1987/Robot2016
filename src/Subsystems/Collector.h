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

public:
	enum CylinderDirection {kExtendCylinder = 0, kRetractCylinder = 1};
	enum ArmPosition {kGround = 0, kCollect = 1, kSafe = 2, kMax = 3};

	Collector();
	void InitDefaultCommand();
	void RunRoller(float speed);
	void SetTopCylinderDirection(CylinderDirection direction);
	void SetBottomCylinderDirection(CylinderDirection direction);
};

#endif
