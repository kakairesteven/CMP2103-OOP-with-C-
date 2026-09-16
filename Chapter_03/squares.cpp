#include <iostream>
#include <iomanip>
#include <cmath>

int main()
// calculate and print a table of squares 0-99
{
    int i = 0; // start from 0
    while (i < 100)
    {
        std::cout << std::setw(4) << i << '\t' << std::setw(8) << std::sqrt(i) << '\n';
        ++i; // increment i (that is, i becomes i+1)
    }
}