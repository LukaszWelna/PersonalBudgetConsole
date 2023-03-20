#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income
{
    // ATTRIBIUTES

    int id;
    int userId;
    string date;
    string item;
    float amount;

    // METHODS
    // GETTERS
    int getId();
    int getUserId();
    string getDate();
    string getItem();
    float getAmount();

    // SETTERS
    void setId(int id);
    void setUserId(int userId);
    void setDate(string date);
    void setItem(string item);
    void setAmount(float amount);
};

#endif // INCOME_H

