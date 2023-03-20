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

string Income::getDate()
{
    return date;
}

string Income::getItem()
{
    return item;
}

float Income::getAmount()
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

void Income::setDate(string date)
{
    this -> date = date;
}

void Income::setItem(string item)
{
    this -> item = item;
}

void Income::setAmount(float amount)
{
    this -> amount = amount;
}
