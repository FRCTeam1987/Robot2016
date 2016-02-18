#ifndef BRONCO_XBOX_BUTTON_H
#define BRONCO_XBOX_BUTTON_H

#include "iostream"
#include "Buttons\JoystickButton.h"

class BroncoXboxButton : public JoystickButton

{
public:
	enum Button{
		A = 1,
		B = 2,
		X = 3,
		Y = 4,
		LB = 5,
		RB = 6,
		BACK = 7,
		START = 8,
		LSB = 9,
		RSB = 10,
		D_U = 0, // Need to figure out what the DPAD (POV hat)
		D_UR = 45,
		D_R = 90,
		D_DR = 135,
		D_D = 180,
		D_DL = 225,
		D_L = 270,
		D_UL = 315,
		LT,
		RT
	};

	BroncoXboxButton(GenericHID *xbox, Button btn);

	void Set(const Button newButton);
	bool Get() override;

private:
	GenericHID *m_xbox;
	Button m_button;

};

#endif
