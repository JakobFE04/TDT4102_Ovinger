
#pragma once
#include "std_lib_facilities.h"

// BEGIN: 1b
 // deklarerer funksjonen incrementByValueNumTimes her
int incrementByValueNumTimes(int startValue, int increment, int numTimes);
// END: 1b

// BEGIN: 1d
 // deklarerer funksjonen incrementByValueNumTimesRef her
void incrementByValueNumTimesRef(int& startValueRef, int increment, int numtimes);
// END: 1d

// BEGIN: 1e
 // deklarerer funksjonen swapNumbers her
void swapNumbers(int& value_1, int& value_2);
// END: 1e

// BEGIN: 2a
 // lag struct Student her
struct Student{
    string name;
    string studyProgram;
    int age;
};
// END: 2a

// BEGIN: 2b
// deklarerer funksjonen printStudent her
void printStudent(Student stud);
// END: 2b

// BEGIN: 2c
// deklarerer funksjonen isInProgram her
bool isInProgram(Student stud, string program);
// END: 2c

// BEGIN: 3a
 // deklarerer funksjonen randomizeString her
string randomizeString(int numSymbols, int limHigh, int limLow);
// END: 3a

// BEGIN: 3c
 // deklarerer funksjonen readInputToString her
string readInputToString(int n, char limHigh, char limLow);
// END: 3c

// BEGIN: 3d
 // deklarerer funksjonen countChar her
int countChar(string countString, char countChar);
// END: 3d
