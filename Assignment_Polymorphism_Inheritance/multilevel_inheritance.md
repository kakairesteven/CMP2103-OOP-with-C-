# Multi-Level Inheritance in C++

## 1. Introduction to Multi-Level Inheritance
In C++, **Multi-Level Inheritance** is a mechanism where a class is derived from another derived class, forming a linear, multi-tiered inheritance hierarchy. Unlike multiple inheritance (where a single class inherits directly from multiple base classes), multi-level inheritance extends functionality step-by-step down a chain.

```
+-------------------+
|    Base Class     |  (Level 1: e.g., Person)
+-------------------+
          |
          v
+-------------------+
| Intermediate Class|  (Level 2: e.g., Employee)
+-------------------+
          |
          v
+-------------------+
|   Derived Class   |  (Level 3: e.g., Manager)
+-------------------+
```

---

## 2. Key Characteristics & Mechanics

### 2.1 Transitive Inheritance Property
Multi-level inheritance exhibits a **transitive property**. If Class $C$ inherits from Class $B$, and Class $B$ inherits from Class $A$:
* Class $C$ implicitly inherits all accessible attributes and methods of Class $A$ through Class $B$.
* Class $C$ possesses the combined capabilities of $A$, $B$, and its own unique extensions.

### 2.2 Access Specifier Propagation Across Tiers
The visibility of inherited members down the multi-level chain depends on the access specifiers used at each derivation level:

| Member Access in Base | Derivation Mode (`public`) | Access in Intermediate Class | Derivation Mode (`public`) | Access in Lowest Derived Class |
| :--- | :--- | :--- | :--- | :--- |
| `public` | `public` | `public` | `public` | `public` |
| `protected` | `public` | `protected` | `public` | `protected` |
| `private` | `public` | Inaccessible directly | `public` | Inaccessible directly |

* **Protected Access (`protected`)**: Members declared as `protected` in the base class are accessible inside member functions of intermediate and derived classes, but remain hidden from external main code.
* **Private Access (`private`)**: Members declared as `private` in any class remain strictly encapsulated within that class and cannot be accessed directly by derived tiers.

---

## 3. Constructor and Destructor Execution Mechanics

Understanding the invocation sequence of constructors and destructors across a multi-tier hierarchy is critical for proper resource management.

### 3.1 Order of Construction (Top-Down Execution)
When an object of the lowest derived class (e.g., `Manager`) is instantiated:
1. Memory is allocated for the entire object layout.
2. The **Base Class Constructor** (`Person`) executes first to initialize fundamental state.
3. The **Intermediate Class Constructor** (`Employee`) executes second.
4. The **Lowest Derived Class Constructor** (`Manager`) executes last.

> **Constructor Chaining**: Each derived class passes necessary initialization parameters up to its immediate parent class using the **Member Initializer List**:
> ```cpp
> Manager(string n, int id, int size) : Employee(n, id), teamSize(size) {}
> ```

### 3.2 Order of Destruction (Bottom-Up Execution)
When a multi-level object goes out of scope or is deleted:
1. The **Lowest Derived Class Destructor** (`~Manager`) executes first to clean up local resources.
2. The **Intermediate Class Destructor** (`~Employee`) executes second.
3. The **Base Class Destructor** (`~Person`) executes last.

This reverse order guarantees that derived layers do not access base resources that have already been deallocated.

---

## 4. Method Overriding and Scope Resolution

Any class in a multi-level chain can override virtual methods defined by its predecessors.
* If the lowest derived class overrides a method, calling that method invokes the lowest version.
* If the lowest derived class needs to access a parent or grandparent implementation, it uses the **Scope Resolution Operator (`::`)**:
  ```cpp
  void Manager::displayDetails() {
      Employee::displayDetails(); // Calls intermediate parent method
      std::cout << "Team Size: " << teamSize << std::endl;
  }
  ```

---

## 5. Software Engineering Best Practices
1. **Limit Chain Depth**: Keep inheritance hierarchies relatively shallow (typically 2–3 levels) to avoid high coupling and fragile base class bugs.
2. **Favor Preferential Public Derivation**: Use `public` derivation for true "is-a" relationships across all levels.
3. **Use `virtual` Destructors**: Always declare the top-level base class destructor as `virtual`.
