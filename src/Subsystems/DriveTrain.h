#ifndef DriveTrain_H
#define DriveTrain_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"
#include "OI.h"
#include "AHRS.h"

class DriveTrain: public PIDSubsystem
{
public:
	enum AutoType {AUTO_TURN, DRIVE_STRAIGHT};

private:
	CANTalon *leftDriveMaster;
	CANTalon *leftDriveSlave;
	CANTalon *rightDriveMaster;
	CANTalon *rightDriveSlave;
	RobotDrive *robotDrive;
	Encoder *leftEncoder;
	Encoder *rightEncoder;
    AHRS *navx;
    DigitalInput *rampSensor;
    double m_output;
    double m_autoSpeed;
    AutoType m_autoMode;
    double m_wheelDiameter;
    double m_offset;
    bool m_isPracticeBot;

    std::shared_ptr<NetworkTable> nt;

public:
	DriveTrain();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();

	void SetNetworkTable(std::shared_ptr<NetworkTable> nt);
	std::shared_ptr<NetworkTable> GetNetworkTable();

	void DriveArcade(Joystick *stick);
	void AutoDrive(float move, float rotate);
	double GetGyroAngle();

	float GetGyroX();
	float GetGyroY();
	float GetGyroZ();
	float GetVelocityX();
	float GetVelocityY();
	float GetVelocityZ();
	float GetPitch();
	float GetRoll();

	void ResetGyro();
	void SetAutoMode(AutoType autoMode);
	AutoType GetAutoMode();
	void SetAutoSpeed(double autoSpeed);
	double GetOutput();
	void setPID (double P, double I, double D);
	void ResetLeftEncoder();
	void PrintLeftEncoder();
	double GetLeftEncoderDistance();
	void SetOffset(double offset);

	void SetBrake();
	void SetCoast();

	bool getRampSensor();
};

#endif
