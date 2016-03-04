#ifndef SetShooterSpeed_H
#define SetShooterSpeed_H

#include "../../CommandBase.h"
#include "WPILib.h"

class SetShooterSpeed: public CommandBase
{
private:
	float m_rpm;
	float m_rpmSamples[10];
	float m_rpmAverage;

public:
	SetShooterSpeed(float rpm);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
