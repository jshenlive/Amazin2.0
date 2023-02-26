// CLASS: PrepareEvent
//
// Author: Jesse Shen, 7909192
//
// REMARKS: Subclass of Event class, with overwrite print function for EventQueue
//
//-----------------------------------------
#include "PrepareEvent.h"
#include "Order.h"
#include <iostream>

using namespace std;

//constructor
PrepareEvent::PrepareEvent() {}

PrepareEvent::PrepareEvent(int h, Order *o) {
    order = o;
    label = "prepare";
}

//destructor
PrepareEvent::~PrepareEvent() {}

//override method
void PrepareEvent::print() {
    cout << "TIME: " << order->getStartTime() << " -> ";
    order->print();
    cout << " is being prepared (prep.time = " << order->getProcessingTime() << ")." << endl;
}