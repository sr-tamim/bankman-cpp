#ifndef CUSTOMER_CLASS
#define CUSTOMER_CLASS

#include<iostream>
#include<vector>
using namespace std;


class Customer{
private:
    double ID;
    string name;
    string address;
    string contactInformation;

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
};

#endif // CUSTOMER_CLASS
