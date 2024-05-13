#ifndef ACCOUNT_CLASS
#define ACCOUNT_CLASS

#include <iostream>
using namespace std;

class BankAccount
{

protected:
    double ID;
    string accountNumber;
    string accountHolderName;
    string contactInformation;
    double balance;
    string address;
    double interestRate;

public:
    BankAccount(double ID)
    {
        this->ID = ID;
        balance = 0.0;
    }

    BankAccount(string accountNumber, string accountHolderName, double balance)
    {
        this->accountNumber = accountNumber;
        this->accountHolderName = accountHolderName;
        this->balance = balance;
    }

    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual double calculateInterest() = 0;

    string getAccountNumber()
    {
        return accountNumber;
    }
    string getAccountHolderName()
    {
        return accountHolderName;
    }

    void setName(string name)
    {
        accountHolderName = name;
    }

    void setContactInformation(string contact)
    {
        contactInformation = contact;
    }

    void setAccountNumber(string number)
    {
        accountNumber = number;
    }

    void setAddress(string addr)
    {
        address = addr;
    }

    string getAddress()
    {
        return address;
    }

    string getContactInformation()
    {
        return contactInformation;
    }

    // virtual ~BankAccount() = default;   // Virtual destructor for polymorphism
};

class SavingsAccount : public BankAccount
{
private:
    double minimumBalance = 500; // "minimumBalance" refers to the lowest amount of funds that must be maintained in an account to avoid penalties or maintain the account's status.

public:
    SavingsAccount(double id) : BankAccount(id) { }

    SavingsAccount(string accountNumber, string accountHolderName, double balance) : BankAccount(accountNumber, accountHolderName, balance)
    {
        interestRate = 0.02;
    }

    void deposit(double amount) override
    {
        balance += amount;
    }

    void withdraw(double amount) override
    {
        if (balance - amount >= minimumBalance)
        {
            balance = balance - amount;
        }
        else
        {
            cout << "Insufficient balance to maintain minimum balance " << endl;
        }
    }

    double calculateInterest() override
    {
        return balance * interestRate; // calculate interest --> formula --> (current balance * interest rate)
    }
};

class CheckingAccount : public BankAccount
{

private:
    double overdraftLimit; // the limit flexibility what customer cannot overdraw their accounts beyond an acceptable level

public:
    CheckingAccount(string accountNumber, string accountHolderName, double balance, double overdraftLimit) : BankAccount(accountNumber, accountHolderName, balance), overdraftLimit(overdraftLimit)
    {
        interestRate = 0.1;
    }

    void deposit(double amount) override
    {
        balance = balance + amount;
    }

    void withdraw(double amount) override
    {
        if (balance + overdraftLimit >= amount)
        {
            balance = balance - amount;
        }
        else
        {
            cout << " Exceeds overdraft limit" << endl;
        }
    }

    double calculateInterest() override
    {
        return 0; // checking account does not earn interest
    }
};

class LoanAccount : public BankAccount
{

private:
    double loanAmount;
    int loanTenure;

public:
    LoanAccount(string accountNumber, string accountHolderName, double loanAmount, double interestRate, int loanTenure) : BankAccount(accountNumber, accountHolderName, 0.0), loanAmount(loanAmount), loanTenure(loanTenure)
    // here balance is set by 0.0 in 'BankAccount' initializer list because this is a loan account, not a typical deposit-based account
    {
        this->interestRate = interestRate;
    }

    void deposit(double amount) override
    {
        cout << "Deposit not allowed for loan accounts.\n";
    }

    void withdraw(double amount) override
    {
        cout << "Withdraw not allowed for loan accounts" << endl;
    }

    double calculateInterest() override
    {
        return loanAmount * interestRate;
    }

    // This function allows a payment to be made toward the loan. It serves to reduce the outstanding loan balance by the specified amount.
    void makePayment(double amount)
    {
        cout << "Payment of " << amount << "made towards loan " << endl;
        loanAmount = loanAmount - amount;
    }

    // This function calculates the monthly payment required to repay the loan over a specified tenure, given the loan amount, interest rate, and loan tenure.
    void calculateMonthlyPayment()
    {
        double monthlyPayment = (loanAmount * interestRate) / loanTenure;
        cout << "Monthly payment: " << monthlyPayment << endl;
    }
};

#endif
