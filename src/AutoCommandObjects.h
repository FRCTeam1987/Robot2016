#ifndef AutoCommandObjects_H
#define AutoCommandObjects_H

#include "WPILib.h"

#include "Commands/Autonomous/CrossDefenseChooser.h"
/*
 * This class is used to store instances of all of our autonomous choosers.
 */
class AutoCommandObjects
{
public:
/* ******************** Command Objects ******************** */
	/* ********** Autonomous ********** */
	static CrossDefenseChooser *crossDefenseChooser;

	AutoCommandObjects();

	/*
	 * By running the command with "RunCommand" then
	 * we can easily check on the command status
	 * without knowing specifically which command we
	 * ran.
	 */
	static Command* active_command;
	static void RunCommand(Command * cmd);



};

#endif
