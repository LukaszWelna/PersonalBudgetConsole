#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>
#include <fstream>
#include "Markup.h"

using namespace std;

class XmlFile
{
    // ATTRIBUTES
    const string FILE_NAME;
protected:
    CMarkup xml;

    // METHODS
public:
    //CONSTRUCTOR
    XmlFile(string fileName) : FILE_NAME(fileName)
    {

    }

    // GETTERS
    const string getFileName();
};

#endif // XMLFILE_H

