#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/DriveTrain/AutoTurn.h"
#include "Commands/DriveTrain/AutoDrive.h"
#include "Commands/DriveTrain/DriveStraight.h"
#include "Commands/DriveTrain/CrossLowBar.h"
#include "CommandBase.h"
#include "Commands/WaitForPitch.h"

class Robot: public IterativeRobot
{
private:
	std::unique_ptr<Command> autonomousCommand;
	SendableChooser *chooser;

	void RobotInit()
	{
		CommandBase::init();
		chooser = new SendableChooser();
		chooser->AddObject("Auto Drive", new AutoDrive());
		chooser->AddObject("Auto Turn - 90", new AutoTurn(45));
		/*  Delete these before commiting to GitHub   */
		chooser->AddObject("Auto Turn - 030", new AutoTurn(30));
		chooser->AddObject("Auto Turn - 060", new AutoTurn(60));
		chooser->AddObject("Auto Turn - 090", new AutoTurn(90));
		chooser->AddObject("Auto Turn - 120", new AutoTurn(120));
		chooser->AddObject("Auto Turn - 150", new AutoTurn(150));
		/*  Delete these before commiting to GitHub   */
//		chooser->AddObject("Drive Straight PID 75", new DriveStraight(0, 120, 0.75));
//		chooser->AddDefault("Drive Straight PID 100", new DriveStraight(0, 120, 1.0));
		chooser->AddObject("Cross Low Bar", new CrossLowBar());
		SmartDashboard::PutData("Auto Modes", chooser);
		chooser->AddObject("Wait For Pitch", new WaitForPitch(8,0.6));
	}

	/**
     * This function is called once each time the robot enters Disabled mode.
     * You can use it to reset any subsystem information you want to clear when
	 * the robot is disabled.
     */
	void DisabledInit()
	{
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

//		autonomousCommand.reset((Command *)chooser->GetSelected());
		autonomousCommand.reset(new DriveStraight(0, 120, .90));

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

