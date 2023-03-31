#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <stdexcept>

using namespace std;

class AuxiliaryMethods
{
    // ATTRIBUTES

    // METHODS
public:
    static char readSign();
    static string readLine();
    static float readNumber();
    static string convertIntToString(int number);
    static string convertDoubleToString(double number);
    static int convertStringToInt(string stringNumber);
    static string retrieveIntFromString(string text, int startPosition);
    static string changeFirstLetterToUpperAndOtherToLower(string text);
    static double convertStringToDouble(string stringNumber);
};

#endif // AUXILIARYMETHODS_H
