#include "UserManager.h"

//GETTERS
int UserManager::getLoggedUserId()
{
    return idLoggedUser;
}

void UserManager::userSignUp()
{
    User user;

    system("cls");
    cout << " >>> ADDING NEW USER <<<" << endl << endl;

    user = getNewUserData();

    if ((user.getLogin() != "") && (user.getName() != "") && (user.getSurname() != "") && (user.getPassword() != ""))
    {
        if (xmlFileWithUsers.addUserToXmlFile(user))
        {
            users.push_back(user);
            cout << endl << "Account created successfully" << endl ;
        }
        else
            cout << endl << "Creating account failed." << endl;

        cout << endl;
        system("pause");
    }
}

User UserManager::getNewUserData()
{
    User user;

    user.setId(retrieveNewUserId());

    string line = "";
    cout << "Enter name: ";
    line = AuxiliaryMethods::readLine();
    if (line == "")
    {
        cout << endl << "Name must contain character. Try again." << endl << endl;
        system("pause");
        return user;
    }
    user.setName(AuxiliaryMethods::changeFirstLetterToUpperAndOtherToLower(line));

    cout << "Enter surname: ";
    line = AuxiliaryMethods::readLine();
    if (line == "")
    {
        cout << endl << "Surname must contain character. Try again." << endl << endl;
        system("pause");
        return user;
    }
    user.setSurname(AuxiliaryMethods::changeFirstLetterToUpperAndOtherToLower(line));

    cout << "Enter login: ";
    user.setLogin(AuxiliaryMethods::readLine());
    if (user.getLogin() == "")
    {
        cout << endl << "Login must contain character. Try again." << endl << endl;
        system("pause");
        return user;
    }
    if (checkLoginExists(user.getLogin()))
    {
        user.setLogin("");
        cout << endl << "Login already exists in database. Try again." << endl << endl;
        system("pause");
        return user;
    }
    cout << "Enter password: ";
    user.setPassword(AuxiliaryMethods::readLine());
    if (user.getPassword() == "")
    {
        cout << endl << "Password must contain character. Try again." << endl << endl;
        system("pause");
        return user;
    }

    return user;
}

int UserManager::retrieveNewUserId()
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

bool UserManager::checkLoginExists(string login)
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

void UserManager::userLogin()
{
    User user;
    string login = "", password = "";

    system("cls");
    cout << " >>> USER LOGIN <<<" << endl << endl;
    cout << "Enter login: ";
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
            cout << endl << "Wrong password entered 3 times." << endl << endl;
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

void UserManager::userLogout()
{
    idLoggedUser = 0;
    system("cls");
    cout << " >>> USER LOGOUT <<<" << endl << endl;
    cout << "User logout successful" << endl;
    cout << endl;
    system("pause");
}

void UserManager::changeLoggedUserPassword()
{
    string newPassword = "";
    system("cls");
    cout << " >>> CHANGING USER PASSWORD <<<" << endl << endl;
    cout << "Enter new password: ";
    newPassword = AuxiliaryMethods::readLine();
    vector <User>::iterator it;

    for (it = users.begin(); it != users.end(); it++)
    {
        if (it -> getId() == idLoggedUser)
        {
            if (xmlFileWithUsers.changeLoggedUserPassword(idLoggedUser, newPassword))
            {
                it -> setPassword(newPassword);
                cout << endl << "Password changed." << endl;
                cout << endl;
                system("pause");
            }
            else
            {
                cout << endl << "Cannot open the database. Changing password failed." << endl;
            }
        }
    }
}
