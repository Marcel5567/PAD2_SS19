#include "flightbooking.h"

FlightBooking::FlightBooking()
{

}

FlightBooking::FlightBooking(long id, double price, string fromDate, string toDate, string fromDest, string toDest, string airline)
{
    this->id = id;
    this->price  = price;
    this->fromDate = fromDate;
    this->toDate = toDate;
    this->fromDest = fromDest;
    this->toDest = toDest;
    this->airline = airline;
}

long FlightBooking::getId() const
{
    return id;
}

double FlightBooking::getPrice() const
{
    return price;
}

string FlightBooking::getFromDate() const
{
    return fromDate;
}

string FlightBooking::getToDate() const
{
    return toDate;
}

string FlightBooking::getFromDest() const
{
    return fromDest;
}

string FlightBooking::getToDest() const
{
    return toDest;
}

string FlightBooking::getAirline() const
{
    return airline;
}

