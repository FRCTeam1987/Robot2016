#ifndef Lights_H
#define Lights_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Lights: public Subsystem
{
private:
	SerialPort *arduino;

public:
	enum COLOR{
			RED = 'R',
			GREEN = 'G',
			BLUE = 'B',
			YELLOW = 'Y',
			PURPLE = 'P',
			CYAN = 'C',
			WHITE = 'W',
			OFF = 'O'
		};
	Lights();
	void InitDefaultCommand();

/* ******************** COMMANDS ******************** */
	void Off();
	void On(){ Set(); };
	void Set(const COLOR c = COLOR::WHITE);
	void Set(const char c);
	void Flash(const COLOR c = COLOR::WHITE, const bool holdWhenComplete = false);
	void FlashConfig(const int count = -1, const int flashInterval = -1);
};

#endif
