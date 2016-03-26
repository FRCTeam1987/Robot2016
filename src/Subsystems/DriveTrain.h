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
	PIDController* distancePID;

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
    double m_headingOffset;
    float m_initialHeading;
    bool m_isPracticeBot;
    bool m_isReversedOn;
    bool m_inAuto;
    double m_azimuth;

    std::shared_ptr<NetworkTable> nt;

public:
	DriveTrain();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
	void ToggleReverse();

	void SetNetworkTable(std::shared_ptr<NetworkTable> nt);
	std::shared_ptr<NetworkTable> GetNetworkTable();

	void DriveArcade(Joystick *stick);
	void AutoDrive(float move, float rotate);
	void Turn(float speed);
	double GetGyroAngle();
	double GetHeadingChange();

	float GetFusedHeading();
	bool IsMagneticDisturbance(); //Probably need to check for a disturbance before using fused heading.

	float GetGyroX();
	float GetGyroY();
	float GetGyroZ();
	float GetVelocityX();
	float GetVelocityY();
	float GetVelocityZ();
	float GetPitch();
	float GetRoll();

	void ResetGyro();
	void ResetHeadingOffset();
	void SetAutoMode(AutoType autoMode);
	AutoType GetAutoMode();
	void SetAutoSpeed(double autoSpeed);
	double GetOutput();
	float GetPIDError();
	void setPID(double P, double I, double D);
	void setPIDf(double P, double I, double D, double f);
	void ResetLeftEncoder();
	void PrintLeftEncoder();
	double GetLeftEncoderDistance();
	void SetOffset(double offset);
	void SetSetpoint(double setpoint);

	void SetBrake();
	void SetCoast();

	bool InAuto();
	void SetAuto(bool isAuto);
	float GetInitialHeading();
	void SetInitialHeading(float heading);

	bool getRampSensor();

	void SetAzimuth(double azimuth);
	double GetAzimuth();
};

#endif
