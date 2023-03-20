#include "UserMenager.h"

//GETTERS
int UserMenager::getLoggedUserId()
{
    return idLoggedUser;
}

void UserMenager::userSignUp()
{
    User user;

    user = getNewUserData();

    if (user.getLogin() != "")
    {
        users.push_back(user);
        xmlFileWithUsers.addUserToXmlFile(user);

        cout << endl << "Account created successfully" << endl << endl;
        system("pause");
    }
}

User UserMenager::getNewUserData()
{
    User user;

    user.setId(retrieveNewUserId());

    cout << "Enter name: ";
    user.setName(AuxiliaryMethods::readLine());
    cout << "Enter surname: ";
    user.setSurname(AuxiliaryMethods::readLine());
    cout << "Enter login: ";
    user.setLogin(AuxiliaryMethods::readLine());
    if (user.getLogin() == "")
    {
        cout << "Login must contains character or number. Try again." << endl;
        system("pause");
        return user;
    }
    if (checkLoginExists(user.getLogin()))
    {
        user.setLogin("");
        cout << "Login already exists in database. Try again." << endl;
        system("pause");
        return user;
    }
    cout << "Enter password: ";
    user.setPassword(AuxiliaryMethods::readLine());

    return user;
}

int UserMenager::retrieveNewUserId()
{
    if (users.empty())
    {
        return 1;
    }
    else
    {
        return users.back().getId() + 1;
    }
}

void UserMenager::showUsers()
{
    for (int i = 0; i < (int) users.size(); i++)
    {
        cout << "User: " << i << endl;
        cout << "Id: " << users[i].getId() << endl;
        cout << "Login: " << users[i].getLogin() << endl;
        cout << "Password: " << users[i].getPassword() << endl;
        cout << "Name: " << users[i].getName() << endl;
        cout << "Surname: " << users[i].getSurname() << endl;
    }
}

bool UserMenager::checkLoginExists(string login)
{
    for (int i = 0; i < (int) users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            return true;
        }
    }
    return false;
}

void UserMenager::userLogin()
{
    User user;
    string login = "", password = "";

    cout << endl << "Enter login: ";
    login = AuxiliaryMethods::readLine();

    vector <User>::iterator it = users.begin();
    while (it != users.end())
    {
        if (it -> getLogin() == login)
        {
            for (int numberOfAttemps = 3; numberOfAttemps > 0; numberOfAttemps--)
            {
                cout << "Enter password. Remain attemps: " << numberOfAttemps << ": ";
                password = AuxiliaryMethods::readLine();

                if (it -> getPassword() == password)
                {
                    cout << endl << "Login successful." << endl << endl;
                    system("pause");
                    idLoggedUser = it -> getId();
                    return;
                }
            }
            cout << "Wrong password entered 3 times." << endl;
            system("pause");
            idLoggedUser = 0;
            return;
        }
        it++;
    }
    cout << "There is no user with this login." << endl << endl;
    system("pause");
    idLoggedUser = 0;
    return;
}

void UserMenager::userLogout()
{
    idLoggedUser = 0;
    cout << "User logout successfull" << endl;
}

void UserMenager::changeLoggedUserPassword()
{
    string newPassword = "";
    cout << "Enter new password: ";
    newPassword = AuxiliaryMethods::readLine();
    vector <User>::iterator it = users.begin();

    for (it; it != users.end(); it++)
    {
        if (it -> getId() == idLoggedUser)
        {
            break;
        }
    }
    if (xmlFileWithUsers.changeLoggedUserPassword(idLoggedUser, newPassword))
    {
        it -> setPassword(newPassword);
        cout << "Password changed." << endl << endl;
        system("pause");
    }
    else
    {
        cout << "Cannot open the database. Changing password failed." << endl;
    }
}
