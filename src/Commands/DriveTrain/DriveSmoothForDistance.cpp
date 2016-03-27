#include "DriveSmoothForDistance.h"

DriveSmoothForDistance::DriveSmoothForDistance(double distance, double speed, double easing, bool reset)
: DriveStraightBase(speed)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveTrain);

	m_distance = distance;
	m_speed = speed;
	m_easing = easing; //Defaults if

	/* ***** DRIVE SMOOTH CONSTANTS ***** */
	m_easingDistance = 34;
	m_minSpeed = 0.28;
	m_positiveDrive = false;
	m_reset = reset;

	DriveStraightBase::SetReset(m_reset);
}

// Called just before this Command runs the first time
void DriveSmoothForDistance::Initialize()
{
	DriveStraightBase::Initialize();

	/*
	 * Will need to be used on comp bot to calibrate
	 */
//	m_distance = SmartDashboard::GetNumber("Smooth_Distance", 60);
//	m_easingDistance = SmartDashboard::GetNumber("Smooth_Distance_Left", 48);
//	m_speed = SmartDashboard::GetNumber("Smooth_Speed", -0.6);
//	m_easing = SmartDashboard::GetNumber("Smooth_Easing", -0.6);
//	m_min = SmartDashboard::GetNumber("Smooth_Min", -0.25);

	driveTrain->ResetLeftEncoder();

	if(m_speed < 0)
	{
		m_positiveDrive = false;
	}
	else
	{
		m_positiveDrive = true;
	}
}

// Called repeatedly when this Command is scheduled to run
void DriveSmoothForDistance::Execute()
{
	driveTrain->SetAutoSpeed(m_speed);

	double distanceRemaining = abs(m_distance) - abs(driveTrain->GetLeftEncoderDistance());
	//if(distanceSoFar >= m_distance*m_percent)
	if(distanceRemaining <= m_easingDistance)
	{
		m_speed -= m_speed * m_easing;
		if(m_positiveDrive == false && m_speed < m_minSpeed)
			m_speed = -m_minSpeed;
		if(m_positiveDrive == true && m_speed > m_minSpeed)
			m_speed = m_minSpeed;
		driveTrain->SetAutoSpeed(m_speed);
//		shooter->SetTopCylinderDirection(Shooter::kRetractCylinder);
//		shooter->SetBottomCylinderDirection(Shooter::kExtendCylinder);
	}
	printf("Heading Change - %f\t PID - %f\t Distance - %f\n", driveTrain->GetHeadingChange(), driveTrain->GetOutput(), driveTrain->GetLeftEncoderDistance());
}

// Make this return true when this Command no longer needs to run execute()
bool DriveSmoothForDistance::IsFinished()
{
	return abs(driveTrain->GetLeftEncoderDistance())>= abs(m_distance);
}

// Called once after isFinished returns true
void DriveSmoothForDistance::End()
{
//	shooter->SetTopCylinderDirection(Shooter::kExtendCylinder);
//	shooter->SetBottomCylinderDirection(Shooter::kExtendCylinder);
	printf("Drive Smooth Finished Execution\n");
	DriveStraightBase::End();
}

// Called when another commto run
void DriveSmoothForDistance::Interrupted()
{
	driveTrain->Disable();
}
