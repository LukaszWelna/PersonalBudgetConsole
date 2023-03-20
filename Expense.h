#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

using namespace std;

class Expense
{
    // ATTRIBUTES
    int id;
    int userId;
    string date;
    string item;
    float amount;

    // METHODS
public:
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

#endif // EXPENSE_H

