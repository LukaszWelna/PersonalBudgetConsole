#ifndef XMLFILEWITHUSERS_H
#define XMLFILEWITHUSERS_H

#include <iostream>
#include <vector>
#include "Markup.h"
#include "User.h"
#include "AuxiliaryMethods.h"
#include "XmlFile.h"

using namespace std;

class XmlFileWithUsers : public XmlFile
{
    // ATTRIBUTES

    // METHODS
public:
    //CONSTRUCTOR
    XmlFileWithUsers(string fileNameWithUsers) : XmlFile(fileNameWithUsers)
    {

    }
    vector <User> loadUsersFromXmlFile();
    bool addUserToXmlFile(User user);
    bool changeLoggedUserPassword(int loggedUserId, string newPassword);
};

#endif // XMLFILEWITHUSERS_H

