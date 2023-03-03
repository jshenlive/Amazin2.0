// CLASS: List
//
// Author: Jesse Shen, 7909192
//
// REMARKS: Creates a Generic List of List
//
//-----------------------------------------
#pragma once

#include "Node.h"

class List {
    protected:
        Node *top;
        Node *next;
        int length;

    public:
        List();

        ~List();

        void print();

        void addNode(Company *);

        void addFront(Node *);

        Node *removeTopNode();

        bool isEmpty();

        Node *getTop();

        int getLength();

        void setTop(Node *);

        void incLength();
};

