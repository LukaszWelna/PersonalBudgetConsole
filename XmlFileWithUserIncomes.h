#ifndef XMLFILEWITHUSERINCOMES_H
#define XMLFILEWITHUSERINCOMES_H

#include <iostream>
#include <vector>
#include "Markup.h"
#include "Income.h"
#include "AuxiliaryMethods.h"

using namespace std;

class XmlFileWithUserIncomes
{
    // ATTRIBUTES
    int lastIncomeId;
    // METHODS
public:
    int getLastIncomeId();
    void setLastIncomeId(int lastIncomeId);
    vector <Income> loadIncomesFromXmlFile(int loggedUserId);
    void addIncomeToXmlFile(Income income);
};

#endif // XMLFILEWITHUSERINCOMES_H

