module;

export module validate_credit_card;

import std;
using namespace std;

// Function declarations
export bool isValid(vector<int> number);
export int sumOfDoubleEvenPlace(vector<int> number);
export int getDigit(int number);
export int sumOfOddPlace(vector<int> number);
export int getSize(vector<int> number);
export bool prefixMatched(vector<int> number);
export vector<int> readCardNumber();
export int getPrefix(vector<int> number, int k);

// Return true if sum of (sum of doubles) and (sum of odds) is divisible by 10 and prefixMatch is true
export bool isValid(vector<int> number)
{
    if (((sumOfDoubleEvenPlace(number) + sumOfOddPlace(number)) % 10 == 0) && prefixMatched(number) && 13 <= getSize(number) && getSize(number) <= 16)
    {
        return true;
    }
    else
    {
        return false;
    }
}

export int sumOfDoubleEvenPlace(vector<int> number)
{
    int sum = 0;
    // Start at position, i = number.size() - 1 and decrement through with steps of 2
    for (int i = number.size() - 1; i >= 0; i -= 2)
    {
        int digit = number[i];
        // Double even number
        digit = digit * 2;
        sum += getDigit(digit);
    }
    return sum;
}

// Return this number if it is a single digit, otherwise, return the sum of the two digits
export int getDigit(int number)
{
    if (number < 10)
    {
        return number;
    }
    else
    {
        return number / 10 + number % 10;
    }
}

//Return sum of odd place digits in number\
int sumOfOddPlace(long long number);
export int sumOfOddPlace(vector<int> number)
{
    int sum = 0;
    for (int i = number.size() - 1; i >= 0; i -= 1)
    {
        sum += number[i];
    }
    return sum;
}

//Return the number of digits in d\
int getSize(long long d);
export int getSize(vector<int> number)
{
    return number.size();
}

//Return true if the digit d is a prefix for number\
bool prefixMatched(long long number, int d);
export bool prefixMatched(vector<int> number)
{
    if ((getPrefix(number, 1)) == 4 || (getPrefix(number, 1)) == 5 || (getPrefix(number, 2)) == 37 || (getPrefix(number, 1)) == 6)
    {
        return true;
    }

    else
    {
        return false;
    }
}

export vector<int> readCardNumber()
{
    std::string number;

    std::cout << "Enter number: \n";
    std::cin >> number;

    std::vector<int> card_digits;
    for (int i = 0; i < number.size(); ++i)
    {
        // Convert char into an integer. Read about ASCII
        card_digits.push_back(number[i] - '0');
        // cout << number[i]<< "\n";
    }

    return card_digits;
}

//Return the first k number of digits from number. If the number of digits in number is less than k, return number.\
int getPrefix(std:vector<int> number, int k);
export int getPrefix(std::vector<int> number, int k)
{
    int k_prefix = 0;

    int length = number.size();

    for (int i = 0; i < k; i++)
    {
        k_prefix = k_prefix * 10 + number[i];
    }

    return k_prefix;
}