#include <iostream>

enum class Month
{
    jan = 1,
    feb,
    mar,
    apr,
    may,
    jun,
    jul,
    aug,
    sep,
    oct,
    nov,
    dec
};

int to_int(Month m)
{
    return static_cast<int>(m);
}

Month operator++(Month& m)
{
    m = (m == Month::dec)
        ? Month::jan
        : Month{to_int(m) + 1};

    return m;
}

int main()
{
    Month m = Month::nov;

    ++m;

    std::cout << to_int(m) << '\n';  // 12

    ++m;

    std::cout << to_int(m) << '\n';  // 1
}