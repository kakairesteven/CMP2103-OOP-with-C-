// (Math: approximate the square root) There are several techniques for implementing
// the sqrt function in the math module. One such technique is known as the
// Babylonian function. It approximates the square root of a number, n, by repeatedly
// performing a calculation using the following formula:
// nextGuess = (lastGuess + (n / lastGuess)) / 2
// When nextGuess and lastGuess are almost identical, nextGuess is the
// approximated square root. The initial guess can be any positive value (e.g., 1).
// This value will be the starting value for lastGuess. If the difference between
// nextGuess and lastGuess is less than a very small number, such as 0.0001,
// you can claim that nextGuess is the approximated square root of n. If not,
// nextGuess becomes lastGuess and the approximation process continues.
// Implement the a function that returns the square root of n usig the above technique.

#include <iostream>
#include <cmath>
using namespace std;

double babylonianSqrt(double n) {
    if (n < 0) {
        return -1;
    }

    double lastGuess = 1.0;
    double nextGuess = (lastGuess + (n / lastGuess)) / 2.0;

    while (fabs(nextGuess - lastGuess) > 0.0001) {
        lastGuess = nextGuess;
        nextGuess = (lastGuess + (n / lastGuess)) / 2.0;
    }

    return nextGuess;
}

int main() {
    double n;

    cout << "Enter a number: ";
    cin >> n;

    if (n < 0) {
        cout << "Square root is not defined for negative numbers." << endl;
    } else {
        cout << "Approximate square root: " << babylonianSqrt(n) << endl;
    }

    return 0;
}
