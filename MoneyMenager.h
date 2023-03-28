#ifndef MONEYMENAGER_H
#define MONEYMENAGER_H

#include <iostream>
#include <vector>
#include <algorithm>
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
    void showBalance(vector <int> dates);
    float showIncomes(vector <int> dates);
    float showExpenses(vector <int> dates);

public:
    MoneyMenager(int loggedUserId) : LOGGED_USER_ID(loggedUserId)
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
    void showCustomMonthBalance();
};


#endif // MONEYMENAGER_H

