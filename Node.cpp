// CLASS: Node
//
// Author: Jesse Shen, 7909192
//
// REMARKS: Node for creating a linked list
//
//-----------------------------------------

#include "Node.h"

Node::Node(Company* i, Node* n): item(i), next(n){}

//deletes associated item
Node::~Node() {
    delete item;
}

void Node::setNext(Node* n) {
    next = n;
}

Node* Node::getNext() {
    return next;
}

Company* Node::getItem() {
    return item;
}

Event* Node::getEvent() {
    return dynamic_cast<Event*>(item);
}