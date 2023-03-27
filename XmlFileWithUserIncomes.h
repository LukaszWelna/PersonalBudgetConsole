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

    // METHODS
public:
    vector <Income> loadIncomesFromXmlFile();
    void addIncomeToXmlFile(Income income);
};

#endif // XMLFILEWITHUSERINCOMES_H

