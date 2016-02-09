#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

//Sensor Values

const int ENCODERPIN_A = 0;
const int ENCODERPIN_B = 1;
const int ENCODERTICKS = 250;
const double PI = 3.141593;
const int HASBALLSENSOR = 6;

//Auto Values

const double AUTODRIVESTRAIGHTSPEED = 0.4;

//Drive Train

const int LEFTDRIVEMOTORMASTER = 1;
const int LEFTDRIVEMOTORSLAVE = 5;
const int RIGHTDRIVEMOTORMASTER = 2;
const int RIGHTDRIVEMOTORSLAVE = 3;

//Shooter

const int INTAKEMOTOR = 0;
const int WHEELMOTOR = 4;

const int RPMTOLERANCE = 50;

//Buttons

const int PRINTSTUFFBUTTON = 3;
const int RESETENCODERBUTTON = 5;
const int FORWARDINTAKEMOTORBUTTON = 7;
const int REVERSEINTAKEMOTORBUTTON = 9;
const int STOPINTAKEMOTORBUTTON = 11;
const int LOADBALLBUTTON = 2;
const int SPINSHOOTERBUTTON = 6;
const int FASTSHOOTERBUTTON = 8;
const int STOPSHOOTERBUTTON = 4;
const int SHOOTBUTTON = 1;

#endif
