#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <LinkedList.h>
#include <functional>
using namespace std;

class MenuOption
{
public:
    string title;
    void (*invoke)();

    MenuOption() {}

    MenuOption(string title, void (*invk)())
    {
        this->title = title;
        this->invoke = invk;
    }
};

class Menu
{
public:
    LinkedList<MenuOption> menuOptions;

    void displayMenu()
    {
        for (int i = 0; i < menuOptions.size(); i++)
        {
            cout << i + 1 << ". " << menuOptions.get(i).title << endl;
        }
    }
};

#endif
