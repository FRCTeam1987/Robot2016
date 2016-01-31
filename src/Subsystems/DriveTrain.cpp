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

	GetPIDController()->SetContinuous(true);
	GetPIDController()->SetInputRange(0, 360);
	GetPIDController()->SetOutputRange((-1 + m_offset), 1 - m_offset);


	m_autoMode = DRIVE_STRAIGHT;
	m_autoSpeed = 0;
	m_output = 0;
	m_offset = 0; //make this number positive

	//Might need more refinement, doesn't seem to be actual wheel diameter, but works pretty well
	m_wheelDiameter = 9.0;

	encoder->SetDistancePerPulse((PI * m_wheelDiameter) / ENCODERTICKS);
}

double DriveTrain::ReturnPIDInput()
{
	return GetGyroAngle();
}

void DriveTrain::UsePIDOutput(double output)
{
	output>0 ? output += m_offset : output -= m_offset;

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
	robotDrive->ArcadeDrive(stick->GetY(), stick->GetX());
}

void DriveTrain::AutoDrive(float move, float rotate)
{
	robotDrive->ArcadeDrive(move, rotate);
}

double DriveTrain::GetGyroAngle()
{
	return navx->GetAngle();
}

float DriveTrain::GetGyroX()
{
	return navx->GetRawGyroX();
}

float DriveTrain::GetGyroY()
{
	return navx->GetRawGyroY();
}

float DriveTrain::GetGyroZ()
{
	return navx->GetRawGyroZ();
}

float DriveTrain::GetVelocityX()
{
	return navx->GetVelocityX();
}

float DriveTrain::GetVelocityY()
{
	return navx->GetVelocityY();
}

float DriveTrain::GetVelocityZ()
{
	return navx->GetVelocityZ();
}

float DriveTrain::GetPitch()
{
	return navx->GetPitch();
}

float DriveTrain::GetRoll()
{
	return navx->GetRoll();
}

void DriveTrain::ResetGyro()
{
	navx->Reset();
	//Definitely dont use the line under this, sets an offset so the gyro doesnt zero
	//navx->ZeroYaw(); read the comment above
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

void DriveTrain::SetOffset(double offset)
{
	m_offset = offset;
}
