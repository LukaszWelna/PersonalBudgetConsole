#include "XmlFileWithUserExpenses.h"

int XmlFileWithUserExpenses::getLastExpenseId()
{
    return lastExpenseId;
}

void XmlFileWithUserExpenses::setLastExpenseId(int lastExpenseId)
{
    this -> lastExpenseId = lastExpenseId;
}

vector <Expense> XmlFileWithUserExpenses::loadExpensesFromXmlFile(int loggedUserId)
{
    CMarkup xml;
    Expense expense;
    vector <Expense> expenses;
    lastExpenseId = 0;

    bool loadSuccess = xml.Load(getFileName());

    if (loadSuccess)
    {
        xml.FindElem();
        xml.IntoElem();
        // LOADING ALL EXPENSES
        while(xml.FindElem("Expense"))
        {
            xml.IntoElem();
            xml.FindElem("Id");
            expense.setId(AuxiliaryMethods::convertStringToInt(xml.GetData()));
            xml.FindElem("UserId");
            expense.setUserId(AuxiliaryMethods::convertStringToInt(xml.GetData()));
            xml.FindElem("Date");
            expense.setDate(AuxiliaryMethods::convertStringToInt(xml.GetData()));
            xml.FindElem("Item");
            expense.setItem(xml.GetData());
            xml.FindElem("Amount");
            expense.setAmount(AuxiliaryMethods::convertStringToInt(xml.GetData()));
            xml.OutOfElem();
            if (expense.getUserId() == loggedUserId)
                    expenses.push_back(expense);
        }
        lastExpenseId = expense.getId();
    }
    else
    {
        lastExpenseId = 0;
    }

    return expenses;
}

bool XmlFileWithUserExpenses::addExpenseToXmlFile(Expense expense)
{
    CMarkup xml;
    bool loadSuccess = xml.Load(getFileName());

    if (!loadSuccess)
    {
        xml.AddElem("Expenses");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("Id", expense.getId());
    xml.AddElem("UserId", expense.getUserId());
    xml.AddElem("Date", expense.getDate());
    xml.AddElem("Item", expense.getItem());
    xml.AddElem("Amount", expense.getAmount());

    if (xml.Save(getFileName()))
    {
        lastExpenseId++;
        return true;
    }

    return false;
}

