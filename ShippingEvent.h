// CLASS: ShippingEvent
//
// Author: Jesse Shen, 7909192
//
// REMARKS: subclass of Event class, with overwrite print function for eventQueue
//
//-----------------------------------------
#pragma once

#include "Event.h"
#include "PrepareEvent.h"

class ShippingEvent : public Event {
    public:
        static const int PRIMERO_SHIPPING_DAY;
        static const int STANDARD_SHIPPING_DAY;

        ShippingEvent();

        ShippingEvent(int, Order *);

        ~ShippingEvent();

        virtual void print() override;

        void calculatePenalty();
};

