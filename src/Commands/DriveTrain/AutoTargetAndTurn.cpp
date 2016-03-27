#include "AutoTargetAndTurn.h"
#include "AutoTarget.h"
#include "AutoTurn.h"
#include "SetBrake.h"
#include "SetCoast.h"

AutoTargetAndTurn::AutoTargetAndTurn()
{
	AddSequential(new SetBrake());
//	AddSequential(new AutoTarget());
//	AddSequential(new AutoTurn(9001, true, 0.5, .42, .004, 1.0, true));
	AddSequential(new AutoTarget());
	AddSequential(new AutoTurn(9001, true, 0.5, .42, .004, 1.0, true));
	AddSequential(new SetCoast());
}
