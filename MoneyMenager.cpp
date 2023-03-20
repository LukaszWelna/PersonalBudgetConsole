#include "MoneyMenager.h"

void MoneyMenager::addIncome()
{
    Income income;
    char choice;
    string date;
    showMenu();
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
    //income = getNewIncomeData();
}

Income MoneyMenager::getNewIncomeData()
{

}

void MoneyMenager::showMenu()
{
    system("cls");
    cout << "1. Current day" << endl;
    cout << "2. Another day" << endl;
}
