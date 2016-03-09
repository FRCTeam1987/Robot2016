#include "Lights.h"
#include "../RobotMap.h"

#include "../Commands/Electrical_Lights/LightsOff.h"

Lights::Lights() :
		Subsystem("LightSubsystem")
{
	arduino = new SerialPort(9600, SerialPort::Port::kMXP);

	FlashConfig(5, 250);
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

void Lights::Set(const int R, const int G, const int B)
{
	std::string cmd = "L1_CUS_" + std::to_string(R) + "_" + std::to_string(G) + "_" + std::to_string(B) + ";";
	arduino->Write(cmd, cmd.length());
}

void Lights::Flash(const COLOR c, const bool holdWhenComplete)
{
	std::cout << "Making Lights flash: " << c << std::endl;
	
	std::string cmd = "L1_FLASH_";
	if(holdWhenComplete){
		cmd += "_HOLD_";
	}
	cmd += std::string(1, c); //Set the color
	cmd += ";";
	arduino->Write(cmd, cmd.length());

}

void Lights::FlashConfig(const int count, const int flashInterval)
{
	std::string cmd = "L1_FLASHC_" + std::to_string(count) + "_" + std::to_string(flashInterval) + ";";
	
	arduino->Write(cmd, cmd.length());
}

void Lights::RainbowCycle()
{
	std::string cmd = "L1_RAINCYC;";
	arduino->Write(cmd, cmd.length());	
}

void Lights::Rainbow()
{
	std::string cmd = "L1_RAIN;";
	arduino->Write(cmd, cmd.length());	
}

void Lights::TheaterChase(const COLOR c)
{
	std::string cmd = "L1_THEA_" + std::string(1, c) + ";";
	arduino->Write(cmd, cmd.length());	
}

void Lights::TheaterRain()
{
	std::string cmd = "L1_THEARAIN;";
	arduino->Write(cmd, cmd.length());	
}
