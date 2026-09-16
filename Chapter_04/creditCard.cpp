#include <iostream>
#include <vector>
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
    cout << "Enter credit card number: ";
    cin >> number;

    if (isValid(number))
        cout << number << " is valid" << endl;
    else
        cout << number << " is invalid" << endl;

    return 0;
}
bool isValid(long long number)
{
    return (getSize(number) >= 13 && getSize(number) <= 16) &&
           (prefixMatched(number, 4) || prefixMatched(number, 5) ||
            prefixMatched(number, 37) || prefixMatched(number, 6)) &&
           ((sumOfDoubleEvenPlace(number) + sumOfOddPlace(number)) % 10 == 0);
}
int sumOfDoubleEvenPlace(long long number)
{
    int sum = 0;
    bool isEvenPlace = false;

    while (number > 0)
    {
        int digit = number % 10;
        if (isEvenPlace)
        {
            sum += getDigit(digit * 2);
        }
        isEvenPlace = !isEvenPlace;
        number /= 10;
    }
    return sum;
}
int getDigit(int number)
{
    if (number < 10)
        return number;
    else
        return number / 10 + number % 10;
}
int sumOfOddPlace(long long number)
{
    int sum = 0;
    bool isEvenPlace = false;

    while (number > 0)
    {
        int digit = number % 10;
        if (!isEvenPlace)
        {
            sum += digit;
        }
        isEvenPlace = !isEvenPlace;
        number /= 10;
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
    while (d > 0)
    {
        size++;
        d /= 10;
    }
    return size;
}
long long getPrefix(long long number, int k)
{
    int size = getSize(number);
    if (size < k)
        return number;
    else
    {
        for (int i = 0; i < size - k; i++)
            number /= 10;
        return number;
    }
}