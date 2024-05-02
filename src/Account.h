
#ifndef ACCOUNT_CLASS
#define ACCOUNT_CLASS

#include<iostream>
using namespace std;

class BankAccount{
private:
    string accountNumber;
    string accountHolderName;
    double balance;
protected:
    double interestRate;
    //vector<Transaction> transactions;
public:
    BankAccount(const string& accountNumber, const string& accountHolderName, double initialBalance){
        this->accountNumber = accountNumber;
        this->accountHolderName = accountHolderName;
        balance = initialBalance;
    }

    string getAccountNumber() const{
        return accountNumber;
    }

    string getAccountHolderName() const{
        return accountHolderName;
    }

    double getBalance() const{
        return balance;
    }

    virtual void deposit(double amount);
    virtual void withdraw(double amount);
    virtual double calculateInterest() = 0;
    virtual void calcualateInterest() = 0;
    virtual void applyFees();
};

#endif // ACCOUNT_CLASS
