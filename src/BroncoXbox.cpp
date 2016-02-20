#include "BroncoXbox.h"

BroncoXbox::BroncoXbox(uint32_t port,
		float expodrive, float expoturn,
		float deadzone) :
	BroncoJoy(port, expodrive, expoturn, deadzone) {

	X_AXIS = BroncoXbox::LS_X;
	Y_AXIS = BroncoXbox::TRIGGERS;
}

float BroncoXbox::GetLeftTrigger() const {
	return CalcExpo(GetRawAxis(2), m_expodrive);
}

float BroncoXbox::GetRightTrigger() const {
	return CalcExpo(GetRawAxis(3), m_expodrive);
}

BroncoXbox::BroncoXbox(uint32_t port, uint32_t numAxisTypes, uint32_t numButtonTypes,
		float expodrive, float expoturn, float deadzone) :
	BroncoJoy(port, numAxisTypes, numButtonTypes, expodrive, expoturn, deadzone) {
	X_AXIS = BroncoXbox::LS_X;
	Y_AXIS = BroncoXbox::TRIGGERS;
}

void BroncoXbox::SetX(const Axis ax)
{
	X_AXIS = ax;
}

void BroncoXbox::SetY(const Axis ax)
{
	Y_AXIS = ax;
}

float BroncoXbox::GetX(JoystickHand hand) const {
	if(X_AXIS == BroncoXbox::TRIGGERS){
		return -GetAxis(X_AXIS);
	}
	return GetAxis(X_AXIS);
}

float BroncoXbox::GetY(JoystickHand hand) const {
	return GetAxis(Y_AXIS);
}

float BroncoXbox::GetLeftJoyX()const{
	return CalcExpo(GetRawAxis(0), m_expoturn);
}

float BroncoXbox::GetLeftJoyY() const{
	return CalcExpo(GetRawAxis(1), m_expodrive);
}

float BroncoXbox::GetRightJoyX()const{
	return CalcExpo(GetRawAxis(4), m_expoturn);
}

float BroncoXbox::GetRightJoyY()const{
	return CalcExpo(GetRawAxis(5), m_expodrive);
}

bool BroncoXbox::GetAButton(){
	return GetRawButton(1);
}

bool BroncoXbox::GetBButton(){
	return GetRawButton(2);
}

bool BroncoXbox::GetXButton(){
	return GetRawButton(3);
}

bool BroncoXbox::GetYButton(){
	return GetRawButton(4);
}

bool BroncoXbox::GetLBButton(){
	return GetRawButton(5);
}

bool BroncoXbox::GetRBButton(){
	return GetRawButton(6);
}

bool BroncoXbox::GetBackButton(){
	return GetRawButton(7);
}

bool BroncoXbox::GetStartButton(){
	return GetRawButton(8);
}

bool BroncoXbox::GetLeftJoyButton(){
	return GetRawButton(9);
}

bool BroncoXbox::GetRightJoyButton(){
	return GetRawButton(10);
}

float BroncoXbox::GetAxis(const Axis ax) const {
	switch(ax)
	{
		case Axis::LS_X:
			return GetLeftJoyX();
			break;
		case Axis::LS_Y:
			return GetLeftJoyY();
			break;
		case Axis::RS_X:
			return GetRightJoyX();
			break;
		case Axis::RS_Y:
			return GetRightJoyY();
			break;
		case Axis::TRIGGERS:
			float L_Trigger = GetLeftTrigger();
			float R_Trigger = GetRightTrigger();

			if(R_Trigger) {
				return -R_Trigger;
			}
			else {
				return L_Trigger;
			}
			break;
	}
}

float BroncoXbox::CalcExpo(float value, float expo) const {
	//Dead Zone
	if (fabs(value) < m_deadzone)
		value = 0;
	else
	{
		// implement an exponential drive curve
		value = expDrive(value, expo);
	}

	return value;
}
