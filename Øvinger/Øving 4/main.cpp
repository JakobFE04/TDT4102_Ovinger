
#include "std_lib_facilities.h"
#include "test.h"

int main()
{
	int input;
	cout << "Hvilken funksjon skal du teste? " << endl;
	cin >> input;
	switch(input){
		case 1:
			testCallByValue();
			break;
		case 2:
			testCallByReference();
			break;
		case 3:
			/*int num_1 = 8;
			int num_2 = 9;
			swapNumbers(num_1, num_2);
			cout << num_1 << " - " << num_2 << endl;
			*/break;
		case 4:
			/*Student Chad;
			Chad.age = 16;
			Chad.name = "Chad";
			Chad.studyProgram = "High School";
			printStudent(Chad);
			*/break;
		case 5:
			/*Student Ichigo;
			Ichigo.age = 20;
			Ichigo.name = "Ichigo";
			Ichigo.studyProgram = "Soul Reaper";
			isInProgram(Ichigo, "High School");
			isInProgram(Ichigo, "Soul Reaper");
			*/break;
		case 6:
			cout << randomizeString(5,97,122) << endl;
			break;
		case 7:
			testString();
			break;
		case 8:
			cout << readInputToString(3, 'G', 'A');
			break;
		case 9:
			cout << countChar("ACBACDBE", 'A');
			break;
		case 10:
			playMastermind();
			break;
		case 11:
			int test;
			test = checkCharactersAndPosition("AABB", "ACBD");
			cout << test;
			break;
		case 12:
			string Test = "TEST";
			string Test_2 = "TEST";
			cout << checkCharacters(Test, Test_2);
			break;
	}
}
