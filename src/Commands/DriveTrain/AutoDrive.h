#ifndef AutoDrive_H
#define AutoDrive_H

#include "../../CommandBase.h"
#include "WPILib.h"

class AutoDrive: public CommandBase
{
private:
	float m_speed;
	float m_turn;

public:
	AutoDrive(float speed = 0, float turn = -0.5);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
