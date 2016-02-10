#ifndef Shooter_H
#define Shooter_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"

class Shooter: public Subsystem
{
private:
	Talon *intakeMotor;
	CANTalon *wheelMotor;
	DigitalInput *hasBall;
	Solenoid *topCylinder;
	Solenoid *bottomCylinder;

public:
	enum IntakeMode {kIntakeForward = 0, kIntakeReverse = 1, kIntakeOff = 2};
	enum CylinderDirection {kExtendCylinder = 0, kRetractCylinder = 1};
	enum HoodPosition {kNear = 0, kMiddle = 1, kFar = 2};

	Shooter();
	void InitDefaultCommand();
	void SetIntake(IntakeMode mode);
	void SetWheel(float rpm);
	bool HasBall();
	float GetRPM();
	void SetTopCylinderDirection(Shooter::CylinderDirection direction);
	void SetBottomCylinderDirection(Shooter::CylinderDirection direction);
};

#endif
