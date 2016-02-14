#include "AutoLowBar.h"
#include "AutoDriveUntilRampSensor.h"
#include "AutoDriveAfterRampSensor.h"

AutoLowBar::AutoLowBar()
{
	AddSequential(new AutoDriveUntilRampSensor(0.6));
	AddSequential(new AutoDriveAfterRampSensor(0.6));
}
