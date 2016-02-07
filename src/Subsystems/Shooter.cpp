#include "Shooter.h"
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"

Shooter::Shooter() :
		PIDSubsystem("Shooter", 1.0, 0.0, 0.0)
{
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	// Enable() - Enables the PID controller
	intakeMotor = new Talon(INTAKEMOTOR);
	hasBall = new DigitalInput(HASBALLSENSOR);
}

double Shooter::ReturnPIDInput()
{
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
	return 0; //Temp To Remove Warning
}

void Shooter::UsePIDOutput(double output)
{
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
}

void Shooter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//setDefaultCommand(new MySpecialCommand());
}

void Shooter::SetIntake(IntakeMode mode) {
	if (mode == kIntakeForward) {
		intakeMotor->Set(-0.5);
	}

	else if (mode == kIntakeReverse) {
		intakeMotor->Set(0.5);
	}

	else {
		intakeMotor->Set(0);
	}
}

bool Shooter::HasBall()
{
	return !hasBall->Get();
}
