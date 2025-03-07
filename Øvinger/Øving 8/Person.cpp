#include "Person.h"

// BEGIN 2b
Person::Person(std::string n, std::string em, std::unique_ptr<Car> c) : name{n}, email{em}, car{std::move(c)}{}

std::string Person::getName() const{
    return name;
}
std::string Person::getEmail() const{
    return email;
}
void Person::setEmail(const std::string& email){
    Person::email = email;
}
// END 2b

// BEGIN 2c
bool Person::hasAvailableSeats() const{
    if (this->car == nullptr){
        return false;
    }
    else{
        if (Person::car->hasFreeSeats()){
            return true;
        }
        else{
            return false;
        }
    }
}
// END 2c

// BEGIN 2d
std::ostream& operator<<(std::ostream& os, const Person& p){
    std::cout << "Name: " << p.name << std::endl;
    std::cout << "Email: " << p.email << std::endl;
    std::cout << "Has available seats: " << std::boolalpha << p.hasAvailableSeats() << std::endl;
    return os;
}
    
// END 2d
