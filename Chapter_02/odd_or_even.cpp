// Write a program to test an integer value to determine if it is odd or even.
// As always, make sure your output is clear and complete. In other words, don’t just output yes or no.
// Your output should stand alone, like The value 4 is an even number.






#include <iostream>

using namespace std;

int main() {
    int number;

    // Prompting user for the input
    cout << "\n Enter an integer value: ";
    if (!(cin >> number)) {
        cout << "Invalid input! Please enter a valid integer. \n" << endl;
        return 1;
    }

    // Determining if the number is divisible by 2 or not and printing the result
    if (number % 2 == 0) {
        cout << "The value " << number << " is an even number. \n" << endl;
    } else {
        cout << "The value " << number << " is an odd number. \n" << endl;
    }

    return 0;
}