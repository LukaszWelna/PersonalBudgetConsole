#ifndef MONEYMANAGER_H
#define MONEYMANAGER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "Income.h"
#include "Expense.h"
#include "AuxiliaryMethods.h"
#include "DateManager.h"
#include "XmlFileWithUserIncomes.h"
#include "XmlFileWithUserExpenses.h"

using namespace std;

class MoneyManager
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
    void showBalance(vector <int> dates);
    double showIncomes(vector <int> dates);
    double showExpenses(vector <int> dates);

public:
    // CONSTRUCTOR
    MoneyManager(int loggedUserId, string fileNameWithIncomes, string fileNameWithExpenses)
        : LOGGED_USER_ID(loggedUserId), xmlFileWithUserIncomes(fileNameWithIncomes), xmlFileWithUserExpenses(fileNameWithExpenses)
    {
        incomes = xmlFileWithUserIncomes.loadIncomesFromXmlFile(LOGGED_USER_ID);
        expenses = xmlFileWithUserExpenses.loadExpensesFromXmlFile(LOGGED_USER_ID);
        sort(incomes.begin(), incomes.end());
        sort(expenses.begin(), expenses.end());
    }

    void addIncome();
    void addExpense();
    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
    void showCustomBalance();
};


#endif // MONEYMANAGER_H

