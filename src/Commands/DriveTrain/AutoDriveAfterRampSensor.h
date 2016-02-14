#ifndef AutoDriveAfterRampSensor_H
#define AutoDriveAfterRampSensor_H

#include "../../CommandBase.h"
#include "WPILib.h"

class AutoDriveAfterRampSensor: public CommandBase
{
private:
	float m_speed;

public:
	AutoDriveAfterRampSensor(float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
