#ifndef SetIntake_H
#define SetIntake_H

#include "../../CommandBase.h"
#include "WPILib.h"
#include "../../Subsystems/Shooter.h"

class SetIntake: public CommandBase
{
private:
	Shooter::IntakeMode m_mode;

public:
	SetIntake(Shooter::IntakeMode mode);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
