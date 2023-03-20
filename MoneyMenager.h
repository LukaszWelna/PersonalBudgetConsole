#ifndef MONEYMENAGER_H
#define MONEYMENAGER_H

#include <iostream>
#include <vector>
#include "Income.h"
#include "Expense.h"
#include "AuxiliaryMethods.h"
#include "DateMenager.h"

using namespace std;

class MoneyMenager
{
    // ATTRIBUTES
    int loggedUserId;
    vector <Income> incomes;
    vector <Expense> expenses;

    // METHODS
    Income getNewIncomeData();
    void showMenu();
public:
    void addIncome();

};


#endif // MONEYMENAGER_H

