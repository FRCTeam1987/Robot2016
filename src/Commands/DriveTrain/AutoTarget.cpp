#include "AutoTarget.h"

AutoTarget::AutoTarget()
{
	Requires(driveTrain);
}

// Called just before this Command runs the first time
void AutoTarget::Initialize()
{
	double xCoord;
	double yCoord;
	double area;
	double width;
	int largestWidthIndex = 0;
	double azimuth;
	double horizontalFOV = 54.8;

	std::shared_ptr<NetworkTable> table;
	table = NetworkTable::GetTable("GRIP/myContoursReport");
	if(table == NULL) {
		printf("No contours report!\n");
		driveTrain->SetAzimuth(0);
		return;
	}
	std::vector<double> xCoords = table->GetNumberArray("centerX", llvm::ArrayRef<double>());
	std::vector<double> yCoords = table->GetNumberArray("centerY", llvm::ArrayRef<double>());
	std::vector<double> areas = table->GetNumberArray("area", llvm::ArrayRef<double>());
	std::vector<double> widths = table->GetNumberArray("width", llvm::ArrayRef<double>());
	if(xCoords.size() == 0)
	{
		printf("No Width \n");
		driveTrain->SetAzimuth(0);
		return;
	}
	for(unsigned int i=0; i<xCoords.size(); i++) {
		printf("before 3\n");
		double tempX = xCoords[i];
		double tempY = yCoords[i];
		double tempArea = areas[i];
		double tempWidth = widths[i];
		const int MIN_Y = 0; //Change to ignore top of frame
		if(widths[largestWidthIndex] < tempWidth && tempY > MIN_Y)//Determine condition to find the correct target
		{
			largestWidthIndex = i;
		}
	}
	xCoord = xCoords[largestWidthIndex];
	yCoord = yCoords[largestWidthIndex];
	area = areas[largestWidthIndex];
	width = widths[largestWidthIndex];

	// Not Tested

	printf("xCoord - %f\t The other math - %f\n", xCoord, ((xCoord - 160) / 640));

	azimuth = ((xCoord - 160) / 640 * horizontalFOV);

//	azimuth = (int)fabs(azimuth) % 360;

	printf("Yo, my azimuth is = %f\n", azimuth);

	driveTrain->SetAzimuth(2 * azimuth);

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


