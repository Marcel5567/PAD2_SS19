#include "hotelbooking.h"

HotelBooking::HotelBooking()
{

}

HotelBooking::HotelBooking(long id, double price, string fromDate, string toDate, string hotel, string town)
{
    this->id = id;
    this->price = price;
    this->fromDate = fromDate;
    this->toDate = toDate;
    this->hotel = hotel;
    this->town = town;

}

long HotelBooking::getId() const
{
    return id;
}

double HotelBooking::getPrice() const
{
    return price;
}

string HotelBooking::getFromDate() const
{
    return fromDate;
}

string HotelBooking::getToDate() const
{
    return toDate;
}

string HotelBooking::getHotel() const
{
    return hotel;
}

string HotelBooking::getTown() const
{
    return town;
}
