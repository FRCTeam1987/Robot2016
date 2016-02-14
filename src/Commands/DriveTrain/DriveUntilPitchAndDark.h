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
public:
	DriveUntilPitchAndDark(float setPitch, float setRoll, double speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
