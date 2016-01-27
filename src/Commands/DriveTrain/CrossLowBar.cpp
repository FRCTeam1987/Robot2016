#include "CrossLowBar.h"
#include "DriveStraight.h"

CrossLowBar::CrossLowBar()
{
	AddSequential(new DriveStraight(0, 40, 0.6));
}
