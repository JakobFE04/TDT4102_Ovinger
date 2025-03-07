#include "FileUtils.h"
#include <filesystem>


void writeUserInputToFile(const std::string &path)
{
	// BEGIN: 1a
	string input;
	cout << "Write 'quit' to exit." << endl;
	cin >> input;
	filesystem::path fileName{"writeUserInputToFile.txt"};
	ofstream outputStream{fileName};
	while (input != "quit"){
		outputStream << input << endl;
		cin >> input;
	}
	// END: 1a
}


void addLineNumbers(const std::string &filename)
{
	// BEGIN: 1b
	ifstream inputStream(filename);
	if (!inputStream){
		cout << "Could not open file" << endl; 
	}
	string nextWord;
	filesystem::path lineNumber{filename + ".linum"};
	ofstream outputStream{lineNumber};
	int count = 0;
	while (inputStream >> nextWord){
		count += 1;
		outputStream << count << nextWord << endl;
	}
	// END: 1b
}