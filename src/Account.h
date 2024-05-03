
#ifndef ACCOUNT_CLASS
#define ACCOUNT_CLASS

#include<iostream>
#include<vector>
using namespace std;

class BankAccount{
private:
    double customerID;
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


class LoanAccount{
private:
    double customerID;
    double loanAmount;
    double interestRate;
    int loanTenure;
protected:
    //vector<Payment> paymentHistory;
public:
    LoanAccount(double loanAmount, double interestRate, int loanTenure){
        this->loanAmount = loanAmount;
        this->interestRate = interestRate;
        this->loanTenure = loanTenure;
    }

    double getLoanAmount() const{
        return loanAmount;
    }

    double getInterestRate() const{
        return interestRate;
    }

    double getLoanTenure() const{
        return loanTenure;
    }

    virtual bool makePayment(double amount);
    virtual void calculateMonthlyPayment() = 0;
    virtual bool isEligible();
};


#endif // ACCOUNT_CLASS
