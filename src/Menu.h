#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <LinkedList.h>
#include <functional>
using namespace std;

class MenuOption
{
private:
    string title;
    std::function<void()> action;

public:
    MenuOption() {}

    MenuOption(string title, std::function<void()> actn)
    {
        this->title = title;
        this->action = actn;
    }

    string getTitle()
    {
        return title;
    }

    void invoke()
    {
        action();
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
            cout << i + 1 << ". " << menuOptions.get(i).getTitle() << endl;
        }
    }
};

#endif
