/*
 * ReadUltrasonicSensor.cpp
 *
 *  Created on: Feb 3, 2016
 *      Author: Paul
 */

#include <Commands/DriveTrain/ReadUltrasonicSensor.h>

ReadUltrasonicSensor::ReadUltrasonicSensor() {
	// TODO Auto-generated constructor stub
	ultrasonicValue=new AnalogInput(0);
}
