#include "AutoTarget.h"

AutoTarget::AutoTarget()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(driveTrain);
}

// Called just before this Command runs the first time
void AutoTarget::Initialize()
{
	double xCoord;
	double yCoord;
	double area;
	double width;
	double azimuth;
	double horizontalFOV = 54.8;

	std::shared_ptr<NetworkTable> table;
	table = NetworkTable::GetTable("GRIP/myContoursReport");
	std::vector<double> xCoords = table->GetNumberArray("centerX", llvm::ArrayRef<double>());
	std::vector<double> yCoords = table->GetNumberArray("centerY", llvm::ArrayRef<double>());
	std::vector<double> areas = table->GetNumberArray("area", llvm::ArrayRef<double>());
	for(unsigned int i=0; i<xCoords.size(); i++) {
		double tempX = xCoords[i];
		double tempY = yCoords[i];
		double tempArea = areas[i];
		if(true)//Determine condition to find the correct target
		{
			xCoord = tempX;
			yCoord = tempY;
			area = tempArea;
		}
	}
	// Not Tested

	printf("xCoord - %f\t The other math - %f\n", xCoord, ((xCoord - 160) / 640));

	azimuth = ((xCoord - 160) / 640 * horizontalFOV);

//	azimuth = (int)fabs(azimuth) % 360;

	printf("Yo, my azimuth is = %f\n", azimuth);

	driveTrain->SetAzimuth(azimuth);
}

// Called repeatedly when this Command is scheduled to run
void AutoTarget::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool AutoTarget::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void AutoTarget::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoTarget::Interrupted()
{

}


