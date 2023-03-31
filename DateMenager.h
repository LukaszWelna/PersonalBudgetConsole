#ifndef DATEMENAGER_H
#define DATEMENAGER_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
#include <regex>
#include "AuxiliaryMethods.h"

using namespace std;

class DateMenager
{
    // ATTRIBUTES

    // METHODS
    static string convertCharArrayToString(char array[]);
    static int calculateDaysInMonth(int year, int month);
    static struct tm convertStringToTimeStruct(string date);
    static int convertDateToInt(string date);
    static bool checkDateFormat(string date);
    static struct tm * getCurrentDateStruct();
public:
    static string convertIntDateToString(int date);
    static int getCurrentDate();
    static int getUserDate();
    static bool compareDates();
    static vector <int> getCurrentMonthDates();
    static vector <int> getLastMonthDates();
    static vector <int> getCustomDates();
};

#endif // DATEMENAGER_H

