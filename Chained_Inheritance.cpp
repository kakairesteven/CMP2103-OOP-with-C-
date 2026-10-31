#include <iostream>
#include <string>

// Base Class: Level 1
class Vehicle {
protected:
    std::string brand;

public:
    Vehicle(std::string b) : brand(b) {}
    
    void startEngine() {
        std::cout << brand << " engine started safely." << std::endl;
    }
};

// Derived Class: Level 2 (Inherits from Vehicle)
class Car : public Vehicle {
protected:
    int numberOfDoors;

public:
    Car(std::string b, int doors) : Vehicle(b), numberOfDoors(doors) {}
    
    void displayCarDetails() {
        // Demonstrates access to inherited member 'brand'
        std::cout << "Car Brand: " << brand << ", Doors: " << numberOfDoors << std::endl;
    }
};

// Derived Class: Level 3 (Inherits from Car - Chained Inheritance)
class ElectricCar : public Car {
private:
    int batteryCapacity; // Locally defined member

public:
    ElectricCar(std::string b, int doors, int battery) 
        : Car(b, doors), batteryCapacity(battery) {}
    
    void displayElectricDetails() {
        // Demonstrates access to locally defined member
        std::cout << "Battery Capacity: " << batteryCapacity << " kWh" << std::endl;
    }
};

int main() {
    std::cout << "--- Chained (Multilevel) Inheritance Demonstration ---" << std::endl;
    
    // Creating an object of the most derived class
    ElectricCar myEV("Tesla", 4, 85);
    
    // 1. Using an inherited member function from the grandparent class (Vehicle)
    myEV.startEngine();
    
    // 2. Using an inherited member function from the parent class (Car)
    myEV.displayCarDetails();
    
    // 3. Using a locally defined member function in ElectricCar
    myEV.displayElectricDetails();
    
    return 0;
}
