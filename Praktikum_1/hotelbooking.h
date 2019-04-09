#ifndef HOTELBOOKING_H
#define HOTELBOOKING_H

#include <string>

using namespace std;

class HotelBooking
{
public:
    HotelBooking();
    HotelBooking(long id, double price, string fromDate, string toDate, string hotel, string town); //Konstruktor

    //GET-Methoden

    long getId() const;

    double getPrice() const;

    string getFromDate() const;

    string getToDate() const;

    string getHotel() const;

    string getTown() const;

private:
    long id;
    double price;
    string fromDate;
    string toDate;
    string hotel;
    string town;

};

#endif // HOTELBOOKING_H
