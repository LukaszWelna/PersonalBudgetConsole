#ifndef MONEYMENAGER_H
#define MONEYMENAGER_H

#include <iostream>
#include <vector>
#include "Income.h"
#include "Expense.h"
#include "AuxiliaryMethods.h"
#include "DateMenager.h"
#include "XmlFileWithUserIncomes.h"
#include "XmlFileWithUserExpenses.h"

using namespace std;

class MoneyMenager
{
    // ATTRIBUTES
    const int LOGGED_USER_ID;
    vector <Income> incomes;
    vector <Expense> expenses;
    XmlFileWithUserIncomes xmlFileWithUserIncomes;
    XmlFileWithUserExpenses xmlFileWithUserExpenses;

    // METHODS
    Income getNewIncomeData();
    Expense getNewExpenseData();
    int getDate();
public:
    MoneyMenager(int loggedUserId) : LOGGED_USER_ID(loggedUserId)
    {
        incomes = xmlFileWithUserIncomes.loadIncomesFromXmlFile(LOGGED_USER_ID);
        expenses = xmlFileWithUserExpenses.loadExpensesFromXmlFile(LOGGED_USER_ID);
    }
    void addIncome();
    void addExpense();
};


#endif // MONEYMENAGER_H

