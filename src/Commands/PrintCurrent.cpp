#include "PrintCurrent.h"

PrintCurrent::PrintCurrent()
{
	//Requires(electrical);
}

// Called just before this Command runs the first time
void PrintCurrent::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void PrintCurrent::Execute()
{

	//std::cout << "Total Cur: " << ourElectrical->GetPDP()->GetTotalCurrent() << " "
	//		  << "Shooter: " << ourElectrical->GetPDP()->GetCurrent(12) << std::endl;
}

// Make this return true when this Command no longer needs to run execute()
bool PrintCurrent::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void PrintCurrent::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PrintCurrent::Interrupted()
{

}
