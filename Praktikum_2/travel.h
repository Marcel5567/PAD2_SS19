#ifndef TRAVEL_H
#define TRAVEL_H

#include "booking.h"
#include <vector>
#include <iostream>

using namespace std;

class Travel
{
public:
    Travel();
    void addBooking(Booking* booking);

private:
    long id;
    vector<Booking*> travelBookings;
};

#endif // TRAVEL_H
