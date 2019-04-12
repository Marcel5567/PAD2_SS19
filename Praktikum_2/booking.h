#ifndef BOOKING_H
#define BOOKING_H


#include <iostream>

using namespace std;

class Booking
{
public:
    Booking();

protected:
    long id;
    double price;
    long tavelId;
    string fromDate;
    string toDate;
};

#endif // BOOKING_H
