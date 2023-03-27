#include "XmlFileWithUserIncomes.h"

/*vector <Income> XmlFileWithUserIncomes::loadIncomesFromXmlFile()
{
    CMarkup xml;
    Income income;
    vector <Income> incomes;

    bool loadSuccess = xml.Load("incomes.xml");

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
            income.setDate(xml.GetData());
            xml.FindElem("Item");
            income.setItem(xml.GetData());
            xml.FindElem("Amount");
            income.setSAmount(xml.GetData());
            xml.OutOfElem();
            incomes.push_back(income);
        }
    }
    else
    {
        cout << "Cannot load incomes from database." << endl;
    }
    return incomes;
}
*/
void XmlFileWithUserIncomes::addIncomeToXmlFile(Income income)
{
    CMarkup xml;
    bool loadSuccess = xml.Load("incomes.xml");

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

    xml.Save("incomes.xml");
}


