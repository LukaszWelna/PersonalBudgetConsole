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
