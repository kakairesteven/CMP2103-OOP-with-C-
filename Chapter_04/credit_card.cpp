#include <iostream>

using namespace std;

// Function Prototypes (as required by the assignment)
bool isValid(long long number);
int sumOfDoubleEvenPlace(long long number);
int getDigit(int number);
int sumOfOddPlace(long long number);
bool prefixMatched(long long number, int d);
int getSize(long long d);
long long getPrefix(long long number, int k);

int main() {
    long long cardNumber;
    
    cout << "Enter a credit card number as an integer: ";
    cin >> cardNumber;
    
    if (isValid(cardNumber)) {
        cout << cardNumber << " is valid" << endl;
    } else {
        cout << cardNumber << " is invalid" << endl;
    }
    
    return 0;
}

// Return true if the card number is valid
bool isValid(long long number) {
    int totalSize = getSize(number);
    
    // Check length constraint (between 13 and 16 digits)
    if (totalSize < 13 || totalSize > 16) {
        return false;
    }
    
    // Check valid prefixes: Visa (4), MasterCard (5), Amex (37), Discover (6)
    if (!prefixMatched(number, 4) && 
        !prefixMatched(number, 5) && 
        !prefixMatched(number, 37) && 
        !prefixMatched(number, 6)) {
        return false;
    }
    
    // Check the Luhn algorithm sum rule
    int totalSum = sumOfDoubleEvenPlace(number) + sumOfOddPlace(number);
    return (totalSum % 10 == 0);
}

// Get the result from Step 2 (Double every second digit from right to left)
int sumOfDoubleEvenPlace(long long number) {
    int sum = 0;
    number /= 10; // Shift right to start with the second digit from the right
    
    while (number > 0) {
        int lastDigit = number % 10;
        sum += getDigit(lastDigit * 2);
        number /= 100; // Jump two places to the left
    }
    return sum;
}

// Return this number if it is a single digit, otherwise, return the sum of the two digits
int getDigit(int number) {
    if (number < 10) {
        return number;
    }
    return (number % 10) + (number / 10);
}

// Return sum of odd place digits in number from right to left
int sumOfOddPlace(long long number) {
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 100; // Jump two places to the left
    }
    return sum;
}

// Return true if the digit d is a prefix for number
bool prefixMatched(long long number, int d) {
    int prefixSize = getSize(d);
    return getPrefix(number, prefixSize) == d;
}

// Return the number of digits in d
int getSize(long long d) {
    int count = 0;
    if (d == 0) return 1;
    while (d > 0) {
        count++;
        d /= 10;
    }
    return count;
}

// Return the first k number of digits from number. 
// If the number of digits in number is less than k, return number.
long long getPrefix(long long number, int k) {
    int totalSize = getSize(number);
    if (totalSize < k) {
        return number;
    }
    
    int digitsToDrop = totalSize - k;
    for (int i = 0; i < digitsToDrop; i++) {
        number /= 10;
    }
    return number;
}
import std;
using namespace std;

import validate_credit_card;


int main()
{
    vector<int> number = readCardNumber();
    // cout << "Prefix: " << getPrefix(number, 3) << "\n";
    // cout << "Matched: " << prefixMatched(number) << "\n";
    // cout << "Size: " << getSize(number) << "\n";
    // cout << "Sum of Odd Numbers " << sumOfOddPlace(number) << "\n";
    // cout << "Sum of double even numbers: " << sumOfDoubleEvenPlace(number) << "\n";
    cout << "Valid: " << isValid(number) << "\n";
    return 0;
}

// Valid examples
// 4242424242424242
