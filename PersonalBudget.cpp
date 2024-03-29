#include "PersonalBudget.h"

// USER MENAGEMENT
void PersonalBudget::userSignUp()
{
    userMenager.userSignUp();
}

void PersonalBudget::userLogin()
{
    userMenager.userLogin();
    if (userLogged())
    {
        moneyMenager = new MoneyMenager(userMenager.getLoggedUserId(), FILE_NAME_WITH_INCOMES, FILE_NAME_WITH_EXPENSES);
    }
}

void PersonalBudget::userLogout()
{
    userMenager.userLogout();
}

bool PersonalBudget::userLogged()
{
    if (userMenager.getLoggedUserId() > 0)
        return true;
    else
        return false;
}

void PersonalBudget::changeLoggedUserPassword()
{
    userMenager.changeLoggedUserPassword();
}

void PersonalBudget::addIncome()
{
    moneyMenager -> addIncome();
}

void PersonalBudget::addExpense()
{
    moneyMenager -> addExpense();
}

void PersonalBudget::showCurrentMonthBalance()
{
    moneyMenager -> showCurrentMonthBalance();
}

void PersonalBudget::showPreviousMonthBalance()
{
    moneyMenager -> showPreviousMonthBalance();
}
void PersonalBudget::showCustomBalance()
{
    moneyMenager -> showCustomBalance();
}

