#include "utilities.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes)
{
	for (int i = 0; i < numTimes; i++)
		startValue += increment;

	return startValue;
}

// BEGIN: 1d
void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes){
	for (int i = 0; i < numTimes; i++)
		startValue += increment;
}
// END: 1d

// BEGIN: 1e
void swapNumbers(int& value_1, int& value_2){
	int temp;
	temp = value_1;
	value_1 = value_2;
	value_2 = temp;
}
// END: 1e

// BEGIN: 2b
void printStudent(Student stud){
	cout << "Name:" << setw(15) << stud.name << endl;
	cout << "Studyprogram:" << setw(14) << stud.studyProgram << endl;
	cout << "Age:" << setw(14) << stud.age << endl;
}
// END: 2b

// BEGIN: 2c
///*returverdi*/ isInProgram(/*param 1: Student, param 2: string*/){}
bool isInProgram(Student stud, string program){
	if (stud.studyProgram == program){
		cout << stud.name << " is a part of the study program " << program << "." << endl;
		return 1;
	}
	else{
		cout << stud.name << " is not a part of the study program " << program << "." << endl;
		return 0;
	}
}
// END: 2c
int randomWithLimits(int randLow, int randHigh){
    random_device rd;
    default_random_engine generator(rd());
    uniform_real_distribution<double> distribution(randLow,randHigh);
    double number = distribution(generator);
    return number;
}

// BEGIN: 3a
///*returverdi*/ randomizeString(/*param 1: antall tegn, param 2: øvre grense, param 3: nedre grense */) 
string randomizeString(int numSymbols, int limHigh, int limLow){
	string randString = "";
	for (int i = 0; i < numSymbols; i++){
		random_device rd;
		default_random_engine generator(rd());
		uniform_real_distribution<double> distribution(limLow,limHigh);
		char ascii = distribution(generator);
		randString += ascii;
	}
	return randString;
}
// END: 3a

// BEGIN: 3c
///*returverdi*/ readInputToString(/*param 1: lengde n, param 2: øvre grense, param 3: nedre grense*/)
string readInputToString(int n, char limHigh, char limLow){
	int counter = 0;
	string returnString;
	cout << "Input a character: " << endl;
	while (counter < n){
		char input;
		cin >> input;
		input = toupper(input);
		limLow = toupper(limLow);
		limHigh = toupper(limHigh);
		if (input >= limLow and input <= limHigh){
			returnString += input;
			counter += 1;
		}
		else {
			cout << "Try a new input within " << limLow << " to " << limHigh << endl;
		}
	}
	return returnString;
}
// END: 3c

// BEGIN: 3d
///*returverdi*/ countChar(/*param 1: string, param 2: char*/)
int countChar(string countString, char countChar){
	int counter = 0;
	for (int i=0; i < countString.length(); i++){
		if (countString.at(i) == countChar){
			counter += 1;
		}
	}
	return counter;
}
// END: 3d
