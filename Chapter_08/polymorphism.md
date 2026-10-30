# Assignment Part 2: Runtime Polymorphism Practice

This document explains how runtime polymorphism works in C++ using a real-world electronic payment system scenario.

## 🏗️ Core Polymorphism Elements

To achieve runtime polymorphism, three specific structural rules must be met in the program's design:

1. **A Parent Class with a Virtual Function:** The base class (`PaymentMethod`) defines a general action function and marks it with the `virtual` keyword. This signals to the compiler that child classes are allowed to change this action's behavior.
2. **Derived Classes with Overrides:** Specific child classes (`CreditCard` and `PayPal`) inherit from the base class. They implement their own custom versions of the payment function using the `override` keyword to safely change the behavior.
3. **Base-Class Pointers or References:** Instead of calling functions directly on child objects, the execution context uses a generic pointer of the parent class type (`PaymentMethod*`).

---

## 🔍 Conceptual Explanations

### 1. The Power of Virtual Dispatch
Normally, a compiler decides which function to call based on the variable's type. By marking the parent function as `virtual`, we enable dynamic dispatch. This means the program pauses during execution, looks at the actual object sitting in memory, and runs the specialized version instead of the generic parent version.

### 2. The Safety Guard of the Override Keyword
When a child class re-implements a parent function, adding the `override` keyword forces the compiler to check our work. If we accidentally misspell the function name or use the wrong data types, the compiler will instantly catch the mistake and throw an error, preventing silent logic bugs.

### 3. Runtime Pointer Flexibility
By using a parent pointer variable, we can point it to a `CreditCard` object, process a transaction, and then reassign that exact same pointer variable to a `PayPal` object. The program dynamically adapts on the fly, producing completely different output actions using a single, unified interface.
