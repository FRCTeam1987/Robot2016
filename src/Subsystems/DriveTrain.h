#ifndef DriveTrain_H
#define DriveTrain_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"

class DriveTrain: public PIDSubsystem
{
public:
	DriveTrain();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
};

#endif
