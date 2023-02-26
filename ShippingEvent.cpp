// CLASS: ShippingEvent
//
// Author: Jesse Shen, 7909192
//
// REMARKS: subclass of Event class, with overwrite print function for eventQueue
//
//-----------------------------------------
#include "ShippingEvent.h"
#include "Order.h"
#include "Revenue.h"
#include <iostream>

using namespace std;

const int ShippingEvent::PRIMERO_SHIPPING_DAY=0;
const int ShippingEvent::STANDARD_SHIPPING_DAY=2;

//Constructor
ShippingEvent::ShippingEvent() {}

ShippingEvent::ShippingEvent(int h, Order *o) {
    order = o;
    label = "shipping";
}

//Destructor
ShippingEvent::~ShippingEvent() {}

//prints out shipping message with penalties if any
void ShippingEvent::print() {

    cout << "TIME: " << order->getFinishTime() << " -> ";
    order->print();
    cout << " has been shipped.";

    calculatePenalty();

    if (order->getPenalty()) {
        Revenue::addTotalPenalty(order->getPenaltyAmount());
        cout << " ***Penalty paid: $" << order->getPenaltyAmount() << "." << endl;
    } else {
        cout << endl;
    }
}

//calculates penalty base on customer type,
void ShippingEvent::calculatePenalty() {
    int totalTime = (order->getFinishTime() + 0.5) / 8 - (order->getArrivalTime() + 0.5) / 8;

    if (order->getCustomer() == Order::PRIMERO_IND) {
        if (totalTime > PRIMERO_SHIPPING_DAY) {
            order->setPenalty(true);
        }
    } else {
        if (totalTime > STANDARD_SHIPPING_DAY) {
            order->setPenalty(true);
        }
    }

}