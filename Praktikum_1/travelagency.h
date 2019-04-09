#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H

#include <rentalcarreservation.h>
#include <hotelbooking.h>
#include <flightbooking.h>

#include <string>
#include <vector>

using namespace std;

class TravelAgency
{
public:
    TravelAgency();
    void readFile();
    void readBinaryFile();
private:
    vector <RentalCarReservation*> rentalCarReservations;
    vector <HotelBooking*> hotelBookings;
    vector <FlightBooking*> flightBookings;
};



#endif // TRAVELAGENCY_H
