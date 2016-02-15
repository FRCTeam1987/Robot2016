#ifndef SetDrive_H
#define SetDrive_H

#include "../../CommandBase.h"
#include "WPILib.h"

class SetDrive: public CommandBase
{
private:
	float m_speed;
	float m_angle;
public:
	SetDrive(float speed, float angle = 0);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
