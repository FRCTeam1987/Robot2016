#ifndef DriveStraightBase_H
#define DriveStraightBase_H

#include "../../CommandBase.h"
#include "WPILib.h"

/**
 * \class DriveStraightBase
 */
class DriveStraightBase: public CommandBase
{
private:
	double m_speed;
	float m_P, m_I, m_D, m_F;
	float m_angleSetpoint;
	bool m_reset;

public:
	DriveStraightBase(double speed, float angleSetpoint = 0.0);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	void SetReset(bool reset);
};

#endif
