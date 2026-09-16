// A program that writes a multiplication table of numbers from 0 to 9.

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // Print the number title
    cout << "\t\tMultiplication Table\n";

    cout << setw(5) << '|';
    for (int i = 1; i < 10; ++i)
    {
        cout << setw(4) << i;
    }

    // Jump to new line
    cout << endl;
    cout << "——————————————————————————————————————————\n";

    // Display body
    for (int i = 1; i < 10; ++i)
    {
        cout << setw(4) << i << "|";
        for (int j = 1; j < 10; ++j)
        {
            // Display the product of i and j with a width of 4 characters
            cout << setw(4) << i * j;
        }
        // Jump to new line
        cout << endl;
    }

}