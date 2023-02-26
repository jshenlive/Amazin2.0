// CLASS: Event
//
// Author: Jesse Shen, 7909192
//
// REMARKS: Event class subclass of Company, with child include ArrivalEvent, PrepareEvent, and ShippingEvent
//
//-----------------------------------------

#include "Event.h"
#include "Order.h"

//Constructor
Event::Event() {}
//Destructor
Event::~Event() {}

//Instance Method
void Event::print() {}

//Accessor
Order* Event::getOrder() {
    return order;
}
int Event::getId() {
    return order->getId();
}
string Event::getLabel() {
    return label;
}
