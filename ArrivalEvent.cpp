// CLASS: ArrivalEvent
//
// Author: Jesse Shen, 7909192
//
// REMARKS: subclass of Event class, with overwrite print function for eventQueue
//
//-----------------------------------------

#include "ArrivalEvent.h"
#include "Order.h"
#include <iostream>
using namespace std;
ArrivalEvent::ArrivalEvent() {}
ArrivalEvent::~ArrivalEvent() {}

ArrivalEvent::ArrivalEvent(int h, Order* o) {
//    startTime = h;
    order = o;
    label = "arrival";
}

void ArrivalEvent::print() {
    cout << "TIME: " << order->getArrivalTime() << " -> ";
    order->print();
    cout << " arrives." << endl;
}