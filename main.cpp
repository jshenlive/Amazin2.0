//-----------------------------------------
// NAME		: Jesse Shen
// STUDENT NUMBER	: 7909192
// COURSE		: COMP 2150
// INSTRUCTOR	: Olivier Tremblay
// ASSIGNMENT	: assignment 2
//
//
// REMARKS: With a given data set, this program will read it in and creates an event-driven simulation.
//           constantly maintain a priority queue (i.e. an ordered list) of events that need to be processed.
//             each completed event will be printed to the console
//              Arguments required: [filename.txt][numEmployee]
//-----------------------------------------


#include <iostream>
#include "Order.h"
#include "List.h"
#include "Helper.h"
#include <fstream> //necessary to use ifstream (to open a file)

using namespace std;

int main(int argc, char *argv[]) {

    //argument check
    if (argc != 3) {
        cout << "USAGE: FileReadingExample.exe filename numAdditionalEmp" << endl;
        cout << "where numAdditionalEmp is an integer >= 0." << endl;
        return 0;
    }

    string filename = argv[1];
    int numEmployee = stoi(argv[2]);

    //Opening the file, reading one line (just the first one of the file here) and parsing it
    ifstream inputFile;
    inputFile.open(filename);  // opening the file for reading
    string line;

    Order *newOrder;
    List *orderList = new List();
    while (getline(inputFile, line))  //gets the next line from the file and saves it in 'line', if there is one
    {
        //add new order using line from file
        newOrder = new Order(line);
        orderList->addNode(newOrder);
    }

    //run main simulation
    Helper::startSimulation(orderList, numEmployee);

    return 0;
}

