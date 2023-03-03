// CLASS: EventQueue
//
// Author: Jesse Shen, 7909192
//
// REMARKS: Subclass of List, simulates an EventQueue, takes in orders and process them in order, with shipping events processed first, then by orderID
//
//-----------------------------------------

#include "EventQueue.h"
#include "ArrivalEvent.h"
#include "PrepareEvent.h"
#include "ShippingEvent.h"


using namespace std;

//Constructor
EventQueue::EventQueue() {}

EventQueue::EventQueue(int numEmployee) : numEmployee(numEmployee + 1) {
    prepareList = new List();
    arrivalList = new List();
    shippingList = new List();
    emptyNodes = new List();
    currentQueue = new List();
}

//Destructor
EventQueue::~EventQueue() {
    //each list is an instance of List which deletes its Nodes and items
    delete prepareList;
    delete arrivalList;
    delete shippingList;
    delete emptyNodes;
}

//Instance Methods

//------------------------------------------------------
// addArrivalEvent
//
// PURPOSE:    adds arrival event to arrivalList, prints out arrival message
// PARAMETERS:
//              takes in current hour, and a new order,
//              for two arrival at the same time: inserts by customer type, primero first then standard
//              this list is used to determine the order for prepare events
//------------------------------------------------------
void EventQueue::addArrivalEvent(int currHour, Order *order) {
    //New memory allocated deletes from arrayList
    ArrivalEvent *newArrival = new ArrivalEvent(currHour, order);   //frees when removes from list
    Node *newNode = new Node(newArrival, nullptr);

    string primero = "Primero";
    string standard = "Standard";

    order->setArrivalTime(currHour);

    //sorts arrival node into arrivalList an ordered list
    if (arrivalList->getTop() == nullptr) {    //check top node of the list
        arrivalList->setTop(newNode);
    } else {
        Node *currNode = arrivalList->getTop();
        //if order is a primero type,
        if (0 == order->getCustomerLabel().compare(primero)) {
            //check top
            Event *topEvent = currNode->getEvent();
            Order *topOrder = topEvent->getOrder();

            // primero always get priority over standard
            if (0 == topOrder->getCustomerLabel().compare(standard)) {
                newNode->setNext(currNode);
                arrivalList->setTop(newNode);
            } else {

                bool found = false;
                //find next non primero order in the list
                while (!found && currNode->getNext() != nullptr) {
                    Event *nextEvent = currNode->getNext()->getEvent();
                    Order *nextOrder = nextEvent->getOrder();
                    if (0 == nextOrder->getCustomerLabel().compare(standard)) {
                        found = true;
                        newNode->setNext(currNode->getNext());
                    } else {
                        currNode = currNode->getNext();
                    }
                }

                currNode->setNext(newNode);
            }

        } else {
            //new order is not primero type, insert to end
            while (currNode->getNext() != nullptr) {
                currNode = currNode->getNext();
            }
            currNode->setNext(newNode);
        }
        //increment list length;
        arrivalList->incLength();
    }

    //add ArrivalEvent to eventQueue to be printed
    addEvent(newArrival);
}

//------------------------------------------------------
// addPrepareEvent
//
// PURPOSE:    adds prepare event to prepareList, prints out prepare message
// PARAMETERS:
//              added when there is available employee,
//              works on the first order on arrival list
//------------------------------------------------------
void EventQueue::addPrepareEvent(int currHour, Order *order) {
    order->setStartTime(currHour);

    //New memory allocated deletes from PrepareList
    PrepareEvent *newPrepare = new PrepareEvent(currHour, order);
    Node *newNode = new Node(newPrepare, nullptr);

    //add according to first in first out
    if (prepareList->getTop() == nullptr) {
        prepareList->setTop(newNode);
    } else {
        Node *temp = prepareList->getTop();
        while (temp->getNext() != nullptr) {
            temp = temp->getNext();
        }
        temp->setNext(newNode);
    }
    prepareList->incLength();

    //add to evenQueue to be printed out
    addEvent(newPrepare);
}

//------------------------------------------------------
// addshippingEvent
//
// PURPOSE:    adds Shipping event to shippingList, prints out shipping message
// PARAMETERS:
//              added when prepareEvents are completed,
//              nodes are added to shipping list for destructuring
//------------------------------------------------------
void EventQueue::addShippingEvent(int currHour, Order *order) {
    //New memory allocated deletes from shippingList
    ShippingEvent *newShipping = new ShippingEvent(currHour, order);
    Node *newNode = new Node(newShipping, nullptr);

    //ordered as first in
    if (shippingList->getTop() == nullptr) {
        shippingList->setTop(newNode);
    } else {
        Node *temp = shippingList->getTop();
        while (temp->getNext() != nullptr) {
            temp = temp->getNext();
        }
        temp->setNext(newNode);
    }
    shippingList->incLength();

    //add shipping event to eventQueue and prints out message
    addEvent(newShipping);

}

//------------------------------------------------------
// runEventQueue
//
// PURPOSE:    manages all orders with working hour
// PARAMETERS:
//              takes in currHour as working current hour, compares the value with event times
//              when match is found, sends of to the next process in line until completes
//              which then prints out all the eventQueue events
//------------------------------------------------------
void EventQueue::runEventQueue(int currHour) {

    if (!prepareList->isEmpty()) {
        Node *topPrepare = prepareList->getTop();
        Event *topPrepareEvent = topPrepare->getEvent();

        //when order is finished preparing send to shippingList
        while (topPrepare != nullptr && currHour == topPrepareEvent->getOrder()->getFinishTime()) {
            Node *temp = topPrepare->getNext();
            topPrepare = prepareList->removeTopNode();
            emptyNodes->addFront(topPrepare);   //free unused nodes
            addShippingEvent(currHour, topPrepareEvent->getOrder());
            topPrepare = temp;
            if (topPrepare != nullptr) {
                topPrepareEvent = topPrepare->getEvent();
            }
        }
    }

    //when new order arrives send to prepare if employee available
    while (arrivalList->getTop() != nullptr && prepareList->getLength() < numEmployee) {
        Node *topArrival = arrivalList->removeTopNode();
        emptyNodes->addFront(topArrival);   //free unused nodes
        Event *topEvent = topArrival->getEvent();
        if (topEvent != nullptr) {
            addPrepareEvent(currHour, topEvent->getOrder());
        }
    }

    //prints out all events at the current hour
    Node *eventNode = currentQueue->getTop();
    while (eventNode != nullptr) {
        Node *next = eventNode->getNext();
        eventNode->getItem()->print();
        eventNode = next;
        currentQueue->setTop(eventNode);
    }
}

//add Event to EventQueue
void EventQueue::addEvent(Event *event) {
    if (currentQueue->getTop() == nullptr) {
        currentQueue->setTop(new Node(event, nullptr));
    } else {
        orderedInsert(new Node(event, nullptr));
    }
}

//------------------------------------------------------
// orderedInsert
//
// PURPOSE:    helper function to order all eventQueue items
// PARAMETERS:
//              sorts a given node events in eventQueue list,
//              so that each message is printed out corresponding to given rules
//------------------------------------------------------
void EventQueue::orderedInsert(Node *node) {
    string shipping = "shipping";

    //pointers for new Event values
    Event *newEvent = node->getEvent();
    Order *newOrder = newEvent->getOrder();
    int newOrderId = newOrder->getId();

    //pointers for current Event values
    Event *topEvent = currentQueue->getTop()->getEvent();
    Order *topOrder = topEvent->getOrder();
    int topOrderId = topOrder->getId();

    //helper pointers
    Node *curr = currentQueue->getTop();
    Event *currEvent;
    Order *currOrder;
    int currOrderId;

    //first sort by shipping events
    if (0 == newEvent->getLabel().compare(shipping)) {
        if (0 != topEvent->getLabel().compare(shipping)) { // if top is not shipping type event
            node->setNext(currentQueue->getTop());
            currentQueue->setTop(node);

        } else if (currentQueue->getTop()->getNext() == nullptr) { //only one node to compare
            if (topOrderId > newOrderId) {
                node->setNext(currentQueue->getTop());
                currentQueue->setTop(node);
            } else {
                currentQueue->getTop()->setNext(node);
            }
        } else {    //all other cases when newEvent is a shipping type
            curr = currentQueue->getTop();
            currEvent = curr->getNext()->getEvent();
            currOrder = currEvent->getOrder();
            currOrderId = currOrder->getId();
            while (curr->getNext() != nullptr && currOrderId < newOrderId) {
                curr = curr->getNext();
                if (curr->getNext() != nullptr) {
                    currEvent = curr->getNext()->getEvent();
                    currOrder = currEvent->getOrder();
                    currOrderId = currOrder->getId();
                }
            }
            node->setNext(curr->getNext());
            curr->setNext(node);
        }
    } else {  //if newNode is not shipping event
        if (currentQueue->getTop()->getNext() == nullptr) { // if only one event in the queue
            if (0 != topEvent->getLabel().compare(shipping) && topOrderId > newOrderId) {
                node->setNext(currentQueue->getTop());
                currentQueue->setTop(node);
            } else {
                currentQueue->getTop()->setNext(node);
            }
        } else if (curr->getNext() != nullptr) { // all other cases
            currEvent = curr->getNext()->getEvent();

            //skip all shipping events
            while (curr->getNext() != nullptr && 0 == currEvent->getLabel().compare(shipping)) {
                curr = curr->getNext();
                if (curr->getNext() != nullptr) {
                    currEvent = curr->getNext()->getEvent();
                }
            }

            //then compare with order id
            currOrder = currEvent->getOrder();
            currOrderId = currOrder->getId();
            while (curr->getNext() != nullptr && currOrderId <= newOrderId) {
                curr = curr->getNext();
                if (curr->getNext() != nullptr) {
                    currEvent = curr->getNext()->getEvent();
                    currOrder = currEvent->getOrder();
                    currOrderId = currOrder->getId();
                }
            }
            //add Event into ordered list
            node->setNext(curr->getNext());
            curr->setNext(node);
        }
    }
}

int EventQueue::getNumShippedItems() {
    return shippingList->getLength();
}