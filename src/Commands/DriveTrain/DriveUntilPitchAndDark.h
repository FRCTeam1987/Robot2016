#ifndef DriveUntilPitchAndDark_H
#define DriveUntilPitchAndDark_H

#include "../../CommandBase.h"
#include "WPILib.h"

class DriveUntilPitchAndDark: public CommandBase
{
private:
	float targetPitch;
	float targetRoll;
	double motorSpeed;
	float m_pitchTolerance;
	float m_rollTolerance;

public:
	DriveUntilPitchAndDark(float setPitch, float setRoll, double speed, float pitchTolerance, float rollTolerance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
