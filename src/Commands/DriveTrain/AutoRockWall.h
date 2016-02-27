#ifndef AutoRockWall_H
#define AutoRockWall_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class AutoRockWall: public CommandGroup
{
public:
	AutoRockWall(float speed, float pitchTolerance, float rollTolerance);
};

#endif
