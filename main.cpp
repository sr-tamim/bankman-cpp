#include<iostream>

using namespace std;

class BankAccount{
public: 
    virtual void calcualateInterest() = 0;
    virtual void applyFees();
};

class LoanAccount{
public:
    virtual void calculateMonthlyPayment() = 0;
    virtual bool isEligible(const Customer& customer);
};

class Customer{
public: 
    virtual double calculateCreditScore() = 0;
    virtual void updateCustomerInformation();
};

class SavingsAcount : public BankAccount{};

class CheckingAccount : public BankAccount{};

class MortageLoan : public LoanAccount{};

class CorporateCustomer : public Customer{};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
