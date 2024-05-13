#ifndef UTILITIES_CLASS
#define UTILITIES_CLASS

#include <iostream>
using namespace std;

class Utilities
{
public:
    static void clearScreen()
    {
        cout << "\033[2J\033[1;1H";
    }
};

#endif