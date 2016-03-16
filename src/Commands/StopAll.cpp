#include "StopAll.h"
#include "Collector/StopIntakeAndCollector.h"
#include "Shooter/SetShooterSpeed.h"
#include "Shooter/SetWheelRaw.h"
#include "Shooter/SetHoodPosition.h"
#include "DriveTrain/AutoDrive.h"
#include "Electrical_Lights/SetLights.h"


StopAll::StopAll()
{
	AddSequential(new StopIntakeAndCollector());
	AddSequential(new SetShooterSpeed(0));
	AddSequential(new SetWheelRaw(0));
	AddSequential(new AutoDrive(0, 0));
	AddSequential(new SetHoodPosition(Shooter::HoodPosition::kNear));
	AddSequential(new SetLights(Lights::COLOR::OFF));
}
