#include "cannonball.h"
#include "cannonball_viz.h"
#include "utilities.h"
#include "std_lib_facilities.h"

// BEGIN: 2a
// Implementer funksjonen acclY
double acclY(){
    return -9.81;
}
// END: 2a

// BEGIN: 2b
// Implementer funksjonen velY
double velY(double initVelocityY, double time){
    double velY = initVelocityY + acclY() * time;
    return velY;
}
// END: 2b

// BEGIN: 2c
// Implementer funksjonene posX og posY
double posX(double initPositionX, double initVelocityX, double time){
    return initPositionX + initVelocityX * time;
}

double posY(double initPositionY, double initVelocityY, double time){
    return initPositionY + initVelocityY*time + ((acclY()*pow(time,2))/2);
}
// END: 2c

// BEGIN: 2d
// Implementer funksjonen printTime
void printTime(double Time){
    int hours = Time/3600;
    Time = int(Time)%3600;
    int minutes = Time/60;
    int seconds = int(Time)%60;
    cout << "Timer: " << hours << endl;
    cout << "Minutter: " << minutes << endl;
    cout << "Sekunder: " << seconds << endl;
}
// END: 2d

// BEGIN: 2e
// Implementer funksjonen flightTime
double flightTime(double initVelocityY){
    return -2*initVelocityY/acclY();
}
// END: 2e

// BEGIN: 3b
// Implementer funksjonen testDeviation
bool testDeviation(double compareOperand, double toOperand, double maxError, string name){
    bool state = 0;
    double test = abs(compareOperand-toOperand);
    if (test <= maxError){
        state = 1;
        cout << name << " is " << (state ? "valid.": "not valid.") << endl;
    }
    else {
        cout << name << ' is ' << (state ? 'valid.': 'not valid.') << ", expected " << toOperand << ", got " << compareOperand << "." << endl;
    }
    return state;
}
// END: 3b

// BEGIN: 4a
// Her skal du implementere ALLE funksjonene i oppgave 4a
double getUserInputTheta(){
    cout << "Hva er starvinkelen i grader? ";
    double theta;
    cin >> theta;
    return theta;
}
double getUserInputInitVelocity(){
    cout << "Hva er startfarten? ";
    double startFart;
    cin >> startFart;
    return startFart;
}
double degToRad(double deg){
    double rad;
    rad = pi*deg/180;
    return rad;
}
double getVelocityX(double theta, double initVelocity){
    return initVelocity * cos(theta);
}
double getVelocityY(double theta, double initVelocity){
    return initVelocity * sin(theta);
}
vector<double> getVelocityVector(double theta, double initVelocity){
    vector<double> velocityVector(2);
    velocityVector.at(0) = getVelocityX(theta, initVelocity);
    velocityVector.at(1) = getVelocityY(theta, initVelocity);
    return velocityVector;
}
// END: 4a

// BEGIN: 4b
double getDistanceTraveled(double velocityX, double velocityY){
    double Time;
    Time = flightTime(velocityY);
    double Xpos;
    Xpos = posX(0.0, velocityX, Time);
    return Xpos;
}
// END: 4b

// BEGIN: 4c
double targetPractice(double distanceToTarget, double velocityX, double velocityY){
    double Xpos;
    Xpos = getDistanceTraveled(velocityX, velocityY);
    return distanceToTarget - Xpos;
}
// END: 4c
// BEGIN: 5a
int randomWithLimits(int randLow, int randHigh){
    random_device rd;
    default_random_engine generator(rd());
    uniform_real_distribution<double> distribution(randLow,randHigh);
    double number = distribution(generator);
    return number;
}
// END: 5a
// BEGIN: 5b
void playTargetPractise(){
    int randomDistance = randomWithLimits(100,1000);
    cout << "Play target practise game!" << endl;
    //cout << randomDistance << endl;
    bool gameState = 1;
    int attempts = 10;
    while(gameState){
        if (attempts > 0){
            double degree = degToRad(getUserInputTheta());
            double velocity = getUserInputInitVelocity();
            vector<double> fartsVektor = getVelocityVector(degree, velocity);
            double difference = targetPractice(randomDistance, fartsVektor[0],fartsVektor[1]);
            double Time = flightTime(fartsVektor[1]);
            //cout << "Skuddet gikk " << getDistanceTraveled(fartsVektor[0], fartsVektor[1]) << endl;
            //cannonBallViz(randomDistance, 1000, fartsVektor[0],fartsVektor[1], 100);
            if (abs(difference) < 5){
                cout << "You hit! You win!" << endl;
                gameState = 0;
            }
            else if (difference > 0){
                cout << "You missed! You were " << abs(difference) << " meters too short! The cannonball was in the air for " << Time << "seconds!" << endl;
                attempts -= 1;
            }
            else if (difference < 0){
                cout << "You missed! You were " << abs(difference) << " meters too far! The cannonball was in the air for " << Time << "seconds!" << endl;
                attempts -= 1;
            }
        }
        else {
            cout << "You ran out of attempts! You lose!" << endl;
            gameState = 0;
        }
        
    }
}
// END: 5b
