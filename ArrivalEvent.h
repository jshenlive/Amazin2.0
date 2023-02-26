// CLASS: ArrivalEvent
//
// Author: Jesse Shen, 7909192
//
// REMARKS: subclass of Event class, with overwrite print function for eventQueue
//
//-----------------------------------------
#pragma once

#include "Event.h"

class ArrivalEvent : public Event{

public:
    //Constructor
    ArrivalEvent();
    ArrivalEvent(int,Order*);

    //Destructor
    ~ArrivalEvent();

    //Overwrite Method
    virtual void print() override;
};

