#include "DriveTrain.h"
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"
#include ",,/../Commands/DriveTrain/Drive.h"
#include "AHRS.h"

DriveTrain::DriveTrain() :
		PIDSubsystem("DriveTrain", 1.0, 0.0, 0.0)
{
	leftDrive = new Talon(LEFTDRIVEMOTOR);
	rightDrive = new Talon(RIGHTDRIVEMOTOR);
	robotDrive = new RobotDrive(leftDrive, rightDrive);
	navx = new AHRS(SPI::Port::kMXP);
}

double DriveTrain::ReturnPIDInput()
{
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
}

void DriveTrain::UsePIDOutput(double output)
{
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
}

void DriveTrain::InitDefaultCommand()
{
	this->SetDefaultCommand(new Drive());
}

void DriveTrain::DriveArcade(Joystick *stick)
{
	robotDrive->ArcadeDrive(-stick->GetY(), -stick->GetX());
}

void DriveTrain::AutoDrive(float move, float rotate)
{
	robotDrive->ArcadeDrive(move, rotate);
}

double DriveTrain::GetGyroAngle()
{
	return navx->GetAngle();
}

void DriveTrain::ResetGyro()
{
	navx->Reset();
}
