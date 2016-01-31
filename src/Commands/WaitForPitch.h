#ifndef WaitForPitch_H
#define WaitForPitch_H

#include "../CommandBase.h"
#include "WPILib.h"

class WaitForPitch: public CommandBase
{
private:
	float targetPitch;
	double motorSpeed;
public:
	WaitForPitch(float setPitch,double speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
