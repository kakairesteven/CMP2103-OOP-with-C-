# Credit Card Validation Program

## Introduction

This is a C++ program that checks whether a credit card number is valid or not. It uses the **Luhn algorithm** to do the validation.

The program asks the user to enter a credit card number. It then checks the number of digits, checks the starting digits of the card, and performs the Luhn calculation.

I divided the program into different functions so that each function handles a specific part of the problem.

## Main Function

The program starts from the `main()` function.

```cpp
int main() {
    long long cardNumber;

    cout << "Enter a credit card number as an integer: ";
    cin >> cardNumber;

    if (isValid(cardNumber))
        cout << cardNumber << " is valid" << endl;
    else
        cout << cardNumber << " is invalid" << endl;

    return 0;
}
```

First, I declared `cardNumber` as a `long long`. I used `long long` because a credit card number can have up to 16 digits, which may be too large for an ordinary `int`.

The user enters the card number using `cin`.

I then pass the number to:

```cpp
isValid(cardNumber)
```

This function returns either `true` or `false`.

If it returns `true`, the program prints that the card is valid. Otherwise, it prints that the card is invalid.

## `isValid()` Function

```cpp
bool isValid(long long number) {
    int size = getSize(number);

    if (size < 13 || size > 16)
        return false;

    if (!prefixMatched(number, 4) && !prefixMatched(number, 5) &&
        !prefixMatched(number, 37) && !prefixMatched(number, 6))
        return false;

    int total = sumOfDoubleEvenPlace(number) + sumOfOddPlace(number);

    return total % 10 == 0;
}
```

This is the main function responsible for deciding whether the card number is valid.

First, I find the number of digits by calling:

```cpp
getSize(number)
```

The program only accepts numbers between 13 and 16 digits. If the number is outside this range, the function immediately returns `false`.

The next part checks the prefix:

```cpp
if (!prefixMatched(number, 4) && !prefixMatched(number, 5) &&
    !prefixMatched(number, 37) && !prefixMatched(number, 6))
```

The `!` means **not**. Therefore, this condition means that if the number does not start with 4, 5, 37, or 6, it is invalid.

If the number passes these two checks, the program performs the Luhn calculation.

```cpp
int total = sumOfDoubleEvenPlace(number) + sumOfOddPlace(number);
```

The two functions calculate the two parts of the sum.

Finally:

```cpp
return total % 10 == 0;
```

checks whether the total is divisible by 10. If the remainder is zero, `isValid()` returns `true`.

## `getSize()` Function

```cpp
int getSize(long long d) {
    int count = 0;

    while (d > 0) {
        d /= 10;
        count++;
    }

    return count;
}
```

I use this function to find how many digits are in the card number.

The `while` loop keeps running while the number is greater than zero.

Every time I do:

```cpp
d /= 10;
```

the last digit is removed.

For example, if the number is:

```text
12345
```

it becomes:

```text
1234
123
12
1
0
```

The loop runs five times, so `count` becomes 5.

## `prefixMatched()` Function

```cpp
bool prefixMatched(long long number, int d) {
    int size = getSize(static_cast<long long>(d));

    return getPrefix(number, size) == d;
}
```

This function checks whether the card number starts with a particular prefix.

The variable `d` represents the prefix I want to check.

For example, if I call:

```cpp
prefixMatched(number, 37)
```

the function first finds that `37` has two digits.

It then calls:

```cpp
getPrefix(number, 2)
```

to get the first two digits of the card number.

The two values are then compared using `==`.

If they are equal, the function returns `true`. Otherwise, it returns `false`.

## `getPrefix()` Function

```cpp
long long getPrefix(long long number, int k) {
    int size = getSize(number);

    if (size <= k)
        return number;

    for (int i = 0; i < size - k; i++)
        number /= 10;

    return number;
}
```

This function is used to get the first few digits of a number.

First, I find the total number of digits using `getSize()`.

If the number of digits is already less than or equal to `k`, the function simply returns the number.

Otherwise, I use a `for` loop to remove the digits at the end.

For example, if:

```text
number = 123456
k = 2
```

I need to remove four digits from the right:

```text
123456 → 12345 → 1234 → 123 → 12
```

The result is `12`, which is the prefix I wanted.

## `sumOfDoubleEvenPlace()` Function

```cpp
int sumOfDoubleEvenPlace(long long number) {
    int sum = 0;

    while (number > 0) {
        number /= 10;
        sum += getDigit(static_cast<int>(number % 10) * 2);
        number /= 10;
    }

    return sum;
}
```

This function handles the digits that need to be doubled according to the Luhn algorithm.

The first:

```cpp
number /= 10;
```

removes the last digit and allows me to move to the next digit.

Then:

```cpp
number % 10
```

gets the digit I want.

I multiply that digit by 2:

```cpp
number % 10 * 2
```

and pass the result to `getDigit()`.

After that, I divide the number by 10 again so that I can move to the next pair of digits.

The process continues until all the required digits have been processed.

## `getDigit()` Function

```cpp
int getDigit(int number) {
    return number / 10 + number % 10;
}
```

This function is used when a doubled digit becomes a two-digit number.

For example, if the digit is 8:

```text
8 × 2 = 16
```

The digits of 16 need to be added:

```text
1 + 6 = 7
```

The function does this using:

```cpp
number / 10
```

to get the first digit, and:

```cpp
number % 10
```

to get the second digit.

So:

```cpp
getDigit(16)
```

gives:

```text
1 + 6 = 7
```

If the number is already a single digit, the division part gives zero, so the original digit is still returned.

## `sumOfOddPlace()` Function

```cpp
int sumOfOddPlace(long long number) {
    int sum = 0;

    while (number > 0) {
        sum += static_cast<int>(number % 10);
        number /= 100;
    }

    return sum;
}
```

This function adds the digits that are not doubled.

First:

```cpp
number % 10
```

gets the last digit of the number and adds it to `sum`.

Then:

```cpp
number /= 100;
```

removes two digits.

This is done so that the function skips the digit that was handled by `sumOfDoubleEvenPlace()` and moves to the next required digit.

The loop continues until there are no more digits left.

## How the Functions Work Together

The functions are connected through `isValid()`.

The program first uses `getSize()` to check the length of the number. It then uses `prefixMatched()` and `getPrefix()` to check the beginning of the number.

After that, `sumOfDoubleEvenPlace()` and `sumOfOddPlace()` calculate the two parts of the Luhn sum. `getDigit()` is used by the first of these functions whenever a doubled digit produces a two-digit number.

The final total is then checked using:

```cpp
total % 10 == 0
```

This gives the final `true` or `false` result.
