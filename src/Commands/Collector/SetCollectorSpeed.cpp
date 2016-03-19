#include "SetCollectorSpeed.h"

SetCollectorSpeed::SetCollectorSpeed(float speed)
{
	Requires(collector);
	m_speed = speed;
}

void SetCollectorSpeed::Initialize()
{
	collector->RunRoller(m_speed);
}

void SetCollectorSpeed::Execute()
{

}

bool SetCollectorSpeed::IsFinished()
{
	return true;
}

void SetCollectorSpeed::End()
{

}

void SetCollectorSpeed::Interrupted()
{
	collector->RunRoller(0);
}
