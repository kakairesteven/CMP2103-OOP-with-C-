// Write a program to test an integer value to determine if it is odd or even.
// As always, make sure your output is clear and complete. In other words, don’t just output yes or no.
// Your output should stand alone, like The value 4 is an even number.

#include <iostream>
using namespace std;

int main()
{
	int value;
	cout << "Enter an integer: ";
	cin >> value;

	if (value % 2 == 0)
		cout << "The value " << value << " is an even number.\n";
	else
		cout << "The value " << value << " is an odd number.\n";

	return 0;
}

