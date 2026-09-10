// A program that writes a multiplication table of numbers from 0 to 9.

import std;
using namespace std;

int main()
{
    // Print the number title
    cout << "\t\tMultiplication Table\n";

    printf("%5c", '|'); 
    // cout << flush;
    for (int i = 1; i < 10; ++i)
    {
        printf("%4d", i);
        // printf("\n");
        // cout << flush;
    }

    // Jump to new line
    printf("\n");
    printf("——————————————————————————————————————————\n");

    // Display body
    for (int i = 1; i < 10; ++i)
    {
        printf("%4d|", i);
        for (int j = 1; j < 10; ++j)
        {
            // Display the product of i and j with a width of 4 characters
            printf("%4d", i * j);
        }
        // Jump to new line
        printf("\n");
    }

}