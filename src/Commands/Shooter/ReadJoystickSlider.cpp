#include "ReadJoystickSlider.h"

ReadJoystickSlider::ReadJoystickSlider()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(shooter);
}

// Called just before this Command runs the first time
void ReadJoystickSlider::Initialize()
{
//	std::cout.precision(3);
}

// Called repeatedly when this Command is scheduled to run
void ReadJoystickSlider::Execute()
{
	float throttleVal = oi->getStick()->GetAxis(Joystick::kThrottleAxis) * -1;


	if( throttleVal > 0 ){
		throttleVal*=6300;
		shooter->SetWheel(throttleVal);
	}else{
		shooter->SetWheel(0); //takes RPM
	}
//	std::cout << "Throttle: " << throttleVal << " RPM: " << shooter->GetRPM() << " Target RPM: " << shooter->GetTargetRPM() << std::endl;

//	std::cout << "Throttle: " << throttleVal << " RPM: " << shooter->GetRPM() << " Encoder Velocity: " << shooter->GetEncoderVel() << std::endl;
//	if( throttleVal > 0 ){
//		shooter->SetWheelRaw(throttleVal);
//	}else{
//		shooter->SetWheelRaw(0); //takes RPM
//	}

}

// Make this return true when this Command no longer needs to run execute()
bool ReadJoystickSlider::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ReadJoystickSlider::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ReadJoystickSlider::Interrupted()
{

}
