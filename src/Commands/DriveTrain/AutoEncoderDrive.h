#ifndef AutoEncoderDrive_H
#define AutoEncoderDrive_H

#include "../../CommandBase.h"
#include "WPILib.h"

class AutoEncoderDrive: public CommandBase
{
private:
	float m_distance;

public:
	AutoEncoderDrive(float distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
