# `car.cpp`

## Overview
This program demonstrates the concept of inheritance in C++. It creates a base class called `Vehicle` and a derived class called `Car`.

## OOP Concepts Used
- Classes
- Inheritance
- Object creation
- Method calling

## Class Design

### `Vehicle`
- Contains the attribute `brand`, which is set to `"Ford"`
- Contains the method `honk()`, which prints: `Tuut, tuut!`

### `Car : public Vehicle`
- Inherits from the `Vehicle` class
- Adds another attribute, `model`, which is set to `"Mustang"`

## Algorithm
1. Create an object named `myCar` of type `Car`.
2. Call the inherited `honk()` method from `Vehicle`.
3. Print the full car name by combining `brand` and `model`.
4. End the program.

## Example Output
```cpp
Tuut, tuut!
Ford Mustang
```

## Possible Error Points
- Make sure `using namespace std;` is included so `cout`, `string`, and `endl` work correctly.
- Use `public` inheritance so the derived class can access the base class members.
- String concatenation must use `std::string` values, not plain C-style strings, when using `+`.

## Summary
This program shows how a car can inherit features from a vehicle, which is a key idea in object-oriented programming.