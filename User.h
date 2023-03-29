#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User
{
    // ATTRIBUTES
    int id;
    string login;
    string password;
    string name;
    string surname;

    // METHODS
public:
    // GETTERS
    int getId();
    string getLogin();
    string getPassword();
    string getName();
    string getSurname();

    // SETTERS
    void setId(int id);
    void setLogin(string login);
    void setPassword(string password);
    void setName(string name);
    void setSurname(string surname);
};


#endif // USER_H

