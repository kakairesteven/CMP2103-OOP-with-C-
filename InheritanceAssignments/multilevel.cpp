#include <iostream>
#include <string>
using namespace std;

// Base class
class Employee
{
public:
    string name;
    double salary;

    void displayEmployee()
    {
        cout << "Employee Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }
};

// Derived class
class Manager : public Employee
{
public:
    string department;

    void displayManager()
    {
        cout << "Department: " << department << endl;
    }
};

// Further derived class
class DepartmentManager : public Manager
{
public:
    int departmentsSupervised;

    void displayDepartmentManager()
    {
        cout << "Departments Supervised: "
             << departmentsSupervised << endl;
    }
};

int main()
{
    DepartmentManager dm;

    // Members inherited from Employee
    dm.name = "Joan";
    dm.salary = 3000;

    // Member defined in Manager
    dm.department = "Engineering";

    // Member defined in DepartmentManager
    dm.departmentsSupervised = 3;

    cout << "DEPARTMENT MANAGER DETAILS" << endl;

    dm.displayEmployee();
    dm.displayManager();
    dm.displayDepartmentManager();

    return 0;
}
