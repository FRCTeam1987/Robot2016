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

public:
	enum IntakeMode { kIntakeForward=0, kIntakeReverse, kIntakeOff };

	Shooter();
	void InitDefaultCommand();
	void SetIntake(IntakeMode mode);
	void SetWheel(float rpm);
	bool HasBall();
	float GetRPM();
};

#endif
