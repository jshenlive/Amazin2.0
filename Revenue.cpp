// CLASS: Revenue
//
// Author: Jesse Shen, 7909192
//
// REMARKS: Collects all money related information, costs, profits, revenue, wages
//
//-----------------------------------------
#include "Revenue.h"

const double Revenue::WAGE_PER_HOUR = 13.5;
const int Revenue::WORKING_HOUR_PER_DAY = 8;
const int Revenue::BONUS = 1;
const double Revenue::PROFIT_MARGIN = 0.5;

double Revenue::wagePerDay = WORKING_HOUR_PER_DAY * WAGE_PER_HOUR + BONUS;
double Revenue::totalWage = 0;
double Revenue::totalPenalty = 0;
double Revenue::totalProfit = 0;
double Revenue::revenue = 0;
double Revenue::profit = 0;

Revenue::Revenue() {}

void Revenue::setTotalWage(int numEmployee, int numDay) {
    Revenue::totalWage = wagePerDay * numEmployee * numDay;
    setTotalProfit();
}

void Revenue::setTotalProfit() {
    totalProfit = revenue * PROFIT_MARGIN - totalPenalty - totalWage;
}

void Revenue::addTotalPenalty(double p) {
    totalPenalty += p;
}

void Revenue::addRevenue(double r) {
    revenue += r;
    profit += r * PROFIT_MARGIN;
}

double Revenue::getTotalWage() {
    return totalWage;
}

double Revenue::getWage() {
    return wagePerDay;
}

double Revenue::getTotalPenalty() {
    return totalPenalty;
}

double Revenue::getRevenue() {
    return revenue;
}

double Revenue::getProfit() {
    return profit - totalPenalty;
}

double Revenue::getTotalProfit() {
    return totalProfit;
}