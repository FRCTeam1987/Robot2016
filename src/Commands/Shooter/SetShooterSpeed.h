#ifndef SetShooterSpeed_H
#define SetShooterSpeed_H

#include "../../CommandBase.h"
#include "WPILib.h"

class SetShooterSpeed: public CommandBase
{
private:
	static const int m_sampleSize = 30;
	float m_rpm;
//	float m_rpmSamples[m_sampleSize];
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
