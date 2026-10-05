#include <iostream>

using Year = int;
using Month = int;

class Date
{
public:
    // Constructor
    Date(Year y, Month m, int d)
        : y{y}, m{m}, d{d}
    {
    }

    // const members: cannot modify the Date object
    int day() const
    {
        return d;
    }

    Month month() const
    {
        return m;
    }

    Year year() const
    {
        return y;
    }

    // Non-const members: can modify the Date object
    void add_day(int n)
    {
        d += n;
    }

    void add_month(int n)
    {
        m += n;
    }

    void add_year(int n)
    {
        y += n;
    }

private:
    Year y;
    Month m;
    int d;
};

int main()
{
    Date today{2026, 10, 1};

    std::cout << "Date: "
              << today.year() << "/"
              << today.month() << "/"
              << today.day() << '\n';

    today.add_day(5);
    today.add_month(1);
    today.add_year(1);

    std::cout << "New date: "
              << today.year() << "/"
              << today.month() << "/"
              << today.day() << '\n';

    return 0;
}