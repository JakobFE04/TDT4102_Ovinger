#include "std_lib_facilities.h"
#include "cannonball.h"
#include "cannonball_viz.h"

int main()
{
	/*double maxError = 0.0001;
	testDeviation(velY(25, 2.5), 0.475, maxError, "velY(25,2.5)");
	testDeviation(velY(25, 5.0), -24.05, maxError, "velY(25,5.0)");
	testDeviation(50, 50, maxError, "velX(50, 2.5)");
	testDeviation(50, 50, maxError, "velX(50, 5.0)");
	testDeviation(posX(0,50, 2.5), 125.0, maxError, "posX(0,50,2.5)");
	testDeviation(posX(0,50, 5.0), 250.0, maxError, "posX(0,50,5.0)");
	testDeviation(posY(0,25, 2.5), 31.8438, maxError, "posY(0,25,2.5)");
	testDeviation(posY(0,25, 5.0), 2.375, maxError, "posY(0,25,5.0)");
	vector<double> fartsVektor;
	fartsVektor = getVelocityVector(degToRad(getUserInputTheta()), getUserInputInitVelocity());
	cout << "Fart X: " << fartsVektor[0] << " Fart Y: " << fartsVektor[1] << endl;
	cout << getDistanceTraveled(fartsVektor[0], fartsVektor[1]) << endl;
	cout << targetPractice(20, fartsVektor[0],fartsVektor[1]) << endl;
	for (int i = 0; i <= 10; i++){
		cout << randomWithLimits(0,5) << endl;
	}
	*/
	playTargetPractise();
	return 0;
}