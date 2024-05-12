#include "PersonalBudget.h"

// USER MANAGEMENT
void PersonalBudget::userSignUp()
{
    userManager.userSignUp();
}

void PersonalBudget::userLogin()
{
    userManager.userLogin();
    if (userLogged())
    {
        moneyManager = new MoneyManager(userManager.getLoggedUserId(), FILE_NAME_WITH_INCOMES, FILE_NAME_WITH_EXPENSES);
    }
}

void PersonalBudget::userLogout()
{
    userManager.userLogout();
}

bool PersonalBudget::userLogged()
{
    if (userManager.getLoggedUserId() > 0)
        return true;
    else
        return false;
}

void PersonalBudget::changeLoggedUserPassword()
{
    userManager.changeLoggedUserPassword();
}

void PersonalBudget::addIncome()
{
    moneyManager -> addIncome();
}

void PersonalBudget::addExpense()
{
    moneyManager -> addExpense();
}

void PersonalBudget::showCurrentMonthBalance()
{
    moneyManager -> showCurrentMonthBalance();
}

void PersonalBudget::showPreviousMonthBalance()
{
    moneyManager -> showPreviousMonthBalance();
}
void PersonalBudget::showCustomBalance()
{
    moneyManager -> showCustomBalance();
}

