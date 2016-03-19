#include "AutoDrive.h"

AutoDrive::AutoDrive(float speed, float turn)
{
	Requires(driveTrain);
	m_speed = speed;
	m_turn = turn;
}

void AutoDrive::Initialize()
{

}

void AutoDrive::Execute()
{
	driveTrain->AutoDrive(m_speed, m_turn);
}

bool AutoDrive::IsFinished()
{
	return true;
}

void AutoDrive::End()
{

}

void AutoDrive::Interrupted()
{

}
