#ifndef COMMANDOBJECTS_H
#define COMMANDOBJECTS_H

#include "WPILib.h"

#include "Commands/DriveTrain/AutoChevalDeFrise.h"
#include "Commands/DriveTrain/DriveStraightUntilRampSensor.h"
#include "Commands/DriveTrain/SetBrake.h"

/*
 * This class is used to store instances of all of our commands. By having
 * an instance of each command we can check to see if any given command
 * is currently running and, if we choose, cancel a running command.
 */
class CommandObjects
{
public:
/* ******************** Command Objects ******************** */

	/* ********** Collector ********** */
	//TODO Create all collector commands

	/* ********** DriveTrain ********** */
	static AutoChevalDeFrise *autoChevalDeFrise;

	static SetBrake *setBrake;

	static DriveStraightUntilRampSensor *driveStraightUntilRampSensor;

	/* ********** Shooter ********** */
	//TODO Create all shooter commands

	CommandObjects();

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
