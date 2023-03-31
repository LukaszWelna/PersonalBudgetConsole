#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

using namespace std;

class Expense
{
    // ATTRIBUTES
    int id;
    int userId;
    int date;
    string item;
    double amount;

    // METHODS
public:
    // GETTERS
    int getId();
    int getUserId();
    int getDate();
    string getItem();
    double getAmount();

    // SETTERS
    void setId(int id);
    void setUserId(int userId);
    void setDate(int date);
    void setItem(string item);
    void setAmount(double amount);

    bool operator < (Expense &expense)
    {
        return (this -> date < expense.getDate());
    }
};

#endif // EXPENSE_H

