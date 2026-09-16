import std;
using namespace std;

// Read number into a vector
vector<int> readVardNumber();
int getPrefix(vector<int> number, int k);
bool prefixMatched(vector<int>);
// int getSize(vector<int> number);
// int sumOfOddPlace(vector<int> number);
// int getDigit(int number);
// int sumOfDoubleEvenPlace(vector<int> number);
// bool isValid(vector<int> number);

// Return true if sum of (sum of doubles) and (sum of odds) is divisible by 10 and prefixMatch is true
// bool isValid(vector<int> number)
// {
//     if (((sumOfDoubleEvenPlace(number) + sumOfOddPlace(number)) % 10 == 0) && prefixMatched(number) && 13 <= getSize(number) && getSize(number) <= 16)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// int sumOfDoubleEvenPlace(vector<int> number)
// {
//     int sum = 0;
//     // Start at position, i = 0 and incrment through with steps of 2
//     for (int i = 0; i < number.size() - 1; i += 2)
//     {
//         int digit = number[i];
//         // Double even number
//         digit = digit * 2;

//         // // if it is a double digit
//         // if (digit >= 10)
//         // {
//         //     digit = digit / 10 + digit % 10;
//         // }

//         // else
//         // {
//         //     // Pass
//         // }
//         sum += getDigit(digit);
//     }
//     return sum;
// }

// // Return this number if it is a single digit, otherwise, return the sum of the two digits
// int getDigit(int number)
// {
//     if (number < 10)
//     {
//         return number;
//     }
//     else
//     {
//         return number / 10 + number % 10;
//     }
// }

//Return sum of odd place digits in number\
int sumOfOddPlace(long long number);
// int sumOfOddPlace(vector<int> number)
// {
//     int sum = 0;
//     for (int i = 0; i < number.size(); i += 2)
//     {
//         sum += number[i];
//     }
//     return sum;
// }

//Return the number of digits in d\
int getSize(long long d);
int getSize(vector<int> number)
{
    return number.size();
}

//Return true if the digit d is a prefix for number\
bool prefixMatched(long long number, int d);
bool prefixMatched(vector<int> number)
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

vector<int> readCardNumber()
{
    std::string number;

    // '34567890'
    // 'thfjhdjkfkf'

    std::cout << "Enter number: \n";
    std::cin >> number;

    std::vector<int> card_digits;

    // for (char digit : number)
    // {
    //     card_digits.push_back(digit - '0');
    // }
    for (int i = 0; i < number.size(); ++i){
        // Convert number into an integer
        card_digits.push_back(number[i] - '0');
        // cout << number[i]<< "\n";
    }


    return card_digits;
}

//Return the first k number of digits from number. If the number of digits in number is less than k, return number.\
int getPrefix(std:vector<int> number, int k);
int getPrefix(std::vector<int> number, int k)
{
    int k_prefix = 0;

    int length = number.size();

    for (int i = 0; i < k; i++)
    {
        k_prefix = k_prefix * 10 + number[i];
    }

    return k_prefix;
}

int main()
{
    vector<int> number = readCardNumber();
    cout << "Prefix: " << getPrefix(number, 3) << "\n";
    cout << "Matched: " << prefixMatched(number) << "\n";
    // cout << "Size: " << getSize(number) << "\n";
    // cout << "Sum of Odd Numbers " << sumOfOddPlace(number) << "\n";
    // // cout << "Single number: " << getDigit(number) << "\n";
    // cout << "Sum of double even numbers: " << sumOfDoubleEvenPlace(number) << "\n";
    // cout << "Valid: " << isValid(number) << "\n";
    // for (int i = 0; i < number.size(); ++i){
    //     cout << number[i] << "\n";
    
    // }
    return 0;
}

// Valid examples
// 4242424242424242



#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string card;
    cout << "Enter card number: ";
    cin >> card;

    // 1. Calculate length (Size)
    int size = card.length();

    // 2. Extract Prefix (first 3 digits safely)
    string prefix_str = card.substr(0, min(3, size));
    int prefix = (size > 0) ? stoi(prefix_str) : 0;

    // 3. Check if Prefix is Matched (4, 5, 6, or 37)
    bool matched = false;
    if (size >= 1) {
        int first_one = card[0] - '0';
        int first_two = (size >= 2) ? stoi(card.substr(0, 2)) : 0;
        matched = (first_one == 4 || first_one == 5 || first_one == 6 || first_two == 37);
    }

    // 4. Calculate Luhn sums (Double Even Places & Odd Places)
    int sum_even = 0;
    int sum_odd = 0;
    bool is_even_position = false; // Starts at false because rightmost digit is odd position

    // Loop backwards from the last digit to the first
    for (int i = size - 1; i >= 0; i--) {
        int digit = card[i] - '0';

        if (is_even_position) {
            int doubled = digit * 2;
            sum_even += (doubled > 9) ? (doubled - 9) : doubled; // Quick digit sum trick
        } else {
            sum_odd += digit;
        }
        is_even_position = !is_even_position; // Alternate positions
    }

    // 5. Determine absolute validity
    bool valid = (size >= 13 && size <= 16) && matched && ((sum_even + sum_odd) % 10 == 0);

    // Print same required outputs
    cout << "\nPrefix: " << prefix << "\n";
    cout << "Matched: " << matched << "\n";
    cout << "Size: " << size << "\n";
    cout << "Sum of Odd Numbers: " << sum_odd << "\n";
    cout << "Sum of double even numbers: " << sum_even << "\n";
    cout << "Valid: " << valid << "\n";

    return 0;
}