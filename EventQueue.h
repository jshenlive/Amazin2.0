// CLASS: EventQueue
//
// Author: Jesse Shen, 7909192
//
// REMARKS: Subclass of List, simulates an EventQueue, takes in orders and process them in order, with shipping events processed first, then by orderID
//
//-----------------------------------------
#pragma once

#include "List.h"
#include "Order.h"

class EventQueue {
    private:
        int numEmployee;
        List* prepareList;
        List* arrivalList;
        List* shippingList;
        List* emptyNodes;
        List* currentQueue;

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

        void addEvent(Event*);

        void runEventQueue(int);

        void orderedInsert(Node *);

        //getters
        int getNumShippedItems();
};
