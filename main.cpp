#include <iostream>
#include "PersonalBudget.h"
#include "User.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"

using namespace std;

void showMainMenu()
{
    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Sign up" << endl;
    cout << "2. Login" << endl;
    cout << "9. End" << endl;
    cout << "---------------------------" << endl;
}

void showUserMenu()
{
    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    /*cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Current month balance" << endl;
    cout << "4. Last month balance" << endl;
    cout << "5. Period balance" << endl;
    cout << "---------------------------" << endl;
    */
    cout << "7. Change password" << endl;
    cout << "8. Logout" << endl;
    cout << "---------------------------" << endl;
}

int main()
{
    PersonalBudget personalBudget;

    char choice;

    while (true)
    {
        if (!personalBudget.userLogged())
        {
            showMainMenu();
            cout << "Your choice: ";
            choice = AuxiliaryMethods::readSign();

            switch (choice)
            {
            case '1':
                personalBudget.userSignUp();
                break;
            case '2':
                personalBudget.userLogin();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "No option in menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            showUserMenu();
            cout << "Your choice: ";
            choice = AuxiliaryMethods::readSign();

            switch (choice)
            {
                /*
            case '1':
                personalBudget.addAddressee();
                break;
            case '2':
                personalBudget.searchByFirstname();
                break;
            case '3':
                personalBudget.searchByLastname();
                break;
            case '4':
                personalBudget.showLoggedUserAddresses();
                break;
            case '5':
                personalBudget.deleteAddressee();
                break;
            case '6':
                personalBudget.editAddressee();
                break;
                */
            case '7':
                personalBudget.changeLoggedUserPassword();
                break;
            case '8':
                personalBudget.userLogout();
                break;
            default:
                cout << endl << "No option in menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }


    return 0;
}
