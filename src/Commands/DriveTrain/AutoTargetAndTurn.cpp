#include "AutoTargetAndTurn.h"
#include "AutoTarget.h"
#include "AutoTurn.h"

AutoTargetAndTurn::AutoTargetAndTurn()
{
	AddSequential(new AutoTarget());
	AddSequential(new AutoTurn(9001, true, 0.5, .5, .004, 1.0, true));
}
