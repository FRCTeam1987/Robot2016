#include "CrossLowBar.h"
#include "DriveStraight.h"
#include "WaitForPitch.h"

CrossLowBar::CrossLowBar()
{
	AddSequential(new WaitForPitch(-8,0.6));
	AddSequential(new WaitForPitch(3.5,-0.4));
}

