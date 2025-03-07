#pragma once

// BEGIN: 1a
class Car{
    private:
    int freeSeats;

    public:
    bool hasFreeSeats() const;
    void reserveFreeSeat();

    Car(int num);
};
// END: 1a 