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
    // METHODS

public:
    // USER MENAGEMENT
    void userSignUp();
    void userLogin();
    void changeLoggedUserPassword();
    void userLogout();
    bool userLogged();
    void showUsers();

    // MONEY MENAGEMENT
    void addIncome();
    void addExpense();
    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
};

#endif // PERSONALBUDGET_H

