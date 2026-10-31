#include <iostream>
#include <string>

// Base Class
class SmartDevice {
protected:
    std::string deviceName;

public:
    SmartDevice(std::string name) : deviceName(name) {}
    
    // Virtual function to enable polymorphism
    virtual void performAction() {
        std::cout << deviceName << " performing generic smart action." << std::endl;
    }

    virtual ~SmartDevice() {}
};

// Derived Class 1: Smartphone
class SmartPhone : public SmartDevice {
public:
    SmartPhone(std::string name) : SmartDevice(name) {}
    
    // Overriding the virtual function
    void performAction() override {
        std::cout << "[Smartphone]: " << deviceName << " is opening an application and connecting to 5G." << std::endl;
    }
};

// Derived Class 2: SmartSpeaker
class SmartSpeaker : public SmartDevice {
public:
    SmartSpeaker(std::string name) : SmartDevice(name) {}
    
    // Overriding the virtual function
    void performAction() override {
        std::cout << "[Smart Speaker]: " << deviceName << " is playing audio music via voice command." << std::endl;
    }
};

int main() {
    std::cout << "--- Smart Device Runtime Polymorphism ---" << std::endl;
    
    // Base class pointer pointing to a Smartphone object
    SmartDevice* devicePtr = new SmartPhone("iPhone 15 Pro");
    devicePtr->performAction(); // Dynamically resolves to SmartPhone's function
    delete devicePtr;
    
    std::cout << "---------------------------------------" << std::endl;
    
    // Base class pointer pointing to a SmartSpeaker object
    devicePtr = new SmartSpeaker("HomePod Mini");
    devicePtr->performAction(); // Dynamically resolves to SmartSpeaker's function
    delete devicePtr;
    
    return 0;
}
