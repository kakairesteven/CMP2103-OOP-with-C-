
#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;

public:
    void setName(string n)
    {
        name = n;
    }

    void displayName()
    {
        cout << "Name: " << name << endl;
    }
};

class Student : public Person
{
protected:
    int regNo;

public:
    void setRegNo(int r)
    {
        regNo = r;
    }

    void displayRegNo()
    {
        cout << "Registration Number: " << regNo << endl;
    }
};

class UniversityStudent : public Student
{
private:
    string course;

public:
    void setCourse(string c)
    {
        course = c;
    }

    void displayDetails()
    {
        displayName();
        displayRegNo();
        cout << "Course: " << course << endl;
    }
};

int main()
{
    UniversityStudent s;

    s.setName("John");
    s.setRegNo(1234);
    s.setCourse("Computer Science");

    s.displayDetails();

    return 0;
}
