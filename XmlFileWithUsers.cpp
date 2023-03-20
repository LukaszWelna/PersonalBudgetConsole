#include "XmlFileWithUsers.h"

vector <User> XmlFileWIthUsers::loadUsersFromXmlFile()
{
    CMarkup xml;
    User user;
    vector <User> users;

    bool loadSuccess = xml.Load("users.xml");

    if (loadSuccess)
    {
        xml.FindElem();
        xml.IntoElem();
        // LOADING ALL USERS
        while(xml.FindElem("User"))
        {
            xml.IntoElem();
            xml.FindElem("Id");
            user.setId(AuxiliaryMethods::convertStringToInt(xml.GetData()));
            xml.FindElem("Login");
            user.setLogin(xml.GetData());
            xml.FindElem("Password");
            user.setPassword(xml.GetData());
            xml.FindElem("Name");
            user.setName(xml.GetData());
            xml.FindElem("Surname");
            user.setSurname(xml.GetData());
            xml.OutOfElem();
            users.push_back(user);
        }
    }
    else
    {
        cout << "Cannot load users from database." << endl;
    }
    return users;
}

void XmlFileWIthUsers::addUserToXmlFile(User user)
{
    CMarkup xml;
    bool loadSuccess = xml.Load("users.xml");

    if (!loadSuccess)
    {
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("Id", user.getId());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());

    xml.Save("users.xml");
}

bool XmlFileWIthUsers::changeLoggedUserPassword(int loggedUserId, string newPassword)
{
    CMarkup xml;
    bool loadSuccess = xml.Load("users.xml");

    if (loadSuccess)
    {
        xml.FindElem();
        xml.IntoElem();
        for (int i = 0; i < loggedUserId; i++)
        {
            xml.FindElem("User");
        }
        xml.IntoElem();
        xml.FindElem("Password");
        xml.SetData(newPassword);
        xml.Save("users.xml");
        return true;
    }
        return false;
}
