#ifndef BANK_CLASS
#define BANK_CLASS

#include <iostream>
#include <vector>
#include <fstream>
#include "Account.h"
#include <LinkedList.h>
using namespace std;

class Bank
{
private:
    string bankName;
    string bankLocation;
    int bankID;

public:
    Bank(const string &bankName, const string &bankLocation)
    {
        this->bankLocation = bankLocation;
        this->bankName = bankName;
    }

    LinkedList<SavingsAccount *> savingsAccounts;

    void createAccount()
    {
        string userName, address, contactInformation, accountNumber;

        cout << "Enter the name of the user: ";
        cin >> userName;
        cout << endl;

        cout << "Enter the account number of the user: ";
        cin >> accountNumber;
        cout << endl;

        cout << "Enter the address of the user: ";
        cin >> address;
        cout << endl;

        cout << "Enter the phone number of the user: ";
        cin >> contactInformation;
        cout << endl;

        SavingsAccount *acc1 = new SavingsAccount(savingsAccounts.size() + 1);
        acc1->setName(userName);
        acc1->setAddress(address);
        acc1->setContactInformation(contactInformation);
        acc1->setAccountNumber(accountNumber);

        savingsAccounts.insertAtEnd(acc1);
    }
};

#endif
