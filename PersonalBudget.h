#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include "UserMenager.h"
#include "MoneyMenager.h"

using namespace std;

class PersonalBudget
{
    // ATTRIBUTES
    UserMenager userMenager;
    MoneyMenager *moneyMenager;
    const string FILE_NAME_WITH_USERS;
    const string FILE_NAME_WITH_INCOMES;
    const string FILE_NAME_WITH_EXPENSES;

    // METHODS
public:
    // CONSTRUCTOR
    PersonalBudget(string fileNameWithUsers, string fileNameWithIncomes, string fileNameWithExpenses)
        : userMenager(fileNameWithUsers), FILE_NAME_WITH_INCOMES(fileNameWithIncomes), FILE_NAME_WITH_EXPENSES(fileNameWithExpenses)
    {
        moneyMenager = NULL;
    }

    // DESTRUCTOR
    ~PersonalBudget()
    {
        delete moneyMenager;
        moneyMenager = NULL;
    }

    // USER MENAGEMENT
    void userSignUp();
    void userLogin();
    void changeLoggedUserPassword();
    void userLogout();
    bool userLogged();

    // MONEY MENAGEMENT
    void addIncome();
    void addExpense();
    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
    void showCustomBalance();
};

#endif // PERSONALBUDGET_H

