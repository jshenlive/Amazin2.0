// CLASS: Order
//
// Author: Jesse Shen, 7909192
//
// REMARKS: Stores all order related information, customer type,
//          order id, order amount, order start time, finish time, arrival time, and penalties
//
//-----------------------------------------

#include "Order.h"

#include <sstream>

#include <iostream>

using namespace std;

int Order::currentOrderId = 1;

const int Order::COMMAND_LENGTH = 3;
const int Order::INDEX_ORDER_TIME = 0;
const int Order::INDEX_CUSTOMER_TYPE = 1;
const int Order::INDEX_ORDER_VALUE = 2;
const int Order::PRIMERO_IND = 0;
const int Order::STANDARD_IND = 1;
const int Order::PROCESSING_INTERVAL = 200;

const string Order::PRIMERO_LABEL = "Primero";
const string Order::PRIMERO = "primero";
const string Order::STANDARD_LABEL = "Standard";
const string Order::STANDARD = "standard";

//Constructor
Order::Order() {}

Order::Order(string data) {
    //using ssstream to parse string into array
    stringstream ss(data);
    string command[COMMAND_LENGTH];
    for (int i = 0; i <= COMMAND_LENGTH; i++) {
        ss >> command[i];
    }
    //store values from given data
    orderTime = stoi(command[INDEX_ORDER_TIME]);
    if (0 == PRIMERO.compare(command[INDEX_CUSTOMER_TYPE])) {
        customer = PRIMERO_IND;
        customerLabel = PRIMERO_LABEL;
    } else {
        customer = STANDARD_IND;
        customerLabel = STANDARD_LABEL;
    }
    orderAmount = stoi(command[INDEX_ORDER_VALUE]);

    //initiate default vales
    orderId = currentOrderId;
    penalty = false;
    setProcessingTime();

    //increment static counter for order id
    currentOrderId++;
}

//destructor
Order::~Order() {}

//overwritten method
int Order::getId() {
    return orderId;
}

void Order::print() {
    cout << "Order " << getId() << " ("
         << getCustomerLabel()
         << ", $" << getOrderAmount() << ")";
}

//getters
int Order::getOrderTime() {
    return orderTime;
}

int Order::getOrderAmount() {
    return orderAmount;
}

int Order::getCustomer() {
    return customer;
}

int Order::getProcessingTime() {
    return processingTime;
}

string Order::getCustomerLabel() {
    return customerLabel;
}

int Order::getStartTime() {
    return startTime;
}

int Order::getFinishTime() {
    return finishTime;
}

int Order::getArrivalTime() {
    return arrivalTime;
}

bool Order::getPenalty() {
    return penalty;
}

double Order::getPenaltyAmount() {
    return penaltyAmount;
}

//setters
void Order::setProcessingTime() {
    processingTime = (getOrderAmount() / PROCESSING_INTERVAL) + 1;
}

void Order::setStartTime(int t) {
    startTime = t;
    setFinishTime(t + getProcessingTime());
}

void Order::setFinishTime(int t) {
    finishTime = t;
}

void Order::setArrivalTime(int t) {
    arrivalTime = t;
}

void Order::setPenalty(bool isPenalty) {
    penalty = isPenalty;
    if (penalty) {
        setPenaltyAmount();
    }
}

void Order::setPenaltyAmount() {
    penaltyAmount = orderAmount * 0.15;
}
//void Order::setOrderId() {}
//
//void Order::setOrderTime() {}
//
//void Order::setOrderAmount() {}
//
//void Order::setOrderStatus() {}
//
//void Order::setCustomer() {}