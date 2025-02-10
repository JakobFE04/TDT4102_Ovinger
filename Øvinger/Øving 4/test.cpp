#include "test.h"

void testCallByValue()
{
	int v0 = 5;
	int increment = 2;
	int iterations = 10;
	int result = incrementByValueNumTimes(v0, increment, iterations);
	cout << "v0: " << v0 << " increment: " << increment
		 << " iterations: " << iterations << " result: " << result << '\n';
}

void testCallByReference()
{
	// BEGIN: 1d
	int v0 = 5;
	int increment = 2;
	int iterations = 10;
	cout << "v0: " << v0 << " increment: "; 
	incrementByValueNumTimesRef(v0, increment, iterations);
	cout << increment << " iterations: " << iterations << " result: " << v0 << '\n';
	// END: 1d

}


void testString(){
	// 3b OG 3e gjøres inne i her
	// BEGIN: 3e
	string grades;
	grades = randomizeString(8,65,71);
	cout << "Test string: " << grades << endl;
	vector<int> gradeCount(6);
	for (int i=0; i < 6; i++){
		gradeCount.at(i) = countChar(grades, char(70-i));
		cout << "Slot " << i << " er " << countChar(grades, char(70-i)) << endl;
	}
	double snitt;
	for (int i=0; i < 6; i++){
		snitt += gradeCount.at(i) * (i+1);
	}
	snitt = snitt/8;
	cout << "Karaktersnitt: " << char(65 + snitt) << " (" << snitt << ")" << endl;
	// END: 3e
}