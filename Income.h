#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income
{
    // ATTRIBIUTES
    int id;
    int userId;
    int date;
    string item;
    float amount;

    // METHODS
public:
    // GETTERS
    int getId();
    int getUserId();
    int getDate();
    string getItem();
    float getAmount();

    // SETTERS
    void setId(int id);
    void setUserId(int userId);
    void setDate(int date);
    void setItem(string item);
    void setAmount(float amount);
};

#endif // INCOME_H

