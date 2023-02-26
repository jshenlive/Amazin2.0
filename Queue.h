// CLASS: Queue
//
// Author: Jesse Shen, 7909192
//
// REMARKS: Creates a Generic List of Queue
//
//-----------------------------------------
#pragma once

//#include "Company.h"
#include "Node.h"

//class Node;

class Queue {
protected:
    Node *top;
    Node *next;
    int length;
public:
    Queue();

    ~Queue();

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

