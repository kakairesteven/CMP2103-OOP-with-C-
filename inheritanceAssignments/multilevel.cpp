
#include <iostream>
#include <string>
using namespace std;

// Base class
class Person
{
public:
    string name;
    int age;

    void displayPerson()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Derived class
class Lecturer : public Person
{
public:
    string subject;

    void displayLecturer()
    {
        cout << "Subject Taught: " << subject << endl;
    }
};

// Further derived class
class SeniorLecturer : public Lecturer
{
public:
    int yearsOfExperience;

    void displaySeniorLecturer()
    {
        cout << "Years of Experience: "
             << yearsOfExperience << endl;
    }
};

int main()
{
    SeniorLecturer s;

    // Inherited from Person
    s.name = "Sarah";
    s.age = 40;

    // Defined in Lecturer
    s.subject = "Computer Science";

    // Defined in SeniorLecturer
    s.yearsOfExperience = 15;

    cout << "SENIOR LECTURER DETAILS" << endl;

    s.displayPerson();
    s.displayLecturer();
    s.displaySeniorLecturer();

    return 0;
}
