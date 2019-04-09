#include "rentalcarreservation.h"

RentalCarReservation::RentalCarReservation()
{

}

RentalCarReservation::RentalCarReservation(long id, double price, string fromDate, string toDate, string pickupLocation, string returnLocation, string company)
{
    this->id = id;
    this->price = price;
    this->fromDate = fromDate;
    this->toDate = toDate;
    this->pickupLocation = pickupLocation;
    this->returnLocation = returnLocation;
    this->company = company;
}

long RentalCarReservation::getId() const
{
    return id;
}

double RentalCarReservation::getPrice() const
{
    return price;
}

string RentalCarReservation::getFromDate() const
{
    return fromDate;
}

string RentalCarReservation::getToDate() const
{
    return toDate;
}

string RentalCarReservation::getPickupLocation() const
{
    return pickupLocation;
}

string RentalCarReservation::getReturnLocation() const
{
    return returnLocation;
}

string RentalCarReservation::getCompany() const
{
    return company;
}
