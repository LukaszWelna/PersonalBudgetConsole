#include "DateMenager.h"

string DateMenager::getCurrentDate()
{
    char buffer[11];
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
    return convertCharArrayToString(buffer);
}

string DateMenager::convertCharArrayToString(char array[])
{
    if (array[0] == '\0')
        return "";
    else
    return string(array);
}
