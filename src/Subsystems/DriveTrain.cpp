#include "DriveTrain.h"
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"
#include "../Commands/DriveTrain/Drive.h"
#include "AHRS.h"

DriveTrain::DriveTrain() :
		PIDSubsystem("DriveTrain", 1.0, 0.0, 0.0)
{
	leftDriveMaster = new CANTalon(LEFT_DRIVE_MOTOR_MASTER);
	leftDriveMaster->SetControlMode(CANTalon::kPercentVbus);
	leftDriveMaster->Set(0);

	leftDriveSlave = new CANTalon(LEFT_DRIVE_MOTOR_SLAVE);
	leftDriveSlave->SetControlMode(CANTalon::kFollower);
	leftDriveSlave->Set(LEFT_DRIVE_MOTOR_MASTER);

	rightDriveMaster = new CANTalon(RIGHT_DRIVE_MOTOR_MASTER);
	rightDriveMaster->SetControlMode(CANTalon::kPercentVbus);
	rightDriveMaster->Set(0);

	rightDriveSlave = new CANTalon(RIGHT_DRIVE_MOTOR_SLAVE);
	rightDriveSlave->SetControlMode(CANTalon::kFollower);
	rightDriveSlave->Set(RIGHT_DRIVE_MOTOR_MASTER);

	SetCoast();

	robotDrive = new RobotDrive(leftDriveMaster, rightDriveMaster);
	robotDrive->SetSafetyEnabled(false);
	navx = new AHRS(SPI::Port::kMXP);
	leftEncoder = new Encoder(LEFT_ENCODER_PIN_A, LEFT_ENCODER_PIN_B);
	rightEncoder = new Encoder(RIGHT_ENCODER_PIN_A, RIGHT_ENCODER_PIN_B);

	rampSensor = new DigitalInput(RAMP_SENSOR_PIN);
	GetPIDController()->SetAbsoluteTolerance(2.0);
	GetPIDController()->SetContinuous(true);
	GetPIDController()->SetInputRange(0, 360);
//	GetPIDController()->SetOutputRange((-1 + m_offset), 1 - m_offset);

	GetPIDController()->SetOutputRange(-1, 1);

	m_isReversedOn = false;

	m_autoMode = DRIVE_STRAIGHT;
	m_autoSpeed = 0;
	m_output = 0;
	m_offset = 0; //make this number positive
	m_headingOffset = GetFusedHeading();

	//Might need more refinement, doesn't seem to be actual wheel diameter, but works pretty well
	if(CommandBase::IsPracticeBot())
	{
		m_wheelDiameter = 8.446;
	}
	else
	{
		m_wheelDiameter = 9.22;
	}

	leftEncoder->SetDistancePerPulse((PI * m_wheelDiameter) / ENCODER_TICKS);
	this->Disable();

	rightEncoder->SetDistancePerPulse((PI * m_wheelDiameter) / ENCODER_TICKS);
	this->Disable();

}

double DriveTrain::ReturnPIDInput()
{
	return GetGyroAngle();
}

void DriveTrain::UsePIDOutput(double output)
{
	m_output = output;

	AutoDrive(m_autoSpeed, output);
}

void DriveTrain::InitDefaultCommand()
{
	this->SetDefaultCommand(new Drive());
}

void DriveTrain::SetNetworkTable(std::shared_ptr<NetworkTable> nt)
{
	this->nt = nt;
}

std::shared_ptr<NetworkTable> DriveTrain::GetNetworkTable()
{
	return nt;
}

void DriveTrain::DriveArcade(Joystick *stick)
{
	robotDrive->ArcadeDrive(stick->GetY()*(m_isReversedOn ? 1 : -1), -stick->GetX());
}

void DriveTrain::AutoDrive(float move, float rotate)
{
	robotDrive->ArcadeDrive(-move, rotate);
}

double DriveTrain::GetGyroAngle()
{
	return navx->GetAngle();
}

double DriveTrain::GetHeadingChange()
{
	if((GetFusedHeading() - m_headingOffset) < 0)
	{
		return (GetFusedHeading() - m_headingOffset) + 360;
	}
	else
	{
		return (GetFusedHeading() - m_headingOffset);
	}
}

float DriveTrain::GetFusedHeading()
{
	return navx->GetFusedHeading();
}

bool DriveTrain::IsMagneticDisturbance()
{
	return navx->IsMagneticDisturbance();
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

void DriveTrain::ResetHeadingOffset()
{
	m_headingOffset = GetFusedHeading();
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

void DriveTrain::setPIDf(double P, double I, double D, double f)
{
	GetPIDController()->SetPID(P, I, D, f);
}

void DriveTrain::ResetLeftEncoder()
{
	printf("Encoder Reseted");
	leftEncoder->Reset();
}

double DriveTrain::GetLeftEncoderDistance()
{
	return leftEncoder->GetDistance();
}

void DriveTrain::PrintLeftEncoder()
{
	printf("Left Encoder Distance - %f\n", leftEncoder->GetDistance());
}

void DriveTrain::SetOffset(double offset)
{
	abs(offset);
	m_offset = offset;
}

void DriveTrain::SetBrake() {
	leftDriveMaster->ConfigNeutralMode(CANSpeedController::NeutralMode::kNeutralMode_Brake);
	rightDriveMaster->ConfigNeutralMode(CANSpeedController::NeutralMode::kNeutralMode_Brake);
	leftDriveSlave->ConfigNeutralMode(CANSpeedController::NeutralMode::kNeutralMode_Brake);
	rightDriveSlave->ConfigNeutralMode(CANSpeedController::NeutralMode::kNeutralMode_Brake);
}

void DriveTrain::SetCoast() {
	leftDriveMaster->ConfigNeutralMode(CANSpeedController::NeutralMode::kNeutralMode_Coast);
	rightDriveMaster->ConfigNeutralMode(CANSpeedController::NeutralMode::kNeutralMode_Coast);
	leftDriveSlave->ConfigNeutralMode(CANSpeedController::NeutralMode::kNeutralMode_Coast);
	rightDriveSlave->ConfigNeutralMode(CANSpeedController::NeutralMode::kNeutralMode_Coast);
}

bool DriveTrain::getRampSensor()
{
	return rampSensor->Get();
}

void DriveTrain::ToggleReverse()
{
	m_isReversedOn = !m_isReversedOn;
}
