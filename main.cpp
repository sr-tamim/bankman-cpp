#include<iostream>

using namespace std;

class BankAccount{};

class LoanAccount{};

class Customer{};

class SavingsAcount : public BankAccount{};

class CheckingAccount : public BankAccount{};

class MortageLoan : public LoanAccount{};

class CorporateCustomer : public Customer{};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
