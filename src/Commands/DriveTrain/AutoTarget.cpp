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
	double hypotenuse, distanceX;
	double distanceY = 71;
	int largestWidthIndex = -1;
	double azimuth;

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
	std::vector<double> heights = table->GetNumberArray("height", llvm::ArrayRef<double>());
	if(xCoords.size() == 0)
	{
		printf("No Width \n");
		driveTrain->SetAzimuth(0);
		return;
	}
	for(unsigned int i=0; i<xCoords.size(); i++) {
		double tempX = xCoords[i];
		double tempY = yCoords[i];
		double tempArea = areas[i];
		double tempWidth = widths[i];
		double tempHeight = heights[i];
		const int MIN_Y = 0; //Change to ignore top of frame
		if(IsBlobTargetRatio(tempWidth, tempHeight) && widths[largestWidthIndex] < tempWidth)
//		if(widths[largestWidthIndex] < tempWidth && tempY > MIN_Y)//Determine condition to find the correct target
		{
			largestWidthIndex = i;
		}
	}
	if(largestWidthIndex < 0) {
		printf("No Width \n");
		driveTrain->SetAzimuth(0);
		return;
	}

	xCoord = xCoords[largestWidthIndex];
	yCoord = yCoords[largestWidthIndex];
	area = areas[largestWidthIndex];
	width = widths[largestWidthIndex];

//	hypotenuse = GOAL_WIDTH_INCHES * IMAGE_RESOLUTION / (2 * width * tan(DegreesToRadians(HORIZONTAL_FOV/2)));
	hypotenuse = 0;

//	distanceX = sqrt((hypotenuse * hypotenuse) - (distanceY * distanceY));
	distanceX = (-3.0175 * width) + 276.82 - 2.0;

	// Not Tested

	printf("xCoord = %f\t The other math = %f\t Hypotenuse = %f\t Distance X = %f\n Width = %f\t", xCoord, ((xCoord - 160) / 640), hypotenuse, distanceX, width);

	azimuth = ((xCoord - 160) / 640 * HORIZONTAL_FOV);

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

double AutoTarget::DegreesToRadians(double degrees)
{
	return degrees * PI / 180;
}

bool AutoTarget::IsBlobTargetRatio(double tWidth, double tHeight, double tolerance) {
	double knownTargetRatio = GOAL_WIDTH_INCHES / GOAL_HEIGHT_INCHES;
	double blobRatio = tWidth / tHeight;
	printf("knownRatio:%.2f   blobRatio:%.2f\n", knownTargetRatio, blobRatio);
	printf("IsBlobTargetRatio: %s\n", (blobRatio < knownTargetRatio + tolerance &&
			blobRatio > knownTargetRatio - tolerance) ? "true": "false");
	return blobRatio < knownTargetRatio + tolerance &&
			blobRatio > knownTargetRatio - tolerance;
}
