// CLASS: WorkingHour
//
// Author: Jesse Shen, 7909192
//
// REMARKS: Collects information on working hour and day
//
//-----------------------------------------
#pragma once

class WorkingHour {
    private:
        int currentDay;
        int currentHour;
    public:

        //Constructor
        WorkingHour();

        //Destructor
        ~WorkingHour();

        //Getters
        int getCurrentHour();

        int getCurrentDay();

        //Mutators
        void addWorkingHour();

        void addWorkingDay();
};

