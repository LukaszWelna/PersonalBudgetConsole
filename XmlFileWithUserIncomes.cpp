#include "XmlFileWithUserIncomes.h"

int XmlFileWithUserIncomes::getLastIncomeId()
{
    return lastIncomeId;
}

void XmlFileWithUserIncomes::setLastIncomeId(int lastIncomeId)
{
    this -> lastIncomeId = lastIncomeId;
}

vector <Income> XmlFileWithUserIncomes::loadIncomesFromXmlFile(int loggedUserId)
{
    CMarkup xml;
    Income income;
    vector <Income> incomes;
    lastIncomeId = 0;

    bool loadSuccess = xml.Load(getFileName());

    if (loadSuccess)
    {
        xml.FindElem();
        xml.IntoElem();
        // LOADING ALL INCOMES
        while(xml.FindElem("Income"))
        {
            xml.IntoElem();
            xml.FindElem("Id");
            income.setId(AuxiliaryMethods::convertStringToInt(xml.GetData()));
            xml.FindElem("UserId");
            income.setUserId(AuxiliaryMethods::convertStringToInt(xml.GetData()));
            xml.FindElem("Date");
            income.setDate(AuxiliaryMethods::convertStringToInt(xml.GetData()));
            xml.FindElem("Item");
            income.setItem(xml.GetData());
            xml.FindElem("Amount");
            income.setAmount(AuxiliaryMethods::convertStringToInt(xml.GetData()));
            xml.OutOfElem();
            if (income.getUserId() == loggedUserId)
                    incomes.push_back(income);
        }
        lastIncomeId = income.getId();
    }
    else
    {
        lastIncomeId = 0;
    }
    return incomes;
}

bool XmlFileWithUserIncomes::addIncomeToXmlFile(Income income)
{
    CMarkup xml;
    bool loadSuccess = xml.Load(getFileName());

    if (!loadSuccess)
    {
        xml.AddElem("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("Id", income.getId());
    xml.AddElem("UserId", income.getUserId());
    xml.AddElem("Date", income.getDate());
    xml.AddElem("Item", income.getItem());
    xml.AddElem("Amount", income.getAmount());

    if(xml.Save(getFileName()))
    {
        lastIncomeId++;
        return true;
    }

    return false;
}


