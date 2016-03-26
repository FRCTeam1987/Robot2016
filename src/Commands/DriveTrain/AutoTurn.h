#ifndef AutoTurn_H
#define AutoTurn_H

#include "../../CommandBase.h"
#include "WPILib.h"

class AutoTurn: public CommandBase
{
private:
	static const int SAMPLE_SIZE = 15;
	double m_angle;
	double m_turnAngleAdjust;
	float m_headingChange;
	float m_baseTurnSpeed;
	float m_adjustSpeed;
	float m_averageTolerance;
	float m_actualTolerance;
	bool m_clockWise;
	bool m_reset;
	float m_angleAverage;
	bool m_useAzimuth;
//	float m_angleSamples[SAMPLE_SIZE];

public:
	AutoTurn(double angle, bool reset = false,  float averageAngleTolerance = 1.0, float baseTurnSpeed = .55, float baseAdjustSpeed = .0036, float actualAngleTolerance = 2.0, bool useAzimuth = false);
	void setAngle(double angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
