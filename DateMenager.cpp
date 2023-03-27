#include "DateMenager.h"

int DateMenager::getCurrentDate()
{
    string date = "";
    char buffer[11];
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
    date = convertCharArrayToString(buffer);

    return convertDateToInt(date);
}

string DateMenager::convertCharArrayToString(char array[])
{
    if (array[0] == '\0')
        return "";
    else
    return string(array);
}

int DateMenager::convertDateToInt(string date)
{
    date.erase(remove(date.begin(), date.end(), '-'), date.end());
    return AuxiliaryMethods::convertStringToInt(date);
}

int DateMenager::getUserDate()
{
    string date = "";
    cout << "Enter date: ";
    date = AuxiliaryMethods::readLine();
    if (checkDateFormat(date))
        return convertDateToInt(date);
    else
        return 0;
}

bool DateMenager::checkDateFormat(string date)
{
    // DATE FORMAT PATTERN
    regex pattern("\\d{4}[-]\\d{2}[-]\\d{2}");
    if (regex_match(date, pattern))
    {
        int maxNumberOfDays = 0;
        struct tm userDateStruct = convertStringToTimeStruct(date);
        maxNumberOfDays = calculateDaysInMonth(userDateStruct.tm_year + 1900, userDateStruct.tm_mon + 1);
        if ((userDateStruct.tm_mon >= 0) && (userDateStruct.tm_mon < 12) && (userDateStruct.tm_mday > 0) && (userDateStruct.tm_mday <= maxNumberOfDays))
            return true;
        else
            return false;
    }
    else
        return false;
}

struct tm DateMenager::convertStringToTimeStruct(string date)
{
    struct tm timeinfo;
    int year = 0, month = 0, day = 0;
    if (sscanf(date.c_str(), "%d - %d - %d,", &year, &month, &day) > 0)
    {
        timeinfo.tm_sec = 0;
        timeinfo.tm_min = 0;
        timeinfo.tm_hour = 0;
        timeinfo.tm_mday = day;
        timeinfo.tm_mon = month - 1;
        timeinfo.tm_year = year - 1900;
        timeinfo.tm_isdst = -1;
    }

    return timeinfo;
}

int DateMenager::calculateDaysInMonth(int year, int month)
{
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // CHECKING LEAP YEAR
    if (month == 2 && ((year%400 == 0) || ((year%100 != 0) && (year % 4 == 0))))
        return daysInMonth[month - 1] + 1;

    else
        return daysInMonth[month - 1];
}
