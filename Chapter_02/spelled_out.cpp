// Write a program that converts spelled-out numbers such as ‘‘zero’’ and ‘‘two’’ into digits, such as 0 and 2. When the user inputs a number, the program should print out the corresponding
// digit. Do it for the values 0, 1, 2, 3, and 4 and write out not a number I know if the user enters something that doesn’t correspond, such as stupid computer!.

#include <iostream>
#include <string>
using namespace std;

int main() {
    string word;

    cout << "Enter a number in words (zero, one, two, three, four): ";
    cin >> word;

    if (word == "zero") {
        cout << "0" << endl;
    } else if (word == "one") {
        cout << "1" << endl;
    } else if (word == "two") {
        cout << "2" << endl;
    } else if (word == "three") {
        cout << "3" << endl;
    } else if (word == "four") {
        cout << "4" << endl;
    } else {
        cout << "Not a number I know" << endl;
    }

    return 0;
}


