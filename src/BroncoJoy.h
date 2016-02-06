#ifndef BRONCOJOY_H
#define BRONCOJOY_H

#include "Joystick.h"

class BroncoJoy : public Joystick
{
public:
	explicit BroncoJoy(uint32_t port,
			float expodrive, float expoturn, float deadzone = 0.05);
	BroncoJoy(uint32_t port, uint32_t numAxisTypes, uint32_t numButtonTypes,
			float expodrive, float expoturn, float deadzone = 0.05);

	virtual float GetX(JoystickHand hand = kRightHand) const;
	virtual float GetY(JoystickHand hand = kRightHand) const;

protected:
	float expDrive(float joyVal, float expo) const;

protected:
	float m_expodrive;
	float m_expoturn;
	float m_deadzone;
};

#endif
