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
        sort(incomes.begin(), incomes.end());
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
        sort(expenses.begin(), expenses.end());
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

void MoneyMenager::showBalance(vector <int> dates)
{
    float sumOfIncomes = 0, sumOfExpenses = 0;

    system("cls");
    cout << "-----------------------------" << endl;
    cout << ">>> CURRENT MONTH BALANCE <<<" << endl;
    cout << "-----------------------------" << endl;
    sumOfIncomes = showIncomes(dates);
    sumOfExpenses = showExpenses(dates);
    cout << "SUM OF INCOMES: " << sumOfIncomes << endl;
    cout << "-----------------------------" << endl;
    cout << "SUM OF EXPENSES: " << sumOfExpenses << endl;
    cout << "-----------------------------" << endl;
    cout << "FINANCIAL BALANCE: " << sumOfIncomes - sumOfExpenses << endl;
    system("pause");
}

float MoneyMenager::showIncomes(vector <int> dates)
{
    float sum = 0;
    if (!incomes.empty())
    {
        cout << ">>> INCOMES <<<" << endl;
        cout << "-----------------------------" << endl;
        for (int i = 0; i < (int) incomes.size(); i++)
        {
            if ((incomes[i].getDate() >= dates[0]) && (incomes[i].getDate() <= dates[1]))
            {
                cout << "Date: " << incomes[i].getDate() << " | Item: " << incomes[i].getItem() << " | Amount: " << incomes[i].getAmount() << endl;
                sum += incomes[i].getAmount();
            }
        }
        cout << "-----------------------------" << endl;
    }

    else
        cout << "No incomes in current month" << endl;

    return sum;
}

float MoneyMenager::showExpenses(vector <int> dates)
{
    float sum = 0;
    if (!expenses.empty())
    {
        cout << ">>> EXPENSES <<<" << endl;
        cout << "-----------------------------" << endl;
        for (int i = 0; i < (int) expenses.size(); i++)
        {
            if ((expenses[i].getDate() >= dates[0]) && (expenses[i].getDate() <= dates[1]))
            {
                cout << "Date: " << expenses[i].getDate() << " | Item: " << expenses[i].getItem() << " | Amount: " << expenses[i].getAmount() << endl;
                sum += expenses[i].getAmount();;
            }
        }
        cout << "-----------------------------" << endl;
    }

    else
        cout << "No expenses in current month" << endl;

    return sum;
}

void MoneyMenager::showCurrentMonthBalance()
{
    vector <int> dates;
    dates = DateMenager::getCurrentMonthDates();
    showBalance(dates);
}


