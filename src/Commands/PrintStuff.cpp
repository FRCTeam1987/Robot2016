#include "PrintStuff.h"

PrintStuff::PrintStuff()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires (driveTrain);
}

// Called just before this Command runs the first time
void PrintStuff::Initialize()
{
	//printf("Gyro Angle - %f\tEncoder Distance - %f\n", driveTrain->GetGyroAngle(), driveTrain->GetEncoderDistance());

	std::shared_ptr<NetworkTable> table = driveTrain->GetNetworkTable();

	if(table == NULL)
	{
		printf("table doesn't exist!!\n");
	}
	else
	{
		if(table->GetTable("GRIP/myPoint") == NULL)
		{
			printf("myPoint is not a valid table!\n");
		}
		else
		{
			if(table->GetTable("GRIP/myPoint")->GetNumber("y") == NULL)
			{
				printf("Number is null!\n");
			}
			else
			{
				printf("myPoint.x: %f", table->GetTable("GRIP/mypoint")->GetNumber("y"));
			}
		}
	}
}

// Called repeatedly when this Command is scheduled to run
void PrintStuff::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool PrintStuff::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void PrintStuff::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PrintStuff::Interrupted()
{

}
