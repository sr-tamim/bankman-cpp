#include<iostream>
#include<vector>

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
