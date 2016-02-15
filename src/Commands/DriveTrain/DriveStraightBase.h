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
public:
	DriveStraightBase(double speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
