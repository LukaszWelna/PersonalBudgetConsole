#ifndef DATEMENAGER_H
#define DATEMENAGER_H

#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

class DateMenager
{
    // METHODS
    static string convertCharArrayToString(char array[]);
    int calculateDaysInMonth();
    struct tm convertStringToTimeStruct();
public:
    static string getCurrentDate();
    static bool checkDateFormat();
    static vector <string> calculateLastMonthDates();
    static bool compareDates();
};

#endif // DATEMENAGER_H

