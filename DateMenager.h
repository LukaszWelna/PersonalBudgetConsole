#ifndef DATEMENAGER_H
#define DATEMENAGER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include "AuxiliaryMethods.h"

using namespace std;

class DateMenager
{
    // METHODS
    static string convertCharArrayToString(char array[]);
    static int calculateDaysInMonth();
    static struct tm convertStringToTimeStruct();
    static int convertDateToInt(string date);
public:
    static int getCurrentDate();
    static bool checkDateFormat();
    static vector <string> calculateLastMonthDates();
    static bool compareDates();
};

#endif // DATEMENAGER_H

