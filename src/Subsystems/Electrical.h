#ifndef Electrical_H
#define Electrical_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Electrical: public Subsystem
{
private:
	PowerDistributionPanel *pdp;
public:
	Electrical();
	void InitDefaultCommand();

	PowerDistributionPanel* GetPDP(){ return pdp; };

};

#endif
