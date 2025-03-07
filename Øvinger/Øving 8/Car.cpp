#include "Car.h"
#include <cassert>

// BEGIN 1b
Car::Car(int num) : freeSeats{num}{}
// END 1b

// BEGIN 1c
bool Car::hasFreeSeats() const {
    // try{
        if (freeSeats){
            return true;
        }  
        else{
            return false;
        } 
    }
    // catch(){
    //     return false;
    // }
    
// }
void Car::reserveFreeSeat(){
    freeSeats -= 1;
}

// END 1c 