#ifndef XMLFILEWITHUSEREXPENSES_H
#define XMLFILEWITHUSEREXPENSES_H

#include <iostream>
#include <vector>
#include "Markup.h"
#include "Expense.h"
#include "AuxiliaryMethods.h"

using namespace std;

class XmlFileWithUserExpenses
{
    // ATTRIBUTES
    int lastExpenseId;
    // METHODS
public:
    int getLastExpenseId();
    void setLastExpenseId(int lastExpenseId);
    vector <Expense> loadExpensesFromXmlFile(int loggedUserId);
    void addExpenseToXmlFile(Expense expense);
};

#endif // XMLFILEWITHUSEREXPENSES_H

