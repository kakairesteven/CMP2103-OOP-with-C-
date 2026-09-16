// Write a program in C++ that converts from miles to kilometers.
// Your program should have a reasonable prompt for the user to enter a number of miles.
// Hint: A mile is 1.609 kilometers.
#include <iostream>
using namespace std;

int main() {
    double miles;
    cout << "Please enter the number of miles: ";
    cin >> miles;
    double kilometers = miles * 1.609;
    cout << "The equivalent in kilometers is: " << kilometers << endl;
    return 0;
}