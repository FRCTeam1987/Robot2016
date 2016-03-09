#ifndef AutoPortcullis_H
#define AutoPortcullis_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class AutoPortcullis: public CommandGroup
{
public:
	AutoPortcullis();
	void End();
	void Interrupted();
};

#endif
