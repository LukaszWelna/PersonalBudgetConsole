#ifndef XMLFILEWITHUSEREXPENSES_H
#define XMLFILEWITHUSEREXPENSES_H

#include <iostream>
#include <vector>
#include "Expense.h"
#include "AuxiliaryMethods.h"
#include "XmlFile.h"

using namespace std;

class XmlFileWithUserExpenses : public XmlFile
{
    // ATTRIBUTES
    int lastExpenseId;
    // METHODS
public:
    //CONSTRUCTOR
    XmlFileWithUserExpenses(string fileNameWithUsers) : XmlFile(fileNameWithUsers)
    {

    }
    int getLastExpenseId();
    void setLastExpenseId(int lastExpenseId);
    vector <Expense> loadExpensesFromXmlFile(int loggedUserId);
    bool addExpenseToXmlFile(Expense expense);
};

#endif // XMLFILEWITHUSEREXPENSES_H

