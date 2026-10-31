#include <iostream>

bool isValid(long long number);
int sumOfDoubleEvenPlace(long long number);
int getDigit(int number);
int sumOfOddPlace(long long number);
bool prefixMatched(long long number, int d);
int getSize(long long number);
long long getPrefix(long long number, int k);

int main() {
    long long card_number;
    std::cout << "Enter a credit card number as an integer: ";
    std::cin >> card_number;

    if (isValid(card_number)) {
        std::cout << card_number << " is valid" << std::endl;
    } else {
        std::cout << card_number << " is invalid" << std::endl;
    }
    return 0;
}

bool isValid(long long number) {
    int total_sum = sumOfDoubleEvenPlace(number) + sumOfOddPlace(number);
    int total_size = getSize(number);

    if (total_size >= 13 && total_size <= 16) {
        if (prefixMatched(number, 4) || prefixMatched(number, 5) || 
            prefixMatched(number, 37) || prefixMatched(number, 6)) {
            return (total_sum % 10 == 0);
        }
    }
    return false;
}

int sumOfDoubleEvenPlace(long long number) {
    int sum = 0;
    number /= 10; 
    while (number > 0) {
        int digit = number % 10;
        sum += getDigit(digit * 2);
        number /= 100; 
    }
    return sum;
}

int getDigit(int number) {
    if (number < 10) {
        return number;
    }
    return (number % 10) + (number / 10);
}

int sumOfOddPlace(long long number) {
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 100; 
    }
    return sum;
}

bool prefixMatched(long long number, int d) {
    int d_size = getSize(d);
    return (getPrefix(number, d_size) == d);
}

int getSize(long long number) {
    int count = 0;
    if (number == 0) return 1;
    while (number > 0) {
        count++;
        number /= 10;
    }
    return count;
}

long long getPrefix(long long number, int k) {
    int num_size = getSize(number);
    if (num_size < k) {
        return number;
    }
    int places_to_drop = num_size - k;
    for (int i = 0; i < places_to_drop; ++i) {
        number /= 10;
    }
    return number;
}
