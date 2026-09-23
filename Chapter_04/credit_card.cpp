import std;
using namespace std;

import validate_credit_card;


int main()
{
    vector<int> number = readCardNumber();
    cout << "Prefix: " << getPrefix(number, 3) << "\n";
    cout << "Matched: " << prefixMatched(number) << "\n";
    cout << "Size: " << getSize(number) << "\n";
    cout << "Sum of Odd Numbers " << sumOfOddPlace(number) << "\n";
    cout << "Sum of double even numbers: " << sumOfDoubleEvenPlace(number) << "\n";
    cout << "Valid: " << isValid(number) << "\n";
    return 0;
}

// Valid examples
// 4242424242424242
