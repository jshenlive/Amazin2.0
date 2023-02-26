// CLASS: Helper
//
// Author: Jesse Shen, 7909192
//
// REMARKS: Helper function for main method, includes the simulation process
//
//-----------------------------------------

#include "Helper.h"
#include "WorkingHour.h"
#include "EventQueue.h"
#include "Revenue.h"
#include <iomanip>
#include <iostream>

using namespace std;

void Helper::startSimulation(Queue *orderList, int numEmployee) {

    //Start simulation process
    cout << "Simulation begins..." << endl;
    EventQueue *eventQueue = new EventQueue(numEmployee);
    WorkingHour *workingHour = new WorkingHour;
    bool completeSimulation = false;
    Node *curr;
    Order *currOrder;

    //get first order if not empty orderList
    if (!orderList->isEmpty()) {
        curr = orderList->getTop();
        currOrder = dynamic_cast<Order *>(curr->getItem());
    }

    //run simulation until all events are completed
    while (!completeSimulation) {

        //add each order according to current hour
        while (curr != nullptr && currOrder->getOrderTime() == workingHour->getCurrentHour()) {

            eventQueue->addArrivalEvent(workingHour->getCurrentHour(), currOrder);
            Revenue::addRevenue(currOrder->getOrderAmount());
            curr = curr->getNext();
            if (curr != nullptr) {
                currOrder = dynamic_cast<Order *>(curr->getItem());
            }
        }

        //process eventQueue events according to current hour
        eventQueue->runEventQueue(workingHour->getCurrentHour());

        //loop end condition or increment working hour
        if (eventQueue->getNumShippedItems() == orderList->getLength()) {
            completeSimulation = true;
        } else {
            if (workingHour->getCurrentHour() % 8 == 0) {
                workingHour->addWorkingDay();
            }
            workingHour->addWorkingHour();
        }
    }

    //set total wage according to working days
    Revenue::setTotalWage(numEmployee, workingHour->getCurrentDay());

    //print end message
    printEnd(workingHour->getCurrentDay(),numEmployee);

    //delete all used memory
    delete workingHour;
    delete orderList;
    delete eventQueue;

}

void Helper::printEnd(int numDay,int numEmployee) {
    cout << endl;
    cout << fixed << setprecision(2);
    cout << "############################" << endl;
    cout << "The simulation has ended." << endl;
    cout << "The number of additional workers was " << numEmployee << "." << endl;
    cout << "The total number of work days was " << numDay << "." << endl;
    cout << "The cost of the additional workers was $" << Revenue::getTotalWage() << endl;
    cout << "The total profit before paying workers was $" << Revenue::getProfit() << endl;
    cout << "The total profit when considering additional workers was $" << Revenue::getTotalProfit() << endl;
    cout << "############################" << endl;
}
