// CLASS: Revenue
//
// Author: Jesse Shen, 7909192
//
// REMARKS: Collects all money related information, costs, profits, revenue, wages
//
//-----------------------------------------
#pragma once

class Revenue {
private:
    //static class variables
    static const double WAGE_PER_HOUR;
    static const int WORKING_HOUR_PER_DAY;
    static const int BONUS;
    static const double PROFIT_MARGIN;

    static double wagePerDay;
    static double totalWage;
    static double totalPenalty;
    static double totalProfit;
    static double revenue;
    static double profit;

public:
    //constructor
    Revenue();

    ~Revenue();

    //mutators
    static void addTotalPenalty(double);

    static void addRevenue(double);

    static void setTotalWage(int, int);

    static void setTotalProfit();

    static void setWage(double);

    //setters

    static double getTotalProfit();

    static double getTotalWage();

    static double getProfit();

    static double getWage();

    static double getTotalPenalty();

    static double getRevenue();
};

