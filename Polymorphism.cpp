
#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void sound()
    {
        cout << "Animal makes a sound" << endl;
    }

    virtual ~Animal() = default;
};

class Dog : public Animal
{
public:
    void sound() override
    {
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal
{
public:
    void sound() override
    {
        cout << "Cat meows" << endl;
    }
};

int main()
{
    Dog d;
    Cat c;

    Animal* ptr;

    ptr = &d;
    ptr->sound();

    ptr = &c;
    ptr->sound();

    return 0;
}
