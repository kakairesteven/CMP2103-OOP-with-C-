
#include <iostream>
using namespace std;

// Base class
class Payment
{
public:
    double amount;

    virtual void makePayment()
    {
        cout << "Processing payment" << endl;
    }
};

// First derived class
class CashPayment : public Payment
{
public:
    void makePayment() override
    {
        cout << "Cash payment made: UGX "
             << amount << endl;
    }
};

// Second derived class
class MobileMoneyPayment : public Payment
{
public:
    void makePayment() override
    {
        cout << "Mobile money payment made: UGX "
             << amount << endl;
    }
};

// Function using a base-class reference
void processPayment(Payment& p)
{
    p.makePayment();
}

int main()
{
    CashPayment cash;
    MobileMoneyPayment mobile;

    cash.amount = 50000;
    mobile.amount = 100000;

    cout << "PAYMENT SYSTEM" << endl;

    processPayment(cash);
    processPayment(mobile);

    return 0;
}
