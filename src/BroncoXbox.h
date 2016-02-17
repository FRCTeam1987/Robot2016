#ifndef BRONCO_XBOX_H
#define BRONCO_XBOX_H

#include "BroncoJoy.h"

class BroncoXbox : public BroncoJoy

{
public:
	enum Axis{
		LS_X,
		LS_Y,
		RS_X,
		RS_Y,
		TRIGGERS
	};
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
			RSB = 10
	};

	explicit BroncoXbox(uint32_t port,
			float expodrive, float expoturn,
			float deadzone=0.05);

	BroncoXbox(uint32_t port, uint32_t numAxisTypes, uint32_t numButtonTypes,
			float expodrive, float expoturn,
			float deadzone=0.05);

	virtual float GetX(JoystickHand hand = kRightHand) const;
	virtual float GetY(JoystickHand hand = kRightHand) const;

	void SetX(const Axis ax);
	void SetY(const Axis ax);

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
	Axis X_AXIS;
	Axis Y_AXIS;

	float GetAxis(const Axis ax) const;
	float CalcExpo(float value, float expo) const;
};

#endif
