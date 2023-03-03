// CLASS: Node
//
// Author: Jesse Shen, 7909192
//
// REMARKS: Node for creating a linked list
//
//-----------------------------------------
#pragma once
#include "Event.h"
#include "Company.h"


class Node {
    private:
        Company* item;
        Node* next;

    public:
        //Constructor
        Node(Company*, Node*);

        //Destructor
        ~Node();

        //Mutator
        void setNext(Node*);

        //Getters
        Node* getNext();
        Event* getEvent();
        Company* getItem();
};
