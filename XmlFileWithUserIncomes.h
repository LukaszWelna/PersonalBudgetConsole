#ifndef XMLFILEWITHUSERINCOMES_H
#define XMLFILEWITHUSERINCOMES_H

#include <iostream>
#include <vector>
#include "Markup.h"
#include "Income.h"
#include "AuxiliaryMethods.h"
#include "XmlFile.h"

using namespace std;

class XmlFileWithUserIncomes : public XmlFile
{
    // ATTRIBUTES
    int lastIncomeId;

    // METHODS
public:
    //CONSTRUCTOR
    XmlFileWithUserIncomes(string fileNameWithUsers) : XmlFile(fileNameWithUsers)
    {

    }
    int getLastIncomeId();
    void setLastIncomeId(int lastIncomeId);
    vector <Income> loadIncomesFromXmlFile(int loggedUserId);
    bool addIncomeToXmlFile(Income income);
};

#endif // XMLFILEWITHUSERINCOMES_H

