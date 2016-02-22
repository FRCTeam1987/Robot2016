#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/DriveTrain/AutoTurn.h"
#include "Commands/Shooter/WaitForBall.h"
#include "Commands/DriveTrain/DriveUntilPitchAndDark.h"
#include "CommandBase.h"

class Robot: public IterativeRobot
{
private:
	std::unique_ptr<Command> autonomousCommand;
	SendableChooser *chooser;

	SendableChooser *defenseTypeChooser;
	SendableChooser *defensePositionChooser;

	void RobotInit()
	{
		CommandBase::init();
		chooser = new SendableChooser();
		chooser->AddObject("Auto Turn - 030", new AutoTurn(30));
		chooser->AddObject("Auto Turn - 060", new AutoTurn(60));
		chooser->AddObject("Auto Turn - 090", new AutoTurn(90));
		chooser->AddObject("Auto Turn - 120", new AutoTurn(120));
		chooser->AddObject("Auto Turn - 150", new AutoTurn(150));
//		chooser->AddObject("Wait For Pitch And Dark", new DriveUntilPitchAndDark(0.0, 0.0, -.65));
		SmartDashboard::PutData("Auto Modes", chooser);
		SmartDashboard::PutData("Wait For Ball", new WaitForBall());

		defenseTypeChooser = new SendableChooser();
		defenseTypeChooser->AddDefault("Low", new std::string("LOW"));
		defenseTypeChooser->AddObject("Rock Wall", new std::string("ROCK_WALL"));
		defenseTypeChooser->AddObject("Rough Terrain", new std::string("ROUGH_TERRAIN"));
		defenseTypeChooser->AddObject("Port", new std::string("PORT"));
		defenseTypeChooser->AddObject("Chival", new std::string("CHIVAL"));
		defenseTypeChooser->AddObject("Ramparts", new std::string("RAMPARTS"));
		defenseTypeChooser->AddObject("Moat", new std::string("MOAT"));
		defenseTypeChooser->AddObject("Sally Port", new std::string("SALLY_PORT"));
		defenseTypeChooser->AddObject("Draw Bridge", new std::string("DRAW_BRIDGE"));
		SmartDashboard::PutData("Defense Type", defenseTypeChooser);

		defensePositionChooser = new SendableChooser();
		defensePositionChooser->AddDefault("1", new std::uint16_t(1));
		defensePositionChooser->AddObject("2", new std::uint16_t(2));
		defensePositionChooser->AddObject("3", new std::uint16_t(3));
		defensePositionChooser->AddObject("4", new std::uint16_t(4));
		defensePositionChooser->AddObject("5", new std::uint16_t(5));
		SmartDashboard::PutData("Defense Position", defensePositionChooser);

//		CameraServer::GetInstance()->SetQuality(50);
//		CameraServer::GetInstance()->StartAutomaticCapture("cam0");
	}

	/**
     * This function is called once each time the robot enters Disabled mode.
     * You can use it to reset any subsystem information you want to clear when
	 * the robot is disabled.
     */
	void DisabledInit()
	{
		CommandBase::driveTrain->SetBrake();
	}

	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	/**
	 * This autonomous (along with the chooser code above) shows how to select between different autonomous modes
	 * using the dashboard. The sendable chooser code works with the Java SmartDashboard. If you prefer the LabVIEW
	 * Dashboard, remove all of the chooser code and uncomment the GetString code to get the auto name from the text box
	 * below the Gyro
	 *
	 * You can add additional auto modes by adding additional commands to the chooser code above (like the commented example)
	 * or additional comparisons to the if-else structure below with additional strings & commands.
	 */
	void AutonomousInit()
	{
		/* std::string autoSelected = SmartDashboard::GetString("Auto Selector", "Default");
		if(autoSelected == "My Auto") {
			autonomousCommand.reset(new MyAutoCommand());
		} else {
			autonomousCommand.reset(new ExampleCommand());
		} */

//		autonomousCommand.reset(new AutoDrive());
//		autonomousCommand->Start();

		autonomousCommand.reset((Command *)chooser->GetSelected());
//		autonomousCommand.reset(new DriveStraight(0, 120, .70));

		if (autonomousCommand != NULL)
			autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();
	}

	void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TestPeriodic()
	{
		LiveWindow::GetInstance()->Run();
	}
};

START_ROBOT_CLASS(Robot)

