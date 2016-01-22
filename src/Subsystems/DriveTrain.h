#ifndef DriveTrain_H
#define DriveTrain_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"
#include "OI.h"
#include "AHRS.h"

class DriveTrain: public PIDSubsystem
{
private:
	Talon *leftDrive;
	Talon *rightDrive;
	RobotDrive *robotDrive;
    AHRS *navx;

public:
	DriveTrain();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
	void DriveArcade(Joystick *stick);
	void AutoDrive(float move, float rotatet);
	double GetGyroAngle();
};

#endif
