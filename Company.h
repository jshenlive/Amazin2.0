// CLASS: Company
//
// Author: Jesse Shen, 7909192
//
// REMARKS: Abstract class for Order, Event, Subclass Events
//
//-----------------------------------------
#pragma once

class Company {
    public:
        //Constructor
        Company();

        //Destructor
        virtual ~Company()=default;

        //Virtual Methods
        virtual void print()=0;
        virtual int getId()=0;
};

