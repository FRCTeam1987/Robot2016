#ifndef BRONCOJOY_H
#define BRONCOJOY_H

#include "Joystick.h"

class BroncoJoy : public Joystick
{
public:
	explicit BroncoJoy(uint32_t port);
	BroncoJoy(uint32_t port, uint32_t numAxisTypes, uint32_t numButtonTypes);

	virtual float GetX(JoystickHand hand = kRightHand) const;
	virtual float GetY(JoystickHand hand = kRightHand) const;
};

#endif
