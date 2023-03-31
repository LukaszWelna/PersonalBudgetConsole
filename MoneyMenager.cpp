#include "MoneyMenager.h"

void MoneyMenager::addIncome()
{
    Income income;

    system("cls");
    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;

    income = getNewIncomeData();

    if (income.getDate() != 0)
    {
        if (xmlFileWithUserIncomes.addIncomeToXmlFile(income))
        {
            incomes.push_back(income);
            cout << endl << "Income added." << endl;
            sort(incomes.begin(), incomes.end());
        }
        else
            cout << endl << "Adding income failed." << endl;

    }
    else
        cout << endl << "Adding income failed." << endl;

    cout << endl;
    system("pause");
}

Income MoneyMenager::getNewIncomeData()
{
    string line = "";
    Income income;
    income.setUserId(LOGGED_USER_ID);
    income.setDate(getDate());

    if (income.getDate())
    {
        double amount = 0;
        system("cls");
        cout << ">>> ADDING NEW INCOME <<<" << endl << endl;

        income.setId(xmlFileWithUserIncomes.getLastIncomeId() + 1);
        cout << "Enter source of income: ";
        income.setItem(AuxiliaryMethods::readLine());
        do
        {
            cout << "Enter amount of income: ";
            amount = AuxiliaryMethods::convertStringToDouble(AuxiliaryMethods::readLine());
        }
        while(amount < 0);

        income.setAmount(amount);
    }
    else
        cout << endl << "Wrong date format." << endl;

    return income;
}

int MoneyMenager::getDate()
{
    char choice;
    int date = 0;

    cout << "1. Current day" << endl;
    cout << "2. Another day" << endl;

    choice = AuxiliaryMethods::readSign();

    switch (choice)
    {
    case '1':
        date = DateMenager::getCurrentDate();
        break;
    case '2':
        system("cls");
        cout << ">>> GETTING USER DATE <<<" << endl << endl;
        date = DateMenager::getUserDate();
        break;
    default:
        system("cls");
        cout << "No option in menu." << endl;
    }
    return date;
}

void MoneyMenager::addExpense()
{
    Expense expense;

    system("cls");
    cout << ">>> ADDING NEW EXPENSE <<<" << endl << endl;

    expense = getNewExpenseData();

    if (expense.getDate() != 0)
    {
        if (xmlFileWithUserExpenses.addExpenseToXmlFile(expense))
        {
            expenses.push_back(expense);
            cout << endl << "Expense added." << endl;
            sort(expenses.begin(), expenses.end());
        }
        else
            cout << endl << "Adding expense failed." << endl;

    }
    else
        cout << endl << "Adding expense failed." << endl;

    cout << endl;
    system("pause");
}

Expense MoneyMenager::getNewExpenseData()
{
    Expense expense;
    expense.setUserId(LOGGED_USER_ID);
    expense.setDate(getDate());

    if (expense.getDate())
    {
        double amount = 0;
        system("cls");
        cout << " >>> ADDING NEW EXPENSE <<<" << endl << endl;

        expense.setId(xmlFileWithUserExpenses.getLastExpenseId() + 1);
        cout << "Enter source of expense: ";
        expense.setItem(AuxiliaryMethods::readLine());
        do
        {
            cout << "Enter amount of expense: ";
            amount = AuxiliaryMethods::convertStringToDouble(AuxiliaryMethods::readLine());
        }
        while(amount < 0);

        expense.setAmount(amount);
    }
    else
        cout << endl << "Wrong date format." << endl;

    return expense;
}

void MoneyMenager::showBalance(vector <int> dates)
{
    double sumOfIncomes = 0, sumOfExpenses = 0;

    sumOfIncomes = showIncomes(dates);
    sumOfExpenses = showExpenses(dates);
    cout << "SUM OF INCOMES: " << sumOfIncomes << endl;
    cout << "-----------------------------" << endl;
    cout << "SUM OF EXPENSES: " << sumOfExpenses << endl;
    cout << "-----------------------------" << endl;
    cout << "FINANCIAL BALANCE: " << sumOfIncomes - sumOfExpenses << endl;
    cout << endl;
    system("pause");
}

double MoneyMenager::showIncomes(vector <int> dates)
{
    bool incomesNotShowed = true;
    double sum = 0;
    if (!incomes.empty())
    {
        cout << ">>> INCOMES <<<" << endl;
        cout << "-----------------------------" << endl;
        for (int i = 0; i < (int) incomes.size(); i++)
        {
            if ((incomes[i].getDate() >= dates[0]) && (incomes[i].getDate() <= dates[1]))
            {
                cout << "Date: " << DateMenager::convertIntDateToString(incomes[i].getDate()) << " | Item: " << incomes[i].getItem() << " | Amount: " << incomes[i].getAmount() << endl;
                sum += incomes[i].getAmount();
                cout << incomes[i].getAmount() << endl;
                incomesNotShowed = false;
            }
        }
    }

    if(incomesNotShowed)
        cout << "No incomes to show." << endl;

    cout << "-----------------------------" << endl;

    return sum;
}

double MoneyMenager::showExpenses(vector <int> dates)
{
    bool expensesNotShowed = true;
    double sum = 0;
    if (!expenses.empty())
    {
        cout << ">>> EXPENSES <<<" << endl;
        cout << "-----------------------------" << endl;
        for (int i = 0; i < (int) expenses.size(); i++)
        {
            if ((expenses[i].getDate() >= dates[0]) && (expenses[i].getDate() <= dates[1]))
            {
                cout << "Date: " << DateMenager::convertIntDateToString(expenses[i].getDate()) << " | Item: " << expenses[i].getItem() << " | Amount: " << expenses[i].getAmount() << endl;
                sum += expenses[i].getAmount();
                expensesNotShowed = false;
            }
        }
    }

    if (expensesNotShowed)
        cout << "No expenses to show." << endl;

    cout << "-----------------------------" << endl;

    return sum;
}

void MoneyMenager::showCurrentMonthBalance()
{
    vector <int> dates;
    dates = DateMenager::getCurrentMonthDates();
    system("cls");
    cout << "-----------------------------" << endl;
    cout << ">>> CURRENT MONTH BALANCE <<<" << endl;
    cout << "-----------------------------" << endl;
    showBalance(dates);
}

void MoneyMenager::showPreviousMonthBalance()
{
    vector <int> dates;
    dates = DateMenager::getLastMonthDates();
    system("cls");
    cout << "-----------------------------" << endl;
    cout << ">>> PREVIOUS MONTH BALANCE <<<" << endl;
    cout << "-----------------------------" << endl;
    showBalance(dates);
}

void MoneyMenager::showCustomBalance()
{
    vector <int> dates;
    dates = DateMenager::getCustomDates();
    if (!((dates[0] == 0) || (dates[1] == 0)) && dates[0] <= dates[1])
    {
        system("cls");
        cout << "-----------------------------" << endl;
        cout << ">>> CUSTOM MONTH BALANCE <<<" << endl;
        cout << "-----------------------------" << endl;
        showBalance(dates);
    }
}


