#include "BroncoXboxButton.h"

BroncoXboxButton::BroncoXboxButton(GenericHID *xbox, Button btn) :
	JoystickButton(xbox, 0) {
	m_xbox = xbox;
	m_button = btn;
	m_triggerPoint = 0.25;
}

void BroncoXboxButton::Set(const Button newButton)
{
	m_button = newButton;
}

void BroncoXboxButton::SetTrigger(const Button newButton, const float triggerPoint)
{
	m_button = newButton;
	
	//Check to make sure the trigger value is within the acceptable range!
	if( (triggerPoint >= 0.0) && (triggerPoint <= 1.0) ) {
	    m_triggerPoint = triggerPoint;
	}
}

bool BroncoXboxButton::Get()
{
	switch(m_button){
		case A:
		case B:
		case X:
		case Y:
		case LB:
		case RB:
		case BACK:
		case START:
		case LSB:
		case RSB:
			return m_xbox->GetRawButton(m_button);
			break;
		case D_U:
			return (m_xbox->GetPOV() == 0 || m_xbox->GetPOV() == 360); // The D-Pad returns angles in 45 deg. increments, hence the values.
			break;
		case D_UR:
			return (m_xbox->GetPOV() == 45);    // TODO: Try casting the enum to an int and compare to that.
			break;
		case D_R:
			return (m_xbox->GetPOV() == 90);
			break;
		case D_DR:
			return (m_xbox->GetPOV() == 135);
			break;
		case D_D:
			return (m_xbox->GetPOV() == 180);
			break;
		case D_DL:
			return (m_xbox->GetPOV() == 225);
			break;
		case D_L:
			return (m_xbox->GetPOV() == 270);
			break;
		case D_UL:
			return (m_xbox->GetPOV() == 315);
			break;
		case LT:
			return (m_xbox->GetRawAxis(2) > m_triggerPoint); //LT is always "axis" number 2
			break;
		case RT:
			return (m_xbox->GetRawAxis(3)> m_triggerPoint); //RT is always "axis" number 3
			break;
		default:
			return false;

	}
}
