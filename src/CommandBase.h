#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <string>
#include "Commands/Command.h"
#include "OI.h"
#include "WPILib.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/Collector.h"
#include "Subsystems/Electrical.h"
#include "Subsystems/Lights.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command
{
public:
	CommandBase(const std::string &name);
	CommandBase();
	static void init();
	// Create a single static instance of all of your subsystems
	static DriveTrain *driveTrain;
	static Shooter *shooter;
	static Collector *collector;
	static Electrical *electrical;
	static Lights *lights;
	static std::shared_ptr<NetworkTable> table;
	static OI *oi;

	static bool IsPracticeBot();

private:
	static bool m_isPracticeBot;
};

#endif
