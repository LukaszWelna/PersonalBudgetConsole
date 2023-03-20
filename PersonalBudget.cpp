#include "PersonalBudget.h"

// USER MENAGEMENT
void PersonalBudget::userSignUp()
{
    userMenager.userSignUp();
}

void PersonalBudget::userLogin()
{
    userMenager.userLogin();
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

void PersonalBudget::showUsers()
{
    userMenager.showUsers();
}

void PersonalBudget::changeLoggedUserPassword()
{
    userMenager.changeLoggedUserPassword();
}

void PersonalBudget::addIncome()
{
    moneyMenager.addIncome();
}
