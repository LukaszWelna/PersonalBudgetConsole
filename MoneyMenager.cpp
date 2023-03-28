#include "MoneyMenager.h"

void MoneyMenager::addIncome()
{
    Income income;

    system("cls");
    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;

    income = getNewIncomeData();

    if (income.getDate() != 0)
    {
        incomes.push_back(income);
        xmlFileWithUserIncomes.addIncomeToXmlFile(income);
        cout << "Income added." << endl;
        system("pause");
    }
    else
    {
        cout << "Adding income failed." << endl;
        system("pause");
    }
}

Income MoneyMenager::getNewIncomeData()
{
    Income income;
    income.setUserId(LOGGED_USER_ID);
    income.setDate(getDate());

    if (income.getDate())
    {
        income.setId(xmlFileWithUserIncomes.getLastIncomeId() + 1);
        cout << "Enter source of income: ";
        income.setItem(AuxiliaryMethods::readLine());
        cout << "Enter amount of income: ";
        income.setAmount(AuxiliaryMethods::readNumber());
    }
    else
        cout << "Wrong date format." << endl;

    return income;
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
        date = DateMenager::getUserDate();
        break;
    default:
        cout << "No option in menu." << endl;
    }
    return date;
}

void MoneyMenager::addExpense()
{
    Expense expense;

    system("cls");
    cout << " >>> ADDING NEW EXPENSE <<<" << endl << endl;

    expense = getNewExpenseData();

    if (expense.getDate() != 0)
    {
        expenses.push_back(expense);
        xmlFileWithUserExpenses.addExpenseToXmlFile(expense);
        cout << "Expense added." << endl;
        system("pause");
    }
    else
    {
        cout << "Adding expense failed." << endl;
        system("pause");
    }
}

Expense MoneyMenager::getNewExpenseData()
{
    Expense expense;
    expense.setUserId(LOGGED_USER_ID);
    expense.setDate(getDate());

    if (expense.getDate())
    {
        expense.setId(xmlFileWithUserExpenses.getLastExpenseId() + 1);
        cout << "Enter source of expense: ";
        expense.setItem(AuxiliaryMethods::readLine());
        cout << "Enter amount of expense: ";
        expense.setAmount(AuxiliaryMethods::readNumber());
    }
    else
        cout << "Wrong date format." << endl;

    return expense;
}
