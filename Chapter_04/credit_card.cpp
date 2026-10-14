<<<<<<< HEAD
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
=======
#include <iostream>

bool isValid(long long number);
int sumOfDoubleEvenPlace(long long number);
int getDigit(int number);
int sumOfOddPlace(long long number);
bool prefixMatched(long long number, int d);
int getSize(long long d);
long long getPrefix(long long number, int k);

int main()
{
    long long number;
    std::cout << "Enter a credit card number: ";
    std::cin >> number;

    std::cout << number << (isValid(number) ? " is valid" : " is invalid") << '\n';
}

bool isValid(long long number)
{
    const int size = getSize(number);
    const bool validPrefix = prefixMatched(number, 4) ||
                             prefixMatched(number, 5) ||
                             prefixMatched(number, 6) ||
                             prefixMatched(number, 37);

    return size >= 13 && size <= 16 && validPrefix &&
           (sumOfDoubleEvenPlace(number) + sumOfOddPlace(number)) % 10 == 0;
}

int sumOfDoubleEvenPlace(long long number)
{
    int sum = 0;
    bool doubleDigit = false;

    while (number > 0)
    {
        const int digit = static_cast<int>(number % 10);
        number /= 10;

        if (doubleDigit)
            sum += getDigit(digit * 2);

        doubleDigit = !doubleDigit;
    }

    return sum;
}

int getDigit(int number)
{
    return number < 10 ? number : number / 10 + number % 10;
}

int sumOfOddPlace(long long number)
{
    int sum = 0;
    bool oddPlace = true;

    while (number > 0)
    {
        if (oddPlace)
            sum += static_cast<int>(number % 10);

        number /= 10;
        oddPlace = !oddPlace;
    }

    return sum;
}

bool prefixMatched(long long number, int d)
{
    return getPrefix(number, getSize(d)) == d;
}

int getSize(long long d)
{
    int size = 0;

    do
    {
        d /= 10;
        ++size;
    } while (d != 0);

    return size;
}

long long getPrefix(long long number, int k)
{
    int size = getSize(number);

    while (k < size)
    {
        number /= 10;
        --size;
    }

    return number;
}
>>>>>>> main
