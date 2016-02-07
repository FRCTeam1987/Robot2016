#include "Shooter.h"
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"

Shooter::Shooter() : Subsystem("ExampleSubsystem")
{
	intakeMotor = new Talon(INTAKEMOTOR);
	wheelMotor = new CANTalon(WHEELMOTOR);
	wheelMotor->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	wheelMotor->ConfigNominalOutputVoltage(0,0);
	wheelMotor->ConfigPeakOutputVoltage(12,0);
	wheelMotor->SetPID(0.02,0.0001,0,0.0425);
	hasBall = new DigitalInput(HASBALLSENSOR);
}

void Shooter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//setDefaultCommand(new MySpecialCommand());
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
	wheelMotor->SetControlMode(CANTalon::kSpeed);
	wheelMotor->Set(rpm);
}
