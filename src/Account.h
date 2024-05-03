
#ifndef ACCOUNT_CLASS
#define ACCOUNT_CLASS

#include <iostream>
#include <vector>
using namespace std;

class BankAccount
{
private:
    double ID;
    string accountNumber;
    string accountHolderName;
    string contactInformation;
    double balance;
    string address;

protected:
    double interestRate;
    // vector<Transaction> transactions;
public:
    BankAccount(double ID)
    {
        this->ID = ID;
    }

    BankAccount(const string &accountNumber, const string &accountHolderName, double initialBalance)
    {
        this->accountNumber = accountNumber;
        this->accountHolderName = accountHolderName;
        balance = initialBalance;
    }

    string getAccountNumber() const
    {
        return accountNumber;
    }

    string getAccountHolderName() const
    {
        return accountHolderName;
    }

    double getBalance() const
    {
        return balance;
    }

    void setName(const string &name)
    {
        accountHolderName = name;
    }

    void setContactInformation(const string &contactInformation)
    {
        this->contactInformation = contactInformation;
    }

    void setAccountNumber(string accountNumber)
    {
        this->accountNumber = accountNumber;
    }

    void setAddress(string address)
    {
        this->address = address;
    }

    string getName()
    {
        return accountHolderName;
    }

    string getAddress()
    {
        return address;
    }

    string getContactInformation()
    {
        return contactInformation;
    }

    /*void displayAccounts() {
        for (const auto& acc : accounts) {
        cout << "ID: " << acc->ID << endl;
        cout << "Name: " << acc->getName() << endl;
        cout << "Address: " << acc->getAddress() << endl;
        cout << "Contact Information: " << acc->getContactInformation() << endl;
        cout << endl;
        }
    }*/

    virtual void deposit(double amount);
    virtual void withdraw(double amount);
    virtual double calculateInterest();
    virtual void calcualateInterest();
    virtual void applyFees();
};

class LoanAccount
{
private:
    double customerID;
    double loanAmount;
    double interestRate;
    int loanTenure;

protected:
    // vector<Payment> paymentHistory;
public:
    LoanAccount(double loanAmount, double interestRate, int loanTenure)
    {
        this->loanAmount = loanAmount;
        this->interestRate = interestRate;
        this->loanTenure = loanTenure;
    }

    double getLoanAmount() const
    {
        return loanAmount;
    }

    double getInterestRate() const
    {
        return interestRate;
    }

    double getLoanTenure() const
    {
        return loanTenure;
    }

    virtual bool makePayment(double amount);
    virtual void calculateMonthlyPayment() = 0;
    virtual bool isEligible();
};

#endif // ACCOUNT_CLASS
