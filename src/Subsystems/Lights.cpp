#include "Lights.h"
#include "../RobotMap.h"

#include "../Commands/Electrical_Lights/LightsOff.h"

Lights::Lights() :
		Subsystem("LightSubsystem")
{
	arduino = new SerialPort(9600, SerialPort::Port::kMXP);
}

void Lights::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new LightsOff());
}

void Lights::Off()
{
	std::cout << "Initializing Lights." << std::endl;

	std::string cmd = "L1_OFF;";
	arduino->Write(cmd, cmd.length());
}

void Lights::Set(const COLOR c)
{
	std::cout << "Setting Lights to: " << c << std::endl;

	std::string cmd = "L1_" + std::string(1, c) + ";";
	arduino->Write(cmd, cmd.length());
}

void Lights::Set(const char c)
{
	std::cout << "Setting Lights to: " << c << std::endl;

	std::string cmd = "L1_" + std::string(1, c) + ";";
	arduino->Write(cmd, cmd.length());
}

void Lights::Flash(const int count, const int flashInterval, const COLOR c)
{

}
