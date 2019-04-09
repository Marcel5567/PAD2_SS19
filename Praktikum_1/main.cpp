#include <iostream>
#include <travelagency.h>
#include <windows.h>

using namespace std;



int main()
{

    TravelAgency TravelAgency;

    int a;

    //DIALOG

    while(true){


        cout << "1: Textdatei einlesen" << endl;
        cout << "2: Binaerdatei einlesen" << endl;
        cout << "0: Programm beenden" << endl << endl;

        cin >> a;
        cout << "\n";

        switch (a) {

        case 1:
            TravelAgency.readFile();
            break;
        case 2:
            TravelAgency.readBinaryFile();
            break;
        case 0:
            exit(0);
        default:
            cout << "Falsche Eingabe. Bitte erneut eingeben \n \n" << endl;;
            break;

        }
    }


    return 0;
}
