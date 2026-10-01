#include <iostream>
using namespace std;

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
    cout << "Enter a credit card number: ";
    cin >> number;

    if (isValid(number))
        cout << number << " is valid." << endl;
    else
        cout << number << " is invalid." << endl;

    return 0;
}

bool isValid(long long number)
{
    int size = getSize(number);

    if (size < 13 || size > 16)
        return false;

    if (!(prefixMatched(number, 4) ||
          prefixMatched(number, 5) ||
          prefixMatched(number, 6) ||
          prefixMatched(number, 37)))
        return false;

    return (sumOfDoubleEvenPlace(number) + sumOfOddPlace(number)) % 10 == 0;
}

int sumOfDoubleEvenPlace(long long number)
{
    int sum = 0;
    number /= 10;

    while (number > 0)
    {
        sum += getDigit((number % 10) * 2);
        number /= 100;
    }

    return sum;
}

int getDigit(int number)
{
    if (number < 10)
        return number;
    return (number / 10) + (number % 10);
}

int sumOfOddPlace(long long number)
{
    int sum = 0;

    while (number > 0)
    {
        sum += number % 10;
        number /= 100;
    }

    return sum;
}

bool prefixMatched(long long number, int d)
{
    return getPrefix(number, getSize(d)) == d;
}

int getSize(long long d)
{
    int count = 0;

    while (d > 0)
    {
        count++;
        d /= 10;
    }

    return count;
}

long long getPrefix(long long number, int k)
{
    int size = getSize(number);

    while (size > k)
    {
        number /= 10;
        size--;
    }

    return number;
}
