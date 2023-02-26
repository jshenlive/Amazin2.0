// CLASS: Queue
//
// Author: Jesse Shen, 7909192
//
// REMARKS: Creates a Generic List of Queue
//
//-----------------------------------------
#include "Queue.h"
#include <iostream>

using namespace std;

Queue::Queue() : top(nullptr) { length = 0; }

//destructor
//deletes nodes
Queue::~Queue() {
    Node *curr = top;
    Node *next;
    while (curr != nullptr) {
        next = curr->getNext();
        delete curr;            //node destructor deletes associated items
        curr = next;
    }
}

//add new Node to front
void Queue::addFront(Node *node) {
    node->setNext(top);
    top = node;
}

//add new item to end of list
void Queue::addNode(Company *item) {
    Node *newNode = new Node(item, nullptr);
    if (top == nullptr) {
        top = newNode;
    } else {
        Node *temp = top;
        while (temp->getNext() != nullptr) {
            temp = temp->getNext();
        }
        temp->setNext(newNode);
    }
    length++;
};

//moves the Node from top of
Node *Queue::removeTopNode() {
    Node *removed = top;
    top = top->getNext();
    length--;
    return removed;
}

bool Queue::isEmpty() {
    return (top == nullptr);
}

Node *Queue::getTop() {
    return top;
}

int Queue::getLength() {
    return length;
}

void Queue::setTop(Node *t) {
    top = t;
}

void Queue::incLength() {
    length++;
}

void Queue::print() {
}