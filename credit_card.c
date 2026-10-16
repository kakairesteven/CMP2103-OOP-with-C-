#include <stdio.h>
#include <stdbool.h>

// Function prototypes
bool isValid(long long number);
int sumOfDoubleEvenPlace(long long number);
int getDigit(int number);
int sumOfOddPlace(long long number);
bool prefixMatched(long long number, int d);
int getSize(long long d);
long long getPrefix(long long number, int k);

int main() {
    long long cardNumber;

    printf("Enter a credit card number as an integer: ");
    scanf("%lld", &cardNumber);

    if (isValid(cardNumber)) {
        printf("%lld is valid.\n", cardNumber);
    } else {
        printf("%lld is invalid.\n", cardNumber);
    }

    return 0;
}

// Return true if the card number is valid
bool isValid(long long number) {
    int size = getSize(number);

    // Check length constraint (between 13 and 16 digits)
    if (size < 13 || size > 16) {
        return false;
    }

    // Check starting prefix
    if (!prefixMatched(number, 4) &&
        !prefixMatched(number, 5) &&
        !prefixMatched(number, 37) &&
        !prefixMatched(number, 6)) {
        return false;
    }

    // Apply the Mod 10 Luhn check
    int totalSum = sumOfDoubleEvenPlace(number)
                + sumOfOddPlace(number);

    return (totalSum % 10 == 0);
}

// Sum of doubled digits in even places from right to left
int sumOfDoubleEvenPlace(long long number) {
    int sum = 0;

    // Remove the rightmost digit
    number /= 10;

    while (number > 0) {
        int lastDigit = number % 10;

        // Double the digit and get the sum of its digits
        sum += getDigit(lastDigit * 2);

        // Move two positions to the left
        number /= 100;
    }

    return sum;
}

// Return the number if it is a single digit.
// Otherwise, return the sum of its two digits.
int getDigit(int number) {
    if (number < 10) {
        return number;
    }

    return (number / 10) + (number % 10);
}

// Return the sum of odd-place digits from right to left
int sumOfOddPlace(long long number) {
    int sum = 0;

    while (number > 0) {
        sum += number % 10;

        // Move two positions to the left
        number /= 100;
    }

    return sum;
}

// Return true if digit d is a prefix for number
bool prefixMatched(long long number, int d) {
    int dSize = getSize(d);

    return getPrefix(number, dSize) == d;
}

// Return the number of digits in d
int getSize(long long d) {
    int count = 0;

    if (d == 0) {
        return 1;
    }

    while (d > 0) {
        count++;
        d /= 10;
    }

    return count;
}

// Return the first k digits from number
long long getPrefix(long long number, int k) {
    int size = getSize(number);

    // If number has fewer or equal digits than k
    if (size <= k) {
        return number;
    }

    // Remove digits from the right
    long long divisor = 1;

    for (int i = 0; i < size - k; i++) {
        divisor *= 10;
    }

    return number / divisor;
}