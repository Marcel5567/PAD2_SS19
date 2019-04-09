#ifndef RENTALCARRESERVATION_H
#define RENTALCARRESERVATION_H

#include <string>

using namespace std;

class RentalCarReservation
{
public:
    RentalCarReservation();
    RentalCarReservation(long id, double price, string fromDate, string toDate, string pickupLocation, string returnLocation, string company); //Konstruktor

    //GET-Methoden

    long getId() const;

    double getPrice() const;

    string getFromDate() const;

    string getToDate() const;

    string getPickupLocation() const;

    string getReturnLocation() const;

    string getCompany() const;

private:
    long id;
    double price;
    string fromDate;
    string toDate;
    string pickupLocation;
    string returnLocation;
    string company;
};

#endif // RENTALCARRESERVATION_H
