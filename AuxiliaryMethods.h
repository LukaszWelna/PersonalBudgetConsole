#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class AuxiliaryMethods
{
    // ATTRIBUTES

    // METHODS
public:
    static char readSign();
    static string readLine();
    static float readNumber();
    static string convertIntToString(int);
    static int convertStringToInt(string);
    static string retrieveIntFromString(string, int);
    static string changeFirstLetterToUpperAndOtherToLower(string);
};

#endif // AUXILIARYMETHODS_H
