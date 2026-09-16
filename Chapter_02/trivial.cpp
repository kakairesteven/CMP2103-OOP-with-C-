// Write a program that doesn’t do anything, but declares a number of variables
// with legal and illegal names (such as int double = 0;),
// so that you can see how the compiler reacts.

#include <iostream>
using namespace std;

int main() {
    int number = 10;
    int totalScore = 25;
    int _value = 7;
    int value2 = 3;

    // Uncomment one illegal declaration at a time to see the compiler error:
    // int double = 0;
    // int 2ndNumber = 5;
    // int my-name = 8;
    // int class = 9;

    cout << "Valid names: " << number << ", " << totalScore << ", " << _value << ", " << value2 << endl;

    return 0;
}