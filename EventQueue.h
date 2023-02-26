// CLASS: EventQueue
//
// Author: Jesse Shen, 7909192
//
// REMARKS: Subclass of Queue, simulates an EventQueue, takes in orders and process them in order, with shipping events processed first, then by orderID
//
//-----------------------------------------
#pragma once

#include "Queue.h"
#include "Order.h"

class EventQueue : public Queue {
private:
    int numEmployee;
    Queue* prepareList;
    Queue* arrivalList;
    Queue* shippingList;
    Queue* emptyNodes;
//    int numShippedItems;

public:
    //constructor
    EventQueue();

    EventQueue(int);

    //destructor
    ~EventQueue();

    //instance methods
    void addArrivalEvent(int, Order *);

    void addPrepareEvent(int, Order *);

    void addShippingEvent(int, Order *);

    void runEventQueue(int);

    void addEvent(Event*);

    void orderedInsert(Node *);


    //getters
    int getNumShippedItems();


};
