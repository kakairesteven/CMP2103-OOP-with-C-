// Convert numbers to their ASCII character equivalence.
// Examples
// Uppercase:
// 65 = A
// 66 = B
// 67 = C
// 68 = D
// 69 = E

// Lowercase:
// 97 = a
// 98 = b
// 99 = c
// 100 = d
// 101 = e

// Special characters:
// 33 = !
// 34 = "
// 35 = #
// 36 = $
// 37 = %
#include <iostream>
using namespace std;

int main()
{
    double d = 0;
    while (std::cin >> d)
    {                                   // repeat the statements below as long as we type in numbers
        int i = d;                      // try to squeeze a floating-point value into an integer value
        char c = i;                     // try to squeeze an integer into a char
        std::cout << "d==" << d         // the original double
             << " i==" << i             // double converted to int
             << " c==" << c             // int value of char
             << " char(" << c << ")\n"; // the char
    }
}

// Try
// Write a program that converts numerical stings to integers. For example '12040' to 12040.
// Application: Type conversions in data processing systems. For example, converting NaN (Not A Number) values to other valid values.
// Precision downcasting: 2026.00 to 2026