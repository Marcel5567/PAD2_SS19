#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H

#include "booking.h"
#include "travel.h"
#include "customer.h"
#include <vector>
#include <iostream>

using namespace std;

class TravelAgency
{
public:
    TravelAgency();
    void readFile();
    Booking* findBooking(long id);
    Travel* findTravel(long id);
    Customer* findCostumer(long id);

private:
    vector<Booking*> allBookings;
    vector<Travel*> allTravels;
    vector<Customer*> allCustomer;

};

#endif // TRAVELAGENCY_H
