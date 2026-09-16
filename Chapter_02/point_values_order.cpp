// Modify the program above to ask the user to enter floating-point values and store them in double  variables.
// Compare the outputs of the two programs for some inputs of your choice.
// Are the results the same? Should they be? What’s the difference?

#include <iostream>
using namespace std;

int main() {
	double first, second, third;

	cout << "Enter three floating-point values: ";
	cin >> first >> second >> third;

	if (first > second) {
		swap(first, second);
	}
	if (second > third) {
		swap(second, third);
	}
	if (first > second) {
		swap(first, second);
	}

	cout << "In ascending order: " << first << ", " << second << ", " << third << endl;
	return 0;
}


