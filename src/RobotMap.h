#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

//Drive Train

const int LEFT_DRIVE_MOTOR_MASTER = 1;
const int LEFT_DRIVE_MOTOR_SLAVE = 5;
const int RIGHT_DRIVE_MOTOR_MASTER = 2;
const int RIGHT_DRIVE_MOTOR_SLAVE = 3;

const int ENCODER_PIN_A = 0;
const int ENCODER_PIN_B = 1;

const int ENCODER_TICKS = 250;
const double PI = 3.141593;
const double AUTO_DRIVESTRAIGHT_SPEED = 0.4;


//Shooter

const int INTAKE_MOTOR = 0;
const int WHEEL_MOTOR = 4;

const int TOP_CYLINDER = 5;
const int BOTTOM_CYLINDER = 4;

const int HAS_BALL_SENSOR = 6;

const int RPM_TOLERANCE = 50;


//Collector

const int ROLLER_MOTOR = 5;

const int TOP_CYLINDER_A = 2;
const int TOP_CYLINDER_B = 3;
const int BOTTOM_CYLINDER_A = 0;
const int BOTTOM_CYLINDER_B = 1;
const int TOP_CYLINDER_EXTENDED_SENSOR = 7;
const int BOTTOM_CYLINDER_EXTENDED_SENSOR = 8;


//Buttons

//const int RESETENCODERBUTTON = 5;
//const int FORWARDINTAKEMOTORBUTTON = 7;
//const int REVERSEINTAKEMOTORBUTTON = 9;
//const int STOPINTAKEMOTORBUTTON = 11;
//const int SPINSHOOTERBUTTON = 6;
//const int FASTSHOOTERBUTTON = 8;
//const int STOPSHOOTERBUTTON = 4;
//const int PRINT_STUFF_BUTTON = 3;
const int SHOOT_BUTTON = 1;
const int LOAD_BALL_BUTTON = 2;
const int COLLECTOR_COLLECT_BUTTON = 3;
const int COLLECTOR_SAFE_BUTTON = 4;
const int COLLECTOR_GROUND_BUTTON = 5;
const int COLLECTOR_MAX_BUTTON = 6;
const int HOOD_FAR_BUTTON = 7;
const int COLLECT_BALL_BUTTON = 8;
const int HOOD_MIDDLE_BUTTON = 9;
const int RUN_COLLECTOR_BUTTON = 10;
const int HOOD_NEAR_BUTTON = 11;

#endif
