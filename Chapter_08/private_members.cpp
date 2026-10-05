#include <iostream>

class Date
{

private:
    // These are privste
    int y, m, d; // year, month, day

public:
    // Constructor
    Date(int y, int m, int d)
        : y{y}, m{m}, d{d}
    {
    }

    // increase date
    void add_day(int n)
    {
        d += n;
    }

    // Access the month
    int month()
    {
        return m;
    }

    // Access the day
    int day()
    {
        return d;
    }

    // Access the year
    int year()
    {
        return y;
    }
};

int main()
{
    Date today{2026, 10, 1};

    std::cout << "Year: " << today.year() << '\n';
    std::cout << "Month: " << today.month() << '\n';
    std::cout << "Day: " << today.day() << '\n';

    today.add_day(5);

    std::cout << "After adding 5 days:\n";
    std::cout << today.year() << "/"
              << today.month() << "/"
              << today.day() << '\n';

    return 0;
}