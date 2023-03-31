#include "AuxiliaryMethods.h"

char AuxiliaryMethods::readSign()
{
    string input = "";
    char sign  = {0};

    while (true)
    {
        cin.sync();
        getline(cin, input);

        if (input.length() == 1)
        {
            sign = input[0];
            break;
        }
        cout << "It is not a sign. Try again." << endl;
    }
    return sign;
}

string AuxiliaryMethods::readLine()
{
    string input = "";
    getline(cin, input);
    return input;
}

float AuxiliaryMethods::readNumber()
{
    float number = 0;
    while (!(cin >> number))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "It is not a number. Try again." << endl;
    }

    return number;
}

string AuxiliaryMethods::convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods::convertDoubleToString(double number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int AuxiliaryMethods::convertStringToInt(string stringNumber)
{
    int number;
    istringstream iss(stringNumber);
    iss >> number;

    return number;
}

string AuxiliaryMethods::retrieveIntFromString(string text, int startPosition)
{
    string number = "";
    while(isdigit(text[startPosition]))
    {
        number += text[startPosition];
        startPosition ++;
    }
    return number;
}

string AuxiliaryMethods::changeFirstLetterToUpperAndOtherToLower(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

double AuxiliaryMethods::convertStringToDouble(string stringNumber)
{
    double number = 0;
    size_t commaPosition = stringNumber.find(",");
    if (commaPosition != string::npos)
    {
        stringNumber.replace(commaPosition, 1, ".");
    }

    try {
        number = stod(stringNumber);
        if (number < 0)
            throw "err";
    }
    catch (...)
    {
        cout << endl << "Wrong value. Try again." << endl << endl;
        number = -1;
    }

    number = round(number * 100.0)/ 100.0;

    return number;
}
