#include "CommandBase.h"
#include "Commands/Scheduler.h"
#include "RobotMap.h"

// Initialize a single static instance of all of your subsystems to NULL
Shooter* CommandBase::shooter = NULL;
DriveTrain* CommandBase::driveTrain = NULL;
Collector* CommandBase::collector = NULL;
Electrical* CommandBase::electrical = NULL;
Lights* CommandBase::lights = NULL;
std::shared_ptr<NetworkTable> CommandBase::table = NULL;
OI* CommandBase::oi = NULL;
bool CommandBase::m_isPracticeBot = false;

CommandBase::CommandBase(const std::string &name) :
		Command(name)
{
	//table = NetworkTable::GetTable("GRIP");
	DigitalInput practiceBotSensor(PRACTICE_JUMPER);
	m_isPracticeBot = practiceBotSensor.Get();
}

CommandBase::CommandBase() :
		Command()
{
	//table = NetworkTable::GetTable("GRIP");
}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	//printf("Entering init.\n");

	table = NetworkTable::GetTable("GRIP");
	/*
	if(table == NULL){
		printf("table doesn't exist!!\n");
	}else{
		if(table->GetTable("myPoint") == NULL){
			printf("myPoint is not a valid table!\n");
		}else{
			if(table->GetTable("myPoint")->GetNumber("x") == NULL){
				printf("Number is null!\n");
			}else{
				printf("myPoint.x: %f", table->GetTable("myPoint")->GetNumber("x"));
			}

		}
	}
	*/
	driveTrain = new DriveTrain();
	shooter = new Shooter();
	collector = new Collector();
	electrical = new Electrical();
	lights = new Lights();
	oi = new OI();

	driveTrain->SetNetworkTable(table);


//	table = NetworkTable::GetTable("GRIP/myContoursReport");
}

bool CommandBase::IsPracticeBot()
{
	return m_isPracticeBot;
}
