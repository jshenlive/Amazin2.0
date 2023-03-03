// CLASS: name...
//
// Author: Jesse Shen, 7909192
//
// REMARKS: What is the purpose of this class?
//
//-----------------------------------------
#pragma once

#include <string>
#include "Company.h"
using namespace std;

class Order : public Company{
    private:
        static const int COMMAND_LENGTH;
        static const int INDEX_ORDER_TIME;
        static const int INDEX_CUSTOMER_TYPE;
        static const int INDEX_ORDER_VALUE;
        static const string PRIMERO;
        static const string PRIMERO_LABEL;
        static const string STANDARD;
        static const string STANDARD_LABEL;

        static const int PROCESSING_INTERVAL;

        int static currentOrderId;
        int orderTime;
        int orderId;

        int orderAmount;
        int processingTime;
        int customer;

        string customerLabel;
        int arrivalTime;
        int startTime;
        int finishTime;

        bool penalty;
        double penaltyAmount;

    public:
        static const int PRIMERO_IND;
        static const int STANDARD_IND;
        //constructors
        Order();
        Order(string);

        //destructer
        ~Order();

        //Override methods
        virtual int getId() override;
        virtual void print() override;

        //getters
        int getOrderTime();
        int getOrderAmount();
        int getProcessingTime();
        int getCustomer();
        int getFinishTime();
        int getStartTime();
        int getArrivalTime();
        bool getPenalty();
        double getPenaltyAmount();
        string getCustomerLabel();

        //setters
        void setProcessingTime();
        void setFinishTime(int);
        void setStartTime(int);
        void setArrivalTime(int);
        void setPenalty(bool);
        void setPenaltyAmount();
    //    void setOrderId();
    //    void setOrderTime();
    //    void setOrderAmount();
    //    void setOrderStatus();
    //    void setCustomer();
};

