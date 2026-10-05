#include <iostream>
using namespace std;
// simple Date (many people prefer implementation details last)
class Date
{
public:
    Date(int y, int m, int d); // constructor: check for valid date and initialize

    void add_day(int n); // increase the Date by n days
    int month();
    void print() const;
    // ...

private:
    int y, m, d; // year, month, day
};

Date::Date(int yy, int mm, int dd) // constructor
    : y{yy}, m{mm}, d{dd}          // note: member initializers
{
}

void Date::add_day(int n)
{
    d += n;
}

int Date::month()
{
    return m; // not the member function, can’t access m
}

void Date::print() const
{
    cout << d << "/" << m << "/" << y << "\n";
}

int main()
{
    Date today{2026, 5, 5};
    today.add_day(5);
    today.print();
}