#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

//Drive Train
const int LEFT_DRIVE_MOTOR_MASTER = 1;
const int LEFT_DRIVE_MOTOR_SLAVE = 5;
const int RIGHT_DRIVE_MOTOR_MASTER = 2;
const int RIGHT_DRIVE_MOTOR_SLAVE = 3;

const int LEFT_ENCODER_PIN_A = 0;
const int LEFT_ENCODER_PIN_B = 1;
const int RIGHT_ENCODER_PIN_A = 2;
const int RIGHT_ENCODER_PIN_B = 3;
const int RAMP_SENSOR_PIN = 4;
const int PRACTICE_JUMPER = 5;

const int ENCODER_TICKS = 250;
const double PI = 3.141593;
const double AUTO_DRIVESTRAIGHT_SPEED = 0.4;
const double AUTO_BASE_TURN_SPEED = 0.45;    //Tune this value
const double AUTO_ADJUST_TURN_SPEED = .004; //Tune this value
const float PITCH_ANGLE_TOLERANCE = 2.0;
const float ROLL_ANGLE_TOLERANCE = 2.0;
const float TURN_ANGLE_TOLERANCE = 1.0;

const double DRIVE_STRAIGHT_P_PRAC = -0.06;
const double DRIVE_STRAIGHT_I_PRAC = -0.004;
const double DRIVE_STRAIGHT_D_PRAC =  0.0;

const double DRIVE_STRAIGHT_P_COMP = -0.07;
const double DRIVE_STRAIGHT_I_COMP =  0.0;
const double DRIVE_STRAIGHT_D_COMP =  0.0;

//Shooter

const int INTAKE_MOTOR = 1;
const int WHEEL_MOTOR = 4;

const int TOP_CYLINDER = 4;
const int BOTTOM_CYLINDER = 5;

const int HAS_BALL_SENSOR = 6;

const int RPM_TOLERANCE = 50;

const int FLASH_LIGHT = 0;


//Collector

const int ROLLER_MOTOR = 5;

const int TOP_CYLINDER_A = 3;
const int TOP_CYLINDER_B = 2;
const int BOTTOM_CYLINDER_A = 1;
const int BOTTOM_CYLINDER_B = 0;

const int TOP_CYLINDER_EXTENDED_SENSOR = 7;
const int BOTTOM_CYLINDER_EXTENDED_SENSOR = 8;

//Xbox
enum LayoutType
{
	kGTADrive = 0,
	kSpencerDrive = 1,
	kLucasDrive = 2,
	kOliviaDrive = 3,
	kConnieDrive = 4,
	kKenzieDrive = 5,
	kSierraDrive = 6,
	kLeviDrive = 7,
	kIanDrive = 8,
	kTreyDrive = 9
};

const LayoutType BUTTON_LAYOUT = kSpencerDrive;

//Joystick
//const int RESETENCODERBUTTON = 5;
//const int FORWARDINTAKEMOTORBUTTON = 7;
//const int REVERSEINTAKEMOTORBUTTON = 9;
//const int STOPINTAKEMOTORBUTTON = 11;
//const int SPINSHOOTERBUTTON = 6;
//const int FASTSHOOTERBUTTON = 8;
//const int STOPSHOOTERBUTTON = 4;
const int SHOOT_BUTTON = 1;
//const int LOAD_BALL_BUTTON = 2;
const int COLLECT_BALL_BUTTON = 2;
const int COLLECTOR_COLLECT_BUTTON = 3;
const int COLLECTOR_SAFE_BUTTON = 4;
const int COLLECTOR_GROUND_BUTTON = 5;
const int COLLECTOR_MAX_BUTTON = 6;
const int HOOD_FAR_BUTTON = 7;
const int HOOD_MIDDLE_BUTTON = 9;
const int RUN_COLLECTOR_BUTTON = 10;
const int HOOD_NEAR_BUTTON = 11;


//button box buttons below
//button box has 11 bts and 2 switches

const int FORWARD_INTAKE_MOTOR_BUTTON = 1;
const int SHOOT_FAR_BUTTON = 2;
const int SHOOT_CLOSE_BUTTON = 3;
const int PRINT_STUFF_BUTTON = 4;
const int AUTO_DRIVE_UNTIL_RAMP_SENSOR_BUTTON = 5;
const int AUTO_CHEVAL_DEFRISE_BUTTON = 7;
const int AUTO_PORTCULLIS_BUTTON = 11;
const int AUTO_ROCK_WALL_BUTTON = 9;
const int AUTO_LOW_BAR_BUTTON = 12;
const int READJUST_BALL_BUTTON = 8;
//const int FORWARD_CONTROLS = ;
//const int BACKWARD_CONTROLS = ;      unused unless driver prefers
const int TOGGLE_CONTROLS = 10;


#endif
