// CLASS: List
//
// Author: Jesse Shen, 7909192
//
// REMARKS: Creates a Generic List of List
//
//-----------------------------------------
#include "List.h"
#include <iostream>

using namespace std;

List::List() : top(nullptr) { length = 0; }

//destructor
//deletes nodes
List::~List() {
    Node *curr = top;
    Node *next;
    while (curr != nullptr) {
        next = curr->getNext();
        delete curr;            //node destructor deletes associated items
        curr = next;
    }
}

//add new Node to front
void List::addFront(Node *node) {
    node->setNext(top);
    top = node;
}

//add new item to end of list
void List::addNode(Company *item) {
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
Node *List::removeTopNode() {
    Node *removed = top;
    top = top->getNext();
    length--;
    return removed;
}

bool List::isEmpty() {
    return (top == nullptr);
}

Node *List::getTop() {
    return top;
}

int List::getLength() {
    return length;
}

void List::setTop(Node *t) {
    top = t;
}

void List::incLength() {
    length++;
}

void List::print() {
}