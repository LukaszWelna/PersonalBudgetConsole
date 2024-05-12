#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include "User.h"
#include "AuxiliaryMethods.h"
#include "XmlFileWithUsers.h"

using namespace std;

class UserManager
{
    // ATTRIBUTES
    int idLoggedUser;
    vector <User> users;
    XmlFileWithUsers xmlFileWithUsers;

    // METHODS
    User getNewUserData();
    int retrieveNewUserId();
    bool checkLoginExists(string login);
public:
    //CONSTRUCTOR
    UserManager(string fileNameWithUsers) : xmlFileWithUsers(fileNameWithUsers)
    {
        idLoggedUser = 0;
        users = xmlFileWithUsers.loadUsersFromXmlFile();
    }
    // GETTERS
    int getLoggedUserId();
    void userSignUp();
    void userLogin();
    void changeLoggedUserPassword();
    void userLogout();
};


#endif // USERMANAGER_H

