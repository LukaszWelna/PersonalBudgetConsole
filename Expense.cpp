#include "Expense.h"

// GETTERS
int Expense::getId()
{
    return id;
}

int Expense::getUserId()
{
    return userId;
}

string Expense::getDate()
{
    return date;
}

string Expense::getItem()
{
    return item;
}

float Expense::getAmount()
{
    return amount;
}

// SETTERS
void Expense::setId(int id)
{
    this -> id = id;
}

void Expense::setUserId(int userId)
{
    this -> userId = userId;
}

void Expense::setDate(string date)
{
    this -> date = date;
}

void Expense::setItem(string item)
{
    this -> item = item;
}

void Expense::setAmount(float amount)
{
    this -> amount = amount;
}
