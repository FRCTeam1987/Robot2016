#ifndef AutoTurnSmallAngle_H
#define AutoTurnSmallAngle_H

#include "../../CommandBase.h"
#include "WPILib.h"

class AutoTurnSmallAngle: public CommandBase
{
private:
	const float TURN_SPEED_INCREMENT = .01;
	const float MIN_TURN_SPEED = .45;
	float m_minAngleChange;
	float m_angleTolerance;
	float m_currentAngle;
	float m_lastAngle;
	float m_angleSetpoint;
	float m_turnSpeed;
	bool m_reset;
	bool m_azimuth;
	bool m_clockWise;
	bool isMoving(float angleChange);

public:
	AutoTurnSmallAngle(float angleSetpoint, bool reset = false, bool useAzimuth = false, float minAngleChange = 0.075, float angleTolerance = 0.25);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
