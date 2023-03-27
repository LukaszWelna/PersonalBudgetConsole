#ifndef MONEYMENAGER_H
#define MONEYMENAGER_H

#include <iostream>
#include <vector>
#include "Income.h"
#include "Expense.h"
#include "AuxiliaryMethods.h"
#include "DateMenager.h"
#include "XmlFileWithUserIncomes.h"

using namespace std;

class MoneyMenager
{
    // ATTRIBUTES
    const int LOGGED_USER_ID;
    vector <Income> incomes;
    vector <Expense> expenses;
    XmlFileWithUserIncomes xmlFileWithUserIncomes;

    // METHODS
    Income getNewIncomeData();
    int getDate();
public:
    MoneyMenager(int loggedUserId) : LOGGED_USER_ID(loggedUserId)
    {
        //incomes = xmlFileWithUserIncomes.loadIncomesFromXmlFile();
    }
    void addIncome();
};


#endif // MONEYMENAGER_H

