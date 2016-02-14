#include "AutoChevalDeFrise.h"
#include "SetBrake.h"
#include "../Collector/SetArmPosition.h"
#include "AutoDriveUntilRampSensor.h"
#include "DriveUntilPitchAndDark.h"


AutoChevalDeFrise::AutoChevalDeFrise()
{
	AddSequential(new SetBrake());
	AddSequential(new SetArmPosition(Collector::kSafe));
	AddSequential(new AutoDriveUntilRampSensor(-0.5));
	AddSequential(new SetArmPosition(Collector::kGround));
	AddSequential(new WaitCommand(2.0));
	AddSequential(new DriveUntilPitchAndDark(0.0, 0.0, 0.50));
}
