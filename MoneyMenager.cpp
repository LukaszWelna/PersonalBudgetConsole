#include "MoneyMenager.h"

void MoneyMenager::addIncome()
{
    Income income;

    income = getNewIncomeData();

    if (income.date != 0)
    {

    }
    {
        cout << "Adding income failed." << endl;
    }
}

Income MoneyMenager::getNewIncomeData()
{
    Income income;
    income.setDate(getDate());

    cout << "Enter source of income: ";
    income.setItem(AuxiliaryMethods::readLine());
    cout << "Enter amount of income: ";
}

int MoneyMenager::getDate()
{
    char choice;
    int date = 0;
    system("cls");
    cout << "1. Current day" << endl;
    cout << "2. Another day" << endl;

    choice = AuxiliaryMethods::readSign();

    switch (choice)
    {
    case '1':
        date = DateMenager::getCurrentDate();
        break;
    case '2':
        break;
    default:
        cout << "No option in menu." << endl;
    }

    return date;
}
