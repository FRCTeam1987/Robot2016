#include "BroncoXboxButton.h"

BroncoXboxButton::BroncoXboxButton(GenericHID *xbox, Button btn) :
	JoystickButton(xbox, 0) {
	m_xbox = xbox;
	m_button = btn;
}

void BroncoXboxButton::Set(const Button newButton)
{
	m_button = newButton;
}

bool BroncoXboxButton::Get()
{
	int modified_id = 0;

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
			return (m_xbox->GetPOV() == 0 || m_xbox->GetPOV() == 360); // Need to figure out what the DPAD (POV hat)
			break;
		case D_UR:
			return (m_xbox->GetPOV() == 45);
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
			return (m_xbox->GetRawAxis(2) > 0.25); //LT is always "axis" number 2
			break;
		case RT:
			return (m_xbox->GetRawAxis(3)> 0.25); //RT is always "axis" number 3
			break;
		default:
			return false;

	}
}
