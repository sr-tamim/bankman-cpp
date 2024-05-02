#include<iostream>
#include<vector>
#include<Account.h>

using namespace std;

class Customer; // forward declaration to use inside LoadAccount class

class LoanAccount{
private:
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
    virtual bool isEligible(const Customer& customer);
};

class Customer{
private:
    string name;
    string address;
    string contactInformation;
protected:
    vector<BankAccount*> accounts;
    vector<LoanAccount*> loans;
public:
    Customer(const string& name, const string& address, const string& contactInformation){
        this->name = name;
        this->address = address;
        this->contactInformation = contactInformation;
    }

    string getName() const{
        return name;
    }

    string getAddress() const{
        return address;
    }

    string getContactInformation() const{
        return contactInformation;
    }

    virtual double calculateCreditScore() = 0;
    virtual void updateCustomerInformation();
    void addAccount(BankAccount* account);
    void addLoan(LoanAccount* loan);
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
