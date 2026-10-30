#include <iostream>

// Base Parent Class
class PaymentMethod {
public:
    // 1. Virtual function required for polymorphism
    virtual void processPayment(double amount) {
        std::cout << "Processing a generic payment of $" << amount << std::endl;
    }
    virtual ~PaymentMethod() = default;
};

// Derived Class 1
class CreditCard : public PaymentMethod {
public:
    // 2. Overriding the virtual function
    void processPayment(double amount) override {
        std::cout << "Charging $" << amount << " to Credit Card (Applying 2% fee)." << std::endl;
    }
};

// Derived Class 2
class PayPal : public PaymentMethod {
public:
    // 2. Overriding the virtual function
    void processPayment(double amount) override {
        std::cout << "Logging into PayPal to authorize payment of $" << amount << std::endl;
    }
};

int main() {
    std::cout << "\n--- Part 2: Runtime Polymorphism ---" << std::endl;

    // 3. Demonstrating runtime polymorphism using a base-class pointer
    PaymentMethod* currentPayment = nullptr;

    // Pointing to a CreditCard object
    currentPayment = new CreditCard();
    currentPayment->processPayment(150.00); // Calls CreditCard version
    delete currentPayment;

    // Pointing to a PayPal object using the exact same pointer variable
    currentPayment = new PayPal();
    currentPayment->processPayment(85.50);  // Calls PayPal version
    delete currentPayment;

    return 0;
}
