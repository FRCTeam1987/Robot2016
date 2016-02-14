#ifndef AutoDriveUntilRampSensor_H
#define AutoDriveUntilRampSensor_H

#include "../../CommandBase.h"
#include "WPILib.h"

class AutoDriveUntilRampSensor: public CommandBase
{
private:
	float m_speed;
public:
	AutoDriveUntilRampSensor(float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
