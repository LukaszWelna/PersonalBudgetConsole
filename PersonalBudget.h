#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include "UserManager.h"
#include "MoneyManager.h"

using namespace std;

class PersonalBudget
{
    // ATTRIBUTES
    UserManager userManager;
    MoneyManager *moneyManager;
    const string FILE_NAME_WITH_USERS;
    const string FILE_NAME_WITH_INCOMES;
    const string FILE_NAME_WITH_EXPENSES;

    // METHODS
public:
    // CONSTRUCTOR
    PersonalBudget(string fileNameWithUsers, string fileNameWithIncomes, string fileNameWithExpenses)
        : userManager(fileNameWithUsers), FILE_NAME_WITH_INCOMES(fileNameWithIncomes), FILE_NAME_WITH_EXPENSES(fileNameWithExpenses)
    {
        moneyManager = NULL;
    }

    // DESTRUCTOR
    ~PersonalBudget()
    {
        delete moneyManager;
        moneyManager = NULL;
    }

    // USER MANAGEMENT
    void userSignUp();
    void userLogin();
    void changeLoggedUserPassword();
    void userLogout();
    bool userLogged();

    // MONEY MANAGEMENT
    void addIncome();
    void addExpense();
    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
    void showCustomBalance();
};

#endif // PERSONALBUDGET_H

