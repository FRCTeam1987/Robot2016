#include "ShootClose.h"
#include "SetHoodPosition.h"
#include "SetShooterSpeed.h"
#include "SetIntake.h"
#include "WaitForNoBall.h"
#include "SetFlashLight.h"
#include "../Electrical_Lights/SetLights.h"

ShootClose::ShootClose()
{
	AddSequential(new SetHoodPosition(Shooter::kMiddle));
	AddSequential(new SetShooterSpeed(3800));
	AddSequential(new SetIntake(Shooter::kIntakeForward));
	AddSequential(new WaitForNoBall());
	AddSequential(new SetLights(Lights::COLOR::YELLOW));
	AddSequential(new WaitCommand(1));
	AddSequential(new SetIntake(Shooter::kIntakeOff));
	AddSequential(new SetHoodPosition(Shooter::kNear));
	AddSequential(new SetShooterSpeed(0));
	AddSequential(new SetLights(Lights::COLOR::OFF));
	AddSequential(new SetFlashLight(false));
}
