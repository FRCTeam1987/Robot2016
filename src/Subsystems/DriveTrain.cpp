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
	encoder = new Encoder(ENCODERPIN_A, ENCODERPIN_B);

	m_autoMode = DRIVE_STRAIGHT;
	m_autoSpeed = 0;
	m_output = 0;
	//Might need more refinement, doesnt seem to be actual wheel diameter, but works pretty well
	m_wheelDiameter = 9.0;

	encoder->SetDistancePerPulse((PI * m_wheelDiameter) / ENCODERTICKS);
}

double DriveTrain::ReturnPIDInput()
{
	return GetGyroAngle();
}

void DriveTrain::UsePIDOutput(double output)
{
	m_output = output;

	if(m_autoMode == DRIVE_STRAIGHT)
	{
		AutoDrive(m_autoSpeed, output);
	}
	else if(m_autoMode == AUTO_TURN)
	{
		AutoDrive(0, output);
	}
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

void DriveTrain::SetAutoMode(AutoType autoMode)
{
	m_autoMode = autoMode;
}

DriveTrain::AutoType DriveTrain::GetAutoMode()
{
	return m_autoMode;
}

void DriveTrain::SetAutoSpeed(double autoSpeed)
{
	m_autoSpeed = autoSpeed;
}

double DriveTrain::GetOutput()
{
	return m_output;
}

void DriveTrain::setPID(double P, double I, double D)
{
	GetPIDController()->SetPID(P, I, D);
}

void DriveTrain::ResetEncoder()
{
	encoder->Reset();
}

double DriveTrain::GetEncoderDistance()
{
	return encoder->GetDistance();
}
