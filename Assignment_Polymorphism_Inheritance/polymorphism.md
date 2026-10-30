# Polymorphism in C++: Compile-Time vs. Run-Time Polymorphism

## 1. Executive Summary & Overview
Polymorphism—derived from the Greek words *poly* (many) and *morph* (form)—is a fundamental pillar of Object-Oriented Programming (OOP) in C++. It allows a single interface, function name, or operator to exhibit different behaviors depending on the context or the data types/objects it operates upon. 

In C++, polymorphism is broadly divided into two categories based on when the function binding occurs:
1. **Compile-Time Polymorphism (Static / Early Binding)**
2. **Run-Time Polymorphism (Dynamic / Late Binding)**

---

## 2. Compile-Time Polymorphism (Static Binding)

In compile-time polymorphism, the compiler resolves which specific function or operator overload to execute during program compilation based on function signatures, argument types, and counts. Because the function address is bound at compile time, static binding incurs **zero runtime performance overhead**.

### 2.1 Function Overloading
Function overloading allows multiple functions within the same scope to share the exact same name, provided they have distinct parameter lists (different number of parameters, different data types, or a different sequence of types).

* **Mechanism**: The C++ compiler uses **Name Mangling** (decorating function names with encoding for argument types) to differentiate overloaded functions at the binary level.
* **Rules**: Functions cannot be overloaded based solely on differences in return type.

### 2.2 Operator Overloading
Operator overloading enables C++ developers to redefine the behavior of built-in operators (such as `+`, `-`, `*`, `<<`, `==`) for custom user-defined data types (classes and structs).

* **Syntax**:
  ```cpp
  ReturnType operator OP_SYMBOL (const ClassName& rhs) const { ... }
  ```
* **Key Principles**: Operator overloading enhances code readability and enables custom objects to participate naturally in mathematical or logical expressions. Operators like `::`, `.`, `.*`, and `sizeof` cannot be overloaded.

---

## 3. Run-Time Polymorphism (Dynamic Binding)

Run-time polymorphism occurs when the decision of which function to call is deferred until program execution. It allows a Base Class pointer or reference to point to a Derived Class object and invoke the derived implementation of a function dynamically.

### 3.1 Key Prerequisites for Run-Time Polymorphism
To achieve dynamic binding in C++, three conditions must be satisfied:
1. **Inheritance Relationship**: A public inheritance hierarchy must exist between a base class and one or more derived classes.
2. **Virtual Functions**: The function in the base class must be declared with the `virtual` keyword and overridden in derived classes.
3. **Base Class Pointer / Reference**: The overridden function must be invoked through a base class pointer (`Base*`) or reference (`Base&`).

### 3.2 The Mechanics: `vtable` and `vptr`
Run-time polymorphism in C++ is underpinned by two internal compiler structures:

1. **Virtual Method Table (`vtable`)**:
   * A static, per-class lookup table created by the compiler for any class containing at least one virtual function.
   * Stores pointers to the virtual functions corresponding to that specific class.
2. **Virtual Pointer (`vptr`)**:
   * A hidden pointer member automatically inserted by the compiler into every object instance of a class with virtual functions.
   * Upon object construction, the `vptr` is initialized to point to the `vtable` of that specific object's class.

**Execution Flow**: When calling `ptr->virtualMethod()`, the runtime follows `ptr` $\rightarrow$ reads `vptr` $\rightarrow$ looks up the function index in `vtable` $\rightarrow$ jumps to the target method address.

### 3.3 Pure Virtual Functions & Abstract Classes
A function declared as `virtual void method() = 0;` is a **pure virtual function**. A class containing at least one pure virtual function becomes an **Abstract Class** and cannot be instantiated directly. It serves as a strict interface that derived classes must implement.

### 3.4 Virtual Destructors: Essential Memory Safety
When deleting a derived class object through a base class pointer (`Base* ptr = new Derived(); delete ptr;`), if the base class destructor is **not virtual**, only the base class destructor executes. This leads to **undefined behavior** and **memory leaks** because derived resources are never cleaned up.

* **Rule**: Always declare base class destructors as `virtual` in polymorphic hierarchies:
  ```cpp
  virtual ~BaseClass() = default;
  ```

---

## 4. Comparison Table: Compile-Time vs. Run-Time Polymorphism

| Feature / Metric | Compile-Time Polymorphism | Run-Time Polymorphism |
| :--- | :--- | :--- |
| **Binding Mechanism** | Static / Early Binding | Dynamic / Late Binding |
| **Resolution Time** | During Compilation | During Program Execution |
| **Key Features** | Function Overloading, Operator Overloading | Virtual Functions, Base Pointers, Overriding |
| **Performance** | Faster (no lookup overhead) | Minor overhead (vptr indirection & vtable lookup) |
| **Flexibility** | Less flexible; bound at build time | Highly flexible; adaptable at runtime |
| **Memory Footprint** | No extra pointer per object | Extra `vptr` per object instance + per-class `vtable` |
