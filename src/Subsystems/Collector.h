#ifndef Collector_H
#define Collector_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Collector: public Subsystem
{
private:
	Talon *roller;

public:
	Collector();
	void InitDefaultCommand();
	void RunRoller(float speed);
};

#endif
