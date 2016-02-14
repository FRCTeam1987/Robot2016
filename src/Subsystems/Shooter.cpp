#include "Shooter.h"
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"
#include "Commands/Shooter/ReadJoystickSlider.h"
#include "Commands/PrintCurrent.h"

Shooter::Shooter() : Subsystem("ExampleSubsystem")
{
	intakeMotor = new Talon(INTAKE_MOTOR);
	wheelMotor = new CANTalon(WHEEL_MOTOR);

	hasBall = new DigitalInput(HAS_BALL_SENSOR);

	topCylinder = new Solenoid(TOP_CYLINDER);
	bottomCylinder = new Solenoid(BOTTOM_CYLINDER);

	wheelMotor->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	wheelMotor->ConfigNominalOutputVoltage(0,0);
	wheelMotor->ConfigPeakOutputVoltage(12,0);
	//Do not delete the line below
	//wheelMotor->SetPID(0.02, 0.0001, 0.0, 0.0425);

	RPMCopy = 0;
}

void Shooter::InitDefaultCommand()
{
	this->SetDefaultCommand(new ReadJoystickSlider());
}

void Shooter::SetIntake(IntakeMode mode)
{
	switch(mode) {
	case kIntakeForward:
		intakeMotor->Set(-1);
		break;
	case kIntakeReverse:
		intakeMotor->Set(1);
		break;
	default:
		intakeMotor->Set(0);
		break;
	}
}

bool Shooter::HasBall()
{
	return !hasBall->Get();
}

void Shooter::SetWheel(float rpm)
{
	RPMCopy=rpm;
	wheelMotor->SetControlMode(CANTalon::kSpeed);
	wheelMotor->Set(rpm);
}

void Shooter::SetWheelRaw(float speed)
{
	wheelMotor->SetControlMode(CANTalon::kPercentVbus);
	wheelMotor->Set(speed);
}

float Shooter::GetRPM()
{
	return wheelMotor->Get();
}

int Shooter::GetEncoderVel()
{
	return wheelMotor->GetEncVel();
}

float Shooter::GetTargetRPM()
{
	return RPMCopy;
}

void Shooter::SetTopCylinderDirection(Shooter::CylinderDirection direction)
{
	topCylinder->Set(direction == Shooter::kExtendCylinder);
}

void Shooter::SetBottomCylinderDirection(Shooter::CylinderDirection direction)
{
	bottomCylinder->Set(direction == Shooter::kExtendCylinder);
}
