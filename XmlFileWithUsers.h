#ifndef XMLFILEWITHUSERS_H
#define XMLFILEWITHUSERS_H

#include <iostream>
#include <vector>
#include "Markup.h"
#include "User.h"
#include "AuxiliaryMethods.h"

using namespace std;

class XmlFileWIthUsers
{
    // ATTRIBUTES

    // METHODS
public:
    vector <User> loadUsersFromXmlFile();
    void addUserToXmlFile(User user);
    bool changeLoggedUserPassword(int loggedUserId, string newPassword);
};

#endif // XMLFILEWITHUSERS_H

