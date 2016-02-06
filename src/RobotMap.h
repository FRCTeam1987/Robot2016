#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

//Sensor Values

const int ENCODERPIN_A = 0;
const int ENCODERPIN_B = 1;
const int ENCODERTICKS = 250;
const double PI = 3.141593;

//Auto Values

const double AUTODRIVESTRAIGHTSPEED = 0.4;

//Drive Train

const int LEFTDRIVEMOTORMASTER = 2;
const int LEFTDRIVEMOTORSLAVE = 3;
const int RIGHTDRIVEMOTORMASTER = 0;
const int RIGHTDRIVEMOTORSLAVE = 1;

//Buttons

const int PRINTSTUFFBUTTON = 2;
const int RESETENCODERBUTTON = 5;

#endif
