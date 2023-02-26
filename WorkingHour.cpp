// CLASS: WorkingHour
//
// Author: Jesse Shen, 7909192
//
// REMARKS: Collects information on working hour and day
//
//-----------------------------------------
#include "WorkingHour.h"

int currentHour;

//Constructor
WorkingHour::WorkingHour() {
    currentDay = 1;
    currentHour = 1;
}

//Destructor
WorkingHour::~WorkingHour() {}

//Instance method
int WorkingHour::getCurrentHour() {
    return currentHour;
}

int WorkingHour::getCurrentDay() {
    return currentDay;
}

void WorkingHour::addWorkingHour() {
    currentHour++;
}

void WorkingHour::addWorkingDay() {
    currentDay++;
}