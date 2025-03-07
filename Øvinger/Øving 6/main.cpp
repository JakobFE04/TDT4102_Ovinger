#include "std_lib_facilities.h"
#include "CourseCatalog.h"
#include "FileUtils.h"
#include "bouncingBall.h"


int main()
{
	int input;
	cout << "Hvilken funksjon vil du teste? ";
	cin >> input;
	switch(input){
		case 1:
			writeUserInputToFile("D:\Vår25\FagnotatV25\C++\TDT4102_Ovinger");
			break;
		case 2:
			addLineNumbers("writeUserInputToFile.txt");
			break;
		case 3:
			testCourseCatalog();
			break;
		case 4:
			std::filesystem::path config_file{"konfigurasjon.txt"};
			std::ifstream is{config_file};
			Config slow;
			is >> slow;
			cout << slow.color_up << endl;
			cout << slow.color_down << endl;
			cout << slow.velocity << endl;
		}
	
	// Her kan du teste din kode ved å kalle på de ulike funksjonene du har implementert	
	return 0;
}