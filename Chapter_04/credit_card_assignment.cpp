#include <iostream>
#include <cmath>
using namespace std;

int getSize(long long d)
{
  int count = 0;
  while(d != 0){
    d /= 10;
    count++;
  }
  return count;
}
long long getPrefix(long long number, int k)
{
    int numDigits = getSize(number);

    if (numDigits < k){
      return number;
    }

    int digitstodrop = numDigits - k;
    long long divisor = pow(10, digitstodrop);
    
    return number / divisor;
}
bool prefixMatched(long long number, int d)
{
    if( d == 4 || d == 5 || d == 6){
       return getPrefix(number, 1) == d;
    }
    if(d == 37){
        return getPrefix(number, 2) == 37;
    }
    
    return false;
}
int getDigit(int number){
    if(number < 10)
        return number;
    
    return number / 10 + number % 10;
}
int sumOfDoubleEvenPlace(long long number){
    int sum = 0;
    int position = 0;

    while(number > 0) {
        int digit = number % 10;
        if(position % 2 == 1){
            sum += getDigit(digit * 2);
        }
        number /= 10;
        position++;
    }
    return sum;
}
int sumOfOddPlace(long long number){
    int sum = 0;
    int position = 0;

    while(number > 0){
        int digit = number % 10;
        if(position % 2 == 0){
            sum += digit;
        }
        number /= 10;
        position++;
    }
    return sum;
}
bool isValid(long long number) {
    if(getSize(number) < 13 ||getSize(number) > 16)
       return false;    
    if(!prefixMatched(number, 4) && !prefixMatched(number, 5) && !prefixMatched(number, 6) && !prefixMatched(number, 37))
       return false;
    int total = sumOfDoubleEvenPlace(number) + sumOfOddPlace(number);
    
   return total % 10 == 0;
}


int main(){
    long long number;

    cout << "Enter your Credit Card Number: ";
    cin >> number;
    if(isValid(number))
       cout << number << " is Valid\n";
    else
      cout << number << " is not Valid. Please enter a valid number!\n";
    return 0;
}