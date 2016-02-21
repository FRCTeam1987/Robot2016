#include "ReadjustBall.h"
#include "SetIntake.h"
#include "WaitForNoBall.h"
#include "WaitForBall.h"

ReadjustBall::ReadjustBall()
{
//	Requires(CommandBase::shooter);
	//Command* command1 = new WaitForNoBall();
	AddSequential(command1);

	printf("Yo, we're constructing our ReadjustBall\n");

	//	AddSequential(new SetIntake(Shooter::kIntakeReverse));
//	AddSequential(new WaitForNoBall());
//	AddSequential(new SetIntake(Shooter::kIntakeForward));
//	AddSequential(new WaitForBall());
//	AddSequential(new SetIntake(Shooter::kIntakeOff));
}

void ReadjustBall::Initialize()
{
	std::cout << "Checking for the ball." << std::endl;

	if(CommandBase::shooter->HasBall())
	{
		std::cout << "We have the ball! Let's readjust" << std::endl;
		command1 = new WaitForBall();
		//m_commands.push_back(CommandGroupEntry(new SetIntake(Shooter::kIntakeReverse), CommandGroupEntry::kSequence_InSequence) );
//		AddSequential(new SetIntake(Shooter::kIntakeReverse));
//		AddSequential(new WaitForNoBall());
//		AddSequential(new SetIntake(Shooter::kIntakeForward));
//		AddSequential(new WaitForBall());
//		AddSequential(new SetIntake(Shooter::kIntakeOff));
	}
}

void ReadjustBall::Execute()
{

}

bool ReadjustBall::IsFinished()
{
	return true;
}

void ReadjustBall::End()
{

}

void ReadjustBall::Interrupted()
{

}
