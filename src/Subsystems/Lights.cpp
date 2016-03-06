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

void Lights::Flash(const COLOR c = COLOR::WHITE, const bool holdWhenComplete = false)
{
	std::cout << "Making Lights flash: " << c << std::endl;
	
	std::string cmd = "L1_FLASH_";
	if(holdWhenComplete){
		cmd += "_HOLD_" + std::string(1, c);
	}else{
		cmd += std::string(1, c);
	}
	cmd += ";";
	arduino->Write(cmd, cmd.length());

}

void Lights::FlashConfig(const int count, const int flashInterval)
{
	std::string cmd = "L1_FLASHC_" + std::to_string(count) + "_" + std::to_string(flashInterval) + ";";
	
	arduino->Write(cmd, cmd.length());
}
