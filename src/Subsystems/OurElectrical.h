#ifndef OurElectrical_H
#define OurElectrical_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class OurElectrical: public Subsystem
{
private:
	PowerDistributionPanel *pdp;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	OurElectrical();
	void InitDefaultCommand();

	PowerDistributionPanel* GetPDP(){ return pdp; };

};

#endif
