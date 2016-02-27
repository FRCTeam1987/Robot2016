#include "PrintStuff.h"
#include "../Subsystems/Collector.h"

PrintStuff::PrintStuff()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires (collector);
	Requires (driveTrain);
}

// Called just before this Command runs the first time
void PrintStuff::Initialize()
{
	printf("Fused Heading = %f \t Change in Heading = %f\n", driveTrain->GetFusedHeading(), driveTrain->GetHeadingChange());

//	if(collector->getArmPosition() == Collector::kGround) {
//		printf("GROUND\n");
//	}
//	else if(collector->getArmPosition() == Collector::kCollect) {
//		printf("COLLECT\n");
//	}
//	else if(collector->getArmPosition() == Collector::kSafe) {
//		printf("SAFE\n");
//	}
//	else if(collector->getArmPosition() == Collector::kMax) {
//		printf("MAX\n");
//	}

//	printf(collector->isTopCylinderExtended() ? "Top Cylinder - True \n" : "Top Cylinder - False \n");;
//	printf(collector->isBottomCylinderExtended() ? "Bottom Cylinder - True \n" : "Bottom Cylinder - False \n");;

//	printf("Encoder - %f\n", driveTrain->GetLeftEncoderDistance());
//	printf(driveTrain->getRampSensor() ? "Ramp Sensor - True \n" : "Ramp Sensor - False \n");
//	printf(collector->isBottomCylinderExtended() ? "EXTENDED - True \n" : "RETRACTED - False \n");
//	printf(collector->isTopCylinderExtended() ? "EXTENDED - True \n" : "DOWN - RETRACTED \n");
//	driveTrain->PrintLeftEncoder();

//	printf(driveTrain->getRampSensor() ? "Ramp Sensor - True \t" : "Ramp Sensor - False \t");
//	printf("Pitch: %f \t Roll: %f\n", driveTrain->GetRoll(), driveTrain->GetPitch());
//	if(collector->getArmPosition() == Collector::kCollect)
//	{
//		printf("Cylinder Sensor - Collect \n");
//	}
//	else if(collector->getArmPosition() == Collector::kGround)
//	{
//		printf("Cylinder Sensor - Ground \n");
//	}
//	else if(collector->getArmPosition() == Collector::kMax)
//	{
//		printf("Cylinder Sensor - Max \n");
//	}
//	else if(collector->getArmPosition() == Collector::kSafe)
//	{
//		printf("Cylinder Sensor - Safe \n");
//	}
//	else
//	{
//		printf("Cylinder Sensor - Error (See Jon) \n");
//	}
//
//	printf(collector->isTopCylinderExtended() ? "Top - Extended \n" : "Top - Retracted \n");
//	printf(collector->isBottomCylinderExtended() ? "Bottom - Extended \n" : "Bottom - Retracted \n");
//printf("Gyro Angle - %f\tEncoder Distance - %f\n", driveTrain->GetGyroAngle(), driveTrain->GetEncoderDistance());
//
//	std::shared_ptr<NetworkTable> table = driveTrain->GetNetworkTable();
//
//	if(table == NULL)
//	{
//		printf("table doesn't exist!!\n");
//	}
//	else
//	{
//		if(table->GetTable("GRIP/myPoint") == NULL)
//		{
//			printf("myPoint is not a valid table!\n");
//		}
//		else
//		{
//			if(table->GetTable("GRIP/myPoint")->GetNumber("y") == NULL)
//			{
//				printf("Number is null!\n");
//			}
//			else
//			{
//				printf("myPoint.x: %f", table->GetTable("GRIP/mypoint")->GetNumber("y"));
//			}
//		}
//	}
}

// Called repeatedly when this Command is scheduled to run
void PrintStuff::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool PrintStuff::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void PrintStuff::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PrintStuff::Interrupted()
{

}
