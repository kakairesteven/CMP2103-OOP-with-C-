#include <iostream>
using namespace std;

// Base class
class Vehicle
{
public:
    double distance;

    virtual void calculateFuel()
    {
        cout << "Calculating vehicle fuel consumption"
             << endl;
    }
};

// First derived class
class Car : public Vehicle
{
public:
    void calculateFuel() override
    {
        cout << "Car fuel required: "
             << distance / 15 << " litres" << endl;
    }
};

// Second derived class
class Motorcycle : public Vehicle
{
public:
    void calculateFuel() override
    {
        cout << "Motorcycle fuel required: "
             << distance / 40 << " litres" << endl;
    }
};

// Function using a base-class reference
void showFuel(Vehicle& v)
{
    v.calculateFuel();
}

int main()
{
    Car car;
    Motorcycle motorcycle;

    car.distance = 300;
    motorcycle.distance = 300;

    cout << "FUEL CONSUMPTION FOR A 300 KM JOURNEY"
         << endl;

    showFuel(car);
    showFuel(motorcycle);

    return 0;
}
