# Rectangle Class Assignment

## Overview
This program implements a robust `Rectangle` class in C++ to demonstrate the core principles of Object-Oriented Programming (OOP), specifically **Encapsulation** and data validation.

## Class Features
- **Private Attributes:** `width` and `length` are protected from direct external modification.
- **Data Validation:** Setters include checks to ensure dimensions are strictly positive values.
- **Default Constructor:** Automatically initializes dimensions to a default of `1.0`.
- **Member Functions:** Dedicated methods to dynamically calculate the rectangle's **Area** and **Perimeter**.

## Object-Oriented Design

| Principle | Implementation Details |
| :--- | :--- |
| **Encapsulation** | Attributes are hidden using the `private` access specifier. |
| **Data Integrity** | Controlled mutations via public getters and setters. |
| **Const Correctness** | Computation and read-only methods are marked `const` to protect state. |

## How to Compile and Run
To compile and run the source code using a standard C++ compiler (like `g++`), run the following commands in your terminal:

```bash
g++ Rectangle.cpp -o Rectangle
./Rectangle
```
