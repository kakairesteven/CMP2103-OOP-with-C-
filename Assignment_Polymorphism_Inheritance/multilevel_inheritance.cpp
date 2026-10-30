/**
 * @file multilevel_inheritance.cpp
 * @brief Demonstration of Multi-Level Inheritance Mechanics in C++
 * @course CMP2103 - Object-Oriented Programming with C++
 */

#include <iostream>
#include <string>

// ============================================================================
// LEVEL 1: BASE CLASS (Person)
// ============================================================================
class Person {
protected:
    std::string fullName;
    int age;

public:
    // Base Class Constructor
    Person(const std::string& name, int a) : fullName(name), age(a) {
        std::cout << "  [1. Person Constructor] Initializing base person: " << fullName << std::endl;
    }

    // Base Method
    virtual void displayDetails() const {
        std::cout << "Name: " << fullName << " | Age: " << age << std::endl;
    }

    // Virtual Base Destructor
    virtual ~Person() {
        std::cout << "  [1. Person Destructor] Destroying base person: " << fullName << std::endl;
    }
};

// ============================================================================
// LEVEL 2: INTERMEDIATE DERIVED CLASS (Employee)
// Inherits from Person (Multi-Level Step 1)
// ============================================================================
class Employee : public Person {
protected:
    int employeeID;
    std::string department;

public:
    // Intermediate Constructor: Explicitly passes arguments to Person constructor
    Employee(const std::string& name, int a, int id, const std::string& dept)
        : Person(name, a), employeeID(id), department(dept) {
        std::cout << "  [2. Employee Constructor] Initializing employee ID: " << employeeID << std::endl;
    }

    // Overriding Base Method & Extending Functionality
    void displayDetails() const override {
        // Accessing inherited protected members (fullName, age) from Person
        std::cout << "ID: " << employeeID << " | Name: " << fullName 
                  << " | Age: " << age << " | Dept: " << department << std::endl;
    }

    // Intermediate Destructor
    ~Employee() override {
        std::cout << "  [2. Employee Destructor] Destroying employee ID: " << employeeID << std::endl;
    }
};

// ============================================================================
// LEVEL 3: LOWEST DERIVED CLASS (Manager)
// Inherits from Employee (Multi-Level Step 2: Person -> Employee -> Manager)
// ============================================================================
class Manager : public Employee {
private:
    int teamSize;
    double projectBudget;

public:
    // Lowest Derived Constructor: Passes arguments up to Employee constructor
    Manager(const std::string& name, int a, int id, const std::string& dept, int tSize, double budget)
        : Employee(name, a, id, dept), teamSize(tSize), projectBudget(budget) {
        std::cout << "  [3. Manager Constructor] Initializing manager team size: " << teamSize << std::endl;
    }

    // Overriding Method across the multi-level hierarchy
    void displayDetails() const override {
        // Accessing inherited protected members cascaded from Level 1 and Level 2
        std::cout << "=== MANAGER PROFILE ===\n";
        std::cout << "Manager Name:   " << fullName << " (Inherited from Person)\n";
        std::cout << "Manager Age:    " << age << " (Inherited from Person)\n";
        std::cout << "Employee ID:    " << employeeID << " (Inherited from Employee)\n";
        std::cout << "Department:     " << department << " (Inherited from Employee)\n";
        std::cout << "Team Size:      " << teamSize << " Managed Engineers\n";
        std::cout << "Project Budget: $" << projectBudget << "\n";
    }

    // Demonstration of calling Intermediate Class method explicitly
    void displayParentSummary() const {
        std::cout << "\n--- Explicit Parent Summary Call (Employee::displayDetails) ---\n";
        Employee::displayDetails(); // Calls Level 2 implementation
    }

    // Lowest Derived Destructor
    ~Manager() override {
        std::cout << "  [3. Manager Destructor] Destroying manager specific data for " << fullName << std::endl;
    }
};


// ============================================================================
// MAIN EXECUTION ROUTINE
// ============================================================================
int main() {
    std::cout << "========================================================\n";
    std::cout << "   CMP2103: MULTI-LEVEL INHERITANCE DEMONSTRATION IN C++\n";
    std::cout << "========================================================\n\n";

    std::cout << "--- Step 1: Instantiating Manager Object (Person -> Employee -> Manager) ---\n";
    std::cout << "Executing Constructors (Top-Down Order):\n";
    
    // Instantiating object at lowest tier
    Manager mgr("Arthur Kadama", 28, 10842, "Software Engineering", 8, 250000.0);

    std::cout << "\n--- Step 2: Demonstrating Cascading Properties & Overridden Methods ---\n";
    mgr.displayDetails();

    std::cout << "\n--- Step 3: Demonstrating Scope Resolution to Access Intermediate Method ---\n";
    mgr.displayParentSummary();

    std::cout << "\n--- Step 4: Object Scope Destruction ---\n";
    std::cout << "Executing Destructors (Bottom-Up Order):\n";
    // Object 'mgr' goes out of scope here at end of main

    return 0; // Triggers destructor chain
}
