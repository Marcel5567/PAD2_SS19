#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "travel.h"
#include <vector>
#include <iostream>

using namespace std;

class Customer
{
public:
    Customer();
    void addTravel(Travel* travel);

private:
    long id;
    string name;
    vector<Travel*> travelList;
};

#endif // CUSTOMER_H
