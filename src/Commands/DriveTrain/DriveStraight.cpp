#include "DriveStraight.h"
#include "../../RobotMap.h"

DriveStraight::DriveStraight(double angle, double distance, double speed)
{
	Requires(driveTrain);
	angleSetpoint = angle;
	distanceSetpoint=distance;
	motorSpeed=speed;
}

// Called just before this Command runs the first time
void DriveStraight::Initialize()
{
	//previous values -0.012, 0.004, -0.023
	driveTrain->setPID(-0.06, -0.004, 0.0);
	driveTrain->SetAutoSpeed(motorSpeed);
	driveTrain->SetAutoMode(driveTrain->DRIVE_STRAIGHT);

	driveTrain->SetOffset(0.0);
	driveTrain->SetSetpoint(angleSetpoint);
	driveTrain->Enable();
	driveTrain->ResetGyro();
	driveTrain->ResetLeftEncoder();
}

// Called repeatedly when this Command is scheduled to run
void DriveStraight::Execute()
{
//	printf("Error - %f \t Output - %f \n", driveTrain->GetGyroAngle() - angleSetpoint, driveTrain->GetOutput());
	printf("Angle Setpoint - %f \t Error - %f \t Output - %f \t", angleSetpoint, (angleSetpoint - driveTrain->GetGyroAngle()), driveTrain->GetOutput());
	printf(" Distance Setpoint - %f \t Distance Driven - %f\n", distanceSetpoint, driveTrain->GetLeftEncoderDistance());
}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraight::IsFinished()
{
	return driveTrain->GetLeftEncoderDistance()>=distanceSetpoint;
}

// Called once after isFinished returns true
void DriveStraight::End()
{
	driveTrain->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveStraight::Interrupted()
{
	driveTrain->Disable();
}
