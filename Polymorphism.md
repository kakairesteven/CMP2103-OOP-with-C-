# Object-Oriented Programming (C++) Take-Home Assignment

## Part 1: Chained (Multilevel) Inheritance
Chained inheritance occurs when a class is derived from another derived class, forming a linear relationship hierarchy.

### Real-World Example Implementation
*   **Grandparent Class:** `Vehicle` (defines generic brand metadata and standard launch logic).
*   **Parent Class:** `Car` (inherits from `Vehicle`, adds door metrics).
*   **Child Class:** `ElectricCar` (inherits from `Car`, adds specific battery tracking details).

### Guide for Hand-Drawn Illustration (Inheritance Chain)
To satisfy the hand-drawn diagram requirement, draw three rectangular blocks stacked vertically on a page:
1.  **Top Block:** Label it `Vehicle`. Inside, list `brand` under data members and `startEngine()` under methods.
2.  **Middle Block:** Label it `Car`. Draw an upward-pointing arrow `▲` from `Car` directly to `Vehicle` to represent inheritance. Inside, list `numberOfDoors` and `displayCarDetails()`.
3.  **Bottom Block:** Label it `ElectricCar`. Draw an upward-pointing arrow `▲` from `ElectricCar` to `Car`. Inside, list `batteryCapacity` and `displayElectricDetails()`.

---

## Part 2: Runtime Polymorphism
Polymorphism allows objects of different classes to react uniquely to the exact same function signature call.

### Real-World Example Implementation
*   **Base Class:** `SmartDevice` containing a `virtual void performAction()` function.
*   **Derived Classes:** `SmartLight` and `SmartThermostat`, both overriding `performAction()`.
*   **Execution:** A base pointer vector or standalone array invokes `.performAction()` at runtime, executing specialized behavior depending on the target object type.

### Guide for Hand-Drawn Illustration (Polymorphism)
To draw the required illustration for this section:
1.  Draw a single base pointer box labeled `SmartDevice* ptr`.
2.  Draw a split path extending from this pointer leading to two distinct object boxes on the right side: one labeled `SmartLight` and the other labeled `SmartThermostat`.
3.  Draw an arrow pointing from `ptr` to the `SmartLight` instance and label the action path: `ptr->performAction() -> Lights Turn ON!`.
4.  Draw a dashed alternative arrow pointing to the `SmartThermostat` instance and label it: `ptr->performAction() -> Climate adjusts!`.
