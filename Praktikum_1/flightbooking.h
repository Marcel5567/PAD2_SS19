#ifndef FLIGHTBOOKING_H
#define FLIGHTBOOKING_H

#include <string>

using namespace std;

class FlightBooking
{
public:
    FlightBooking();
    FlightBooking(long id, double price, string fromDate, string toDate, string fromDest, string toDest, string airline); //Konstruktor


    //GET-Methoden

    long getId() const;

    double getPrice() const;

    string getFromDate() const;

    string getToDate() const;

    string getFromDest() const;

    string getToDest() const;

    string getAirline() const;

private:
    long id;
    double price;
    string fromDate;
    string toDate;
    string fromDest;
    string toDest;
    string airline;
};

#endif // FLIGHTBOOKING_H
