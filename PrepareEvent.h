// CLASS: PrepareEvent
//
// Author: Jesse Shen, 7909192
//
// REMARKS: subclass of Event class, with overwrite print function for eventQueue
//
//-----------------------------------------
#pragma once

#include "Event.h"
#include "ArrivalEvent.h"

class PrepareEvent : public Event {
public:
    //constructor
    PrepareEvent();

    PrepareEvent(int, Order *);

    //destructor
    ~PrepareEvent();

    //override method
    virtual void print() override;

};

