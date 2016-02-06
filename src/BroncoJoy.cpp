#include "BroncoJoy.h"

#include <math.h>

// Joystick range in which movement is considered accidental
#define MOTOR_MIN 0.3 //Was 0.15

// Uncomment the following line to enable exponential drive control
//#define EXPO_DRIVE
#define EXPO_DRIVE
#define EXPO_MULTIPLIER_DRIVE 2
#define EXPO_MULTIPLIER_TURN 2

#ifdef EXPO_DRIVE
float BroncoJoy::expDrive(float joyVal, float expo) const
{
	float joyMax = 1.0 - m_deadzone;
	float joySign = joyVal<0 ? -1. : 1.;
	float joyLive = fabs(joyVal) - m_deadzone;
	return joySign * (MOTOR_MIN + ((1.0-MOTOR_MIN) * pow(joyLive, expo)/pow(joyMax,expo)));
}
#endif

BroncoJoy::BroncoJoy(uint32_t port,
		float expodrive, float expoturn, float deadzone) :
	Joystick(port) {
	m_expodrive = expodrive;
	m_expoturn = expoturn;
	m_deadzone = deadzone;
}

BroncoJoy::BroncoJoy(uint32_t port, uint32_t numAxisTypes, uint32_t numButtonTypes,
		float expodrive, float expoturn, float deadzone) :
	Joystick(port, numAxisTypes, numButtonTypes) {
	m_expodrive = expodrive;
	m_expoturn = expoturn;
	m_deadzone = deadzone;
}

float BroncoJoy::GetX(JoystickHand hand) const {
	float x = Joystick::GetX(hand);

	// dead zone
	if (fabs(x) < m_deadzone)
		x = 0;
#ifdef EXPO_DRIVE
	else
	{
		// implement an exponential drive curve
		x = expDrive(x, EXPO_MULTIPLIER_TURN);
	}
#endif

	return x;
}

float BroncoJoy::GetY(JoystickHand hand) const {
	float y = Joystick::GetY(hand);

	if (fabs(y) < m_deadzone)
		y = 0;
#ifdef EXPO_DRIVE
	else
	{
		// implement an exponential drive curve
		y = expDrive(y, EXPO_MULTIPLIER_DRIVE);
	}
#endif

//	printf("%f -> %f\n", beforeY, y);
	return y;
}
