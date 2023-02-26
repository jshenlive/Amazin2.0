// CLASS: Event
//
// Author: Jesse Shen, 7909192
//
// REMARKS: Event class subclass of Company, with child include ArrivalEvent, PrepareEvent, and ShippingEvent
//
//-----------------------------------------
#pragma once

#include <string>
#include "Company.h"

using namespace std;

class Order;

class Event : public Company {
protected:
    Order *order;
    string label;

public:
    //constructor
    Event();

    //destructor
    ~Event();

    //instance methods
    virtual void print() override;

    //accessors
    virtual int getId() override;

    virtual string getLabel();

    Order *getOrder();
};

