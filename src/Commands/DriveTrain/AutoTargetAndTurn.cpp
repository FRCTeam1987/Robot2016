#include "AutoTargetAndTurn.h"
#include "AutoTarget.h"
#include "AutoTurn.h"
#include "AutoTurnSmallAngle.h"
#include "SetBrake.h"
#include "SetCoast.h"
#include "../Electrical_Lights/SetLights.h"
#include "../Shooter/IndicateOnTarget.h"

AutoTargetAndTurn::AutoTargetAndTurn(float minAngleChange, float angleTolerance)
{
	AddSequential(new SetBrake());
	AddSequential(new SetLights(Lights::COLOR::OFF));
//	AddSequential(new AutoTarget());
//	AddSequential(new AutoTurn(9001, true, 0.5, .42, .004, 1.0, true));
	AddSequential(new AutoTarget());
	AddSequential(new AutoTurnSmallAngle(0, true, true, minAngleChange, angleTolerance));
	AddSequential(new AutoTarget());
	AddSequential(new IndicateOnTarget());
	AddSequential(new SetCoast());
}
