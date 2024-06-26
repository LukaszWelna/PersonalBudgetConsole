#include "DateManager.h"

struct tm * DateManager::getCurrentDateStruct()
{
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    return timeinfo;
};

int DateManager::getCurrentDate()
{
    string date = "";
    char buffer[11];
    struct tm *timeinfo;

    timeinfo = getCurrentDateStruct();

    strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
    date = convertCharArrayToString(buffer);

    return convertDateToInt(date);
}

string DateManager::convertCharArrayToString(char array[])
{
    if (array[0] == '\0')
        return "";
    else
    return string(array);
}

int DateManager::convertDateToInt(string date)
{
    date.erase(remove(date.begin(), date.end(), '-'), date.end());
    return AuxiliaryMethods::convertStringToInt(date);
}

int DateManager::getUserDate()
{
    string date = "";
    cout << "Enter date: ";
    date = AuxiliaryMethods::readLine();
    if (checkDateFormat(date))
        return convertDateToInt(date);
    else
        return 0;
}

bool DateManager::checkDateFormat(string date)
{
    // DATE FORMAT PATTERN
    regex pattern("\\d{4}[-]\\d{2}[-]\\d{2}");
    if (regex_match(date, pattern))
    {
        int currentDate = getCurrentDate();
        int userDate = convertDateToInt(date);
        int maxNumberOfDays = 0;
        struct tm userDateStruct = convertStringToTimeStruct(date);
        maxNumberOfDays = calculateDaysInMonth(userDateStruct.tm_year + 1900, userDateStruct.tm_mon + 1);
        if ((userDateStruct.tm_mon >= 0) && (userDateStruct.tm_mon < 12) && (userDateStruct.tm_mday > 0) && (userDateStruct.tm_mday <= maxNumberOfDays)
            && (userDateStruct.tm_year >= 100) && (userDate <= currentDate))
            return true;
        else
            return false;
    }
    else
        return false;
}

struct tm DateManager::convertStringToTimeStruct(string date)
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

string DateManager::convertIntDateToString(int date)
{
    string stringDate = "";
    stringDate = AuxiliaryMethods::convertIntToString(date);
    stringDate.insert(4, "-");
    stringDate.insert(7, "-");

    return stringDate;
}

int DateManager::calculateDaysInMonth(int year, int month)
{
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // CHECKING LEAP YEAR
    if (month == 2 && ((year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0))))
        return daysInMonth[month - 1] + 1;

    else
        return daysInMonth[month - 1];
}

vector <int> DateManager::getCurrentMonthDates()
{
    vector <int> dates;
    string stringDate = "";
    int lastDate = 0;
    char buffer[11];
    struct tm *timeinfo;

    timeinfo = getCurrentDateStruct();

    strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
    stringDate = convertCharArrayToString(buffer);

    // LAST DAY IN CURRENT MONTH
    lastDate = convertDateToInt(stringDate);

    // FIRST DAY IN CURRENT MONTH
    timeinfo -> tm_mday = 1;
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
    stringDate = convertCharArrayToString(buffer);
    dates.push_back(convertDateToInt(stringDate));
    dates.push_back(lastDate);

    return dates;
}

vector <int> DateManager::getLastMonthDates()
{
    vector <int> dates;
    string stringDate = "";
    char buffer[11];
    int maxNumberOfDays = 0;
    struct tm *timeinfo;

    timeinfo = getCurrentDateStruct();

    if (timeinfo -> tm_mon == 0)
    {
        timeinfo -> tm_mon = 11;
        timeinfo -> tm_year --;
    }
    else
    {
        timeinfo -> tm_mon--;
    }

    maxNumberOfDays = calculateDaysInMonth(timeinfo -> tm_year + 1900, timeinfo -> tm_mon + 1);

    timeinfo -> tm_mday = 1;
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
    stringDate = convertCharArrayToString(buffer);
    dates.push_back(convertDateToInt(stringDate));

    timeinfo -> tm_mday = maxNumberOfDays;
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
    stringDate = convertCharArrayToString(buffer);
    dates.push_back(convertDateToInt(stringDate));

    return dates;
}

vector <int> DateManager::getCustomDates()
{
    vector <int> dates;
    string userDate1 = "", userDate2 = "";
    system("cls");
    cout << ">>> GETTING USER DATES <<<" << endl << endl;
    cout << "Enter first (earlier) date in format yyyy-mm-dd: ";
    cin >> userDate1;

    if (checkDateFormat(userDate1))
    {
        dates.push_back(convertDateToInt(userDate1));
        cout << "Enter second (later) date in format yyyy-mm-dd: ";
        cin >> userDate2;

        if (checkDateFormat(userDate2))
        {
            dates.push_back(convertDateToInt(userDate2));
        }

        else
        {
            dates.push_back(0);
            cout << endl << "Wrong format of date" << endl;
            cout << endl;
            system("pause");
        }
    }
    else
    {
        dates.push_back(0);
        dates.push_back(0);
        cout << endl << "Wrong format of date" << endl;
        cout << endl;
        system("pause");

    }
    return dates;
}
