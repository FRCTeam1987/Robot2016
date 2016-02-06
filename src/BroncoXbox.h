#ifndef BRONCO_XBOX_H
#define BRONCO_XBOX_H

#include "BroncoJoy.h"

class BroncoXbox : public BroncoJoy

{
public:
	explicit BroncoXbox(uint32_t port,
			float expodrive, float expoturn,
			float deadzone=0.05);

	BroncoXbox(uint32_t port, uint32_t numAxisTypes, uint32_t numButtonTypes,
			float expodrive, float expoturn,
			float deadzone=0.05);

	virtual float GetX(JoystickHand hand = kRightHand) const;
	virtual float GetY(JoystickHand hand = kRightHand) const;

	float GetLeftTrigger() const;
	float GetRightTrigger() const;
	bool GetAButton();
	bool GetBButton();
	bool GetXButton();
	bool GetYButton();
	bool GetLBButton();
	bool GetRBButton();
	bool GetBackButton();
	bool GetStartButton();
	bool GetLeftJoyButton();
	bool GetRightJoyButton();
	float GetLeftJoyX() const;
	float GetLeftJoyY() const;
	float GetRightJoyX() const;
	float GetRightJoyY() const;

private:
	float CalcExpo(float value, float expo) const;
};

#endif
