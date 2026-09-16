// Given two inter values, the programs finds out if a number is less, equal or greater than the second number

#include <iostream>
using namespace std;

int main()
{
    int a = 0;
    int b = 0;
    cout << "Please enter two integers\n";
    cin >> a >> b;
    if (a < b) // condition
        // 1st alternative (if condition is true)
        cout << a << " is less than " << b << endl;

    else if (a > b)
        // 2nd alternative (if condition is false)
        cout << a << " is greater than " << b << endl;
    else if (a == b)
        cout << a << " is equal to " << b << endl;
    else
        cout << "Invalid input" << endl;
}

// Try
// This program has a bug: it compares a string to an integer. Modify it so that comparisons are performed using integer values ONLY.
