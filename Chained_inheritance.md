# Homework Assignment: Multilevel Inheritance Documentation

## 1. Overview of Multilevel Inheritance
Multilevel (chained) inheritance refers to a class hierarchy where a derived class inherits from another derived class, forming a clear inheritance chain. In this paradigm, properties and methods flow sequentially down from the grandparent to the parent, and down to the child class.

---

## 2. Real-World Class Hierarchy Design
The code implements a vehicle lifecycle tracking system consisting of three sequential layers:

*   **Vehicle (Base Class / Grandparent):** 
    *   Defines core attributes universal to transport systems.
    *   Contains the `brand` data field.
    *   Exposes the `startEngine()` function.
*   **Car (Derived Class / Parent):** 
    *   Inherits explicitly from `Vehicle`.
    *   Introduces the `numberOfDoors` attribute.
    *   Defines the local `drive()` function while retaining access to `brand`.
*   **ElectricCar (Most Derived Class / Child):** 
    *   Inherits from `Car`.
    *   Introduces the specialized `batteryCapacity` specification.
    *   Contains the `charge()` function while sequentially inheriting all fields above it (`brand`, `numberOfDoors`, `startEngine()`, and `drive()`).

---

## 3. Class Structure Decomposition

| Class Layer | Class Name | Inherits From | New Attributes/Methods Added |
| :--- | :--- | :--- | :--- |
| **Grandparent** | `Vehicle` | *None (Base)* | `brand` (string), `startEngine()` |
| **Parent** | `Car` | `Vehicle` | `numberOfDoors` (int), `drive()` |
| **Child** | `ElectricCar` | `Car` | `batteryCapacity` (int), `charge()` |

---

## 4. Compilation and Execution
To run and verify the source file using standard GCC compilers, run the following commands in your workspace directory terminal:

```bash
# Compile the source program
g++ -std=c++11 vehicle_inheritance.cpp -o vehicle_inheritance

# Run the output binary executable
./vehicle_inheritance
```
