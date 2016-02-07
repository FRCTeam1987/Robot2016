#ifndef Shooter_H
#define Shooter_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"

class Shooter: public PIDSubsystem
{
private:
	Talon *intakeMotor;
	DigitalInput *hasBall;

public:
	enum IntakeMode { kIntakeForward=0, kIntakeReverse, kIntakeOff };

	Shooter();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
	void SetIntake(IntakeMode mode);
	bool HasBall();
};

#endif
