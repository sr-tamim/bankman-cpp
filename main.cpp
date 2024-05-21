#include<iostream>
#include<vector>
#include<Account.h>
#include<Customer.h>
#include<Bank.h>
#include<Utilities.h>
#include<Menu.h>

using namespace std;


int main()
{
    Menu menu;
    Bank bank("NUB Bank Ltd", "Dhaka");

    menu.menuOptions.insertAtEnd(MenuOption("Create Account", [&bank]() { bank.createAccount(); }));
    menu.menuOptions.insertAtEnd(MenuOption("Exit", []() { Utilities::exit(); }));

    int choice;
    while (true)
    {
        menu.displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        if (choice < 1 || choice > menu.menuOptions.size())
        {
            cout << "Invalid choice" << endl;
            continue;
        }

        menu.menuOptions.get(choice - 1).invoke();
    }

    return 0;
}
