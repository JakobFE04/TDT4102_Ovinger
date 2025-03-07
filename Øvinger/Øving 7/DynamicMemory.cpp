#include <cassert>
#include <iostream>

#include "DynamicMemory.h"

// BEGIN: 1a
void fillInFibonacciNumbers(int* result, int length){
    result[0] = 0;
    result[1] = 1;
    result[2] = 1;
    for (int i=3; i<length; i++){
        result[i] = result[i-1]+result[i-2];
    }
}
// END: 1a

// BEGIN: 1b
void printArray(int* array, int length){
    for (int i=0; i < length; i++){
        std::cout << array[i] << std::endl;
    }
}
// END: 1b

// BEGIN: 1c
void createFibonacci(){
    int input;
    std::cout << "Skriv inn antall tall: ";
    std::cin >> input;
    int* Array = new int[input];

    fillInFibonacciNumbers(Array, input);
    printArray(Array,input);
    delete Array;
    Array = nullptr;
}

// END: 1c