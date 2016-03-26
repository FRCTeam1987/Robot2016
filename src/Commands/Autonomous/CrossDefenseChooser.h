#ifndef CrossDefenseChooser_H
#define CrossDefenseChooser_H

#include "../../CommandBase.h"
#include "WPILib.h"

#include "CommandObjects.h"

class CrossDefenseChooser: public CommandBase
{

private:
	int obstacle_number;
public:
	CrossDefenseChooser();
	void SetObstacle( int obsNum );
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
