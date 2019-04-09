#include "travelagency.h"

#include <iostream>
#include <fstream>
#include <string>

TravelAgency::TravelAgency()
{

}



    vector<string> spalteString(string a, char Trennstrich){

    //Vektor für Position des Trennstrichs
    vector<unsigned int> spalte_Positionen;

    //Vektor für alle Elemente ohne Trennstrich
    vector<string> Return;

    //Position des Trennstrichs
    for (unsigned int i = 0; i < a.length(); i++){
        if(a[i] == Trennstrich){
            spalte_Positionen.push_back(i);
        }
    }


    //F,R oder H
    Return.push_back(a.substr(0,spalte_Positionen[0]));


    //Elemente zwischen Trennstrich filtern
    for (unsigned int i = 0; i< spalte_Positionen.size(); i++){
        Return.push_back(a.substr(spalte_Positionen[i] +1,spalte_Positionen[i+1] - spalte_Positionen[i] - 1));
    }

    return Return;


}

void TravelAgency::readFile()
{
    string Zeile;

    ifstream Textdatei("bookings.txt");

    int flugbuchungen_anzahl{0};
    int mietwagenbuchungen_anzahl{0};
    int hotelreservierungen_anzahl{0};

    double flugbuchungen_wert{0};
    double mietwagenbuchungen_wert{0};
    double hotelreservierungen_wert{0};

    //Vektor für alle Zeilen
    vector<string> Zeilen;


    if(!Textdatei){
        cerr << "Datei kann nicht geöffnet werden" << endl;
    }

    //Finde alle Zeilen und speichere sie im Vektor Zeilen
    while(getline(Textdatei, Zeile)){
        Zeilen.push_back(Zeile);
    }

    //Vektor für den gesamten Datensatz
    vector<vector<string>> Daten;

    for (unsigned int i = 0; i < Zeilen.size(); i++){
            vector<string> spalten = spalteString(Zeilen[i],'|');
            Daten.push_back(spalten);
    }

    //Alle Datensätze durchgehen
    for(unsigned int i = 0; i < Daten.size(); i++){


        //Flugbuchung
        if(Daten[i][0][0] == 'F'){




            long id = stol(Daten[i][1]);
            double price = stod(Daten[i][2]);
            string fromDate = Daten[i][3];
            string toDate = Daten[i][4];
            string fromDest = Daten[i][5];
            string toDest = Daten[i][6];
            string airline = Daten[i][7];

            flugbuchungen_anzahl++;

            flugbuchungen_wert += price;

            FlightBooking flightbooking(id,price, fromDate, toDate, fromDest, toDest, airline);

            flightBookings.push_back(&flightbooking);



        }


        //Hotelbuchung
        if(Daten[i][0][0] == 'H'){


            long id = stol(Daten[i][1]);
            double price = stod(Daten[i][2]);
            string fromDate = Daten[i][3];
            string toDate = Daten[i][4];
            string hotel = Daten[i][5];
            string town = Daten[i][6];

            hotelreservierungen_anzahl++;

            hotelreservierungen_wert += price;

            HotelBooking hotelbooking(id,price, fromDate, toDate, hotel, town);

            hotelBookings.push_back(&hotelbooking);


        }

        //Automvermietung
        if(Daten[i][0][0] == 'R'){


            long id = stol(Daten[i][1]);
            double price = stod(Daten[i][2]);
            string fromDate = Daten[i][3];
            string toDate = Daten[i][4];
            string pickupLocation = Daten[i][5];
            string returnLocation = Daten[i][6];
            string company = Daten[i][7];

            mietwagenbuchungen_anzahl++;

            mietwagenbuchungen_wert += price;

            RentalCarReservation rentalcarreservation(id,price, fromDate, toDate, pickupLocation, returnLocation, company);

            rentalCarReservations.push_back(&rentalcarreservation);


        }
    }

    cout << "Es wurden " << flugbuchungen_anzahl  << " Flugbuchungen im Wert von " << flugbuchungen_wert << " Euro,\n" << mietwagenbuchungen_anzahl << " Mietwagenbuchungen im Wert von " << mietwagenbuchungen_wert << " Euro \nund " << hotelreservierungen_anzahl << " Hotelreservierungen im Wert von " << hotelreservierungen_wert << " Euro angelegt." << endl << endl;





}


void TravelAgency::readBinaryFile()
{
    ifstream eingabe;
    eingabe.open("bookingsBinary.bin", ios::in | ios::binary);


    int flugbuchungen_anzahl{0};
    double flugbuchungen_wert{0};

    int hotelreservierungen_anzahl{0};
    double hotelreservierungen_wert{0};

    int mietwagenbuchungen_anzahl{0};
    double mietwagenbuchungen_wert{0};

    if(eingabe.is_open()){

        int size{0};
        int aktuell{0};

        //End-Position ermitteln
        eingabe.seekg(0,ios::end);

        //End-Position zwischenspeichern
        size = (int)eingabe.tellg();

        //Zur Anfangsposition zurückspringen
        eingabe.seekg(0, ios::beg);

        //Anfangsposition zwischenspeichern
        aktuell = (int)eingabe.tellg();


        while(aktuell < size && aktuell >= 0){
            char letter{0};
            long id{0};
            double price{0};
            char fromDate[9]{0};
            char toDate[9]{0};

            char fromDest[4]{0};
            char toDest[4]{0};
            char airline[16]{0};

            char hotel[16]{0};
            char town[16]{0};

            char pickupLocation[16]{0};
            char retLocation[16]{0};
            char company[16]{0};

            eingabe.read((char*)&letter, sizeof (char));

            eingabe.read((char*)&id,sizeof (long));
            eingabe.read((char*)&price,sizeof (double));
            eingabe.read((char*)&fromDate,sizeof (char)*8);
            eingabe.read((char*)&toDate,sizeof (char)*8);

            if(letter == 'F'){
                eingabe.read((char*)&fromDest,sizeof (char)*3);
                eingabe.read((char*)&toDest,sizeof (char)*3);
                eingabe.read((char*)&airline,sizeof (char)*15);


                flightBookings.push_back(new FlightBooking(id, price, fromDate, toDate, fromDest, toDest, airline));
                flugbuchungen_anzahl++;


            }

            if(letter == 'H'){
                eingabe.read((char*)&hotel,sizeof (char)*15);
                eingabe.read((char*)&town,sizeof (char)*15);

                hotelBookings.push_back(new HotelBooking(id, price, fromDate, toDate, hotel, town));
                hotelreservierungen_anzahl++;

            }

            if(letter == 'R'){
                eingabe.read((char*)&pickupLocation, sizeof (char)*15);
                eingabe.read((char*)&retLocation, sizeof (char)*15);
                eingabe.read((char*)&company, sizeof (char)*15);

                rentalCarReservations.push_back(new RentalCarReservation(id, price, toDate, fromDate, pickupLocation, retLocation, company));
                mietwagenbuchungen_anzahl++;
            }


            //Momentane Position ermitteln
            aktuell = eingabe.tellg();







        }
        eingabe.close();

    }else{
        cout << "Datei konnte nicht geoeffnet werden!" << endl;
        return;
    }






    int max = 0;

    for(int i = 0; i < this->flightBookings.size(); i++){
        flugbuchungen_wert += flightBookings[i]->getPrice();
        if(this->flightBookings[i]->getPrice() > this->flightBookings[max]->getPrice()){
            max = i;

        }
    }

    cout << "Der Teuerste Flug (ID:" << flightBookings[max]->getId() << "): Vom " << flightBookings[max]->getFromDate() << " bis " << flightBookings[max]->getToDate() << " von " << flightBookings[max]->getFromDest() << " nach " << flightBookings[max]->getToDest() << "\nmit " << flightBookings[max]->getAirline() << " zum Preis von " << flightBookings[max]->getPrice() << " Euro" << endl << endl << endl;

    max = 0;

    for(int i = 0; i < this->rentalCarReservations.size(); i++){
        mietwagenbuchungen_wert += rentalCarReservations[i]->getPrice();
        if(this->rentalCarReservations[i]->getPrice() > this->rentalCarReservations[max]->getPrice()){
            max = i;

        }
    }

    cout << "Teuerste Mietwagenbuchung (ID:" << rentalCarReservations[max]->getId() << "): Vom " << rentalCarReservations[max]->getFromDate() << " bis " << rentalCarReservations[max]->getToDate() << " von " << rentalCarReservations[max]->getPickupLocation() << " nach " << rentalCarReservations[max]->getReturnLocation() << "\nmit " << rentalCarReservations[max]->getCompany() << " zum Preis von " << rentalCarReservations[max]->getPrice() << " Euro" << endl << endl << endl;

    max = 0;

    for(int i = 0; i < this->hotelBookings.size(); i++){
         hotelreservierungen_wert += hotelBookings[i]->getPrice();
        if(this->hotelBookings[i]->getPrice() > this->hotelBookings[max]->getPrice()){
            max = i;

        }
    }

    cout << "Teuerste Hotelbuchung (ID:" << hotelBookings[max]->getId() << "): Vom " << hotelBookings[max]->getFromDate() << " bis " << hotelBookings[max]->getToDate() << " im " << hotelBookings[max]->getHotel() << "\nin " << hotelBookings[max]->getTown() << " zum Preis von " << hotelBookings[max]->getPrice() << "Euro" << endl << endl << endl;

    cout << "Es wurden " << flugbuchungen_anzahl  << " Flugbuchungen im Wert von " << flugbuchungen_wert << " Euro,\n" << mietwagenbuchungen_anzahl << " Mietwagenbuchungen im Wert von " << mietwagenbuchungen_wert << " Euro \nund " << hotelreservierungen_anzahl << " Hotelreservierungen im Wert von " << hotelreservierungen_wert << " Euro angelegt." << endl << endl << endl;


}


