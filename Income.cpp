#include "Income.h"

// GETTERS
int Income::getId()
{
    return id;
}

int Income::getUserId()
{
    return userId;
}

int Income::getDate()
{
    return date;
}

string Income::getItem()
{
    return item;
}

double Income::getAmount()
{
    return amount;
}

// SETTERS
void Income::setId(int id)
{
    this -> id = id;
}

void Income::setUserId(int userId)
{
    this -> userId = userId;
}

void Income::setDate(int date)
{
    this -> date = date;
}

void Income::setItem(string item)
{
    this -> item = item;
}

void Income::setAmount(double amount)
{
    this -> amount = amount;
}
