#ifndef DriveTrain_H
#define DriveTrain_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"
#include "OI.h"
#include "AHRS.h"

class DriveTrain: public PIDSubsystem
{
public:
	enum AutoType {AUTO_TURN, DRIVE_STRAIGHT};

private:
	Talon *leftDrive;
	Talon *rightDrive;
	RobotDrive *robotDrive;
    AHRS *navx;
    double m_output;
    double m_autoSpeed;
    AutoType m_autoMode;

public:
	DriveTrain();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
	void DriveArcade(Joystick *stick);
	void AutoDrive(float move, float rotate);
	double GetGyroAngle();
	void ResetGyro();
	void SetAutoMode(AutoType autoMode);
	AutoType GetAutoMode();
	void SetAutoSpeed(double autoSpeed);
	double GetOutput();
	void setPID (double P, double I, double D);
};

#endif
