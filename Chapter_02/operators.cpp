// Write a program that takes an operation followed by two operands and outputs the result. For example:
// + 100 3.14
// ∗ 4 5

// Read the operation into a string called operation and use an if-statement to figure out which
// operation the user wants, for example, if (operation=="+"). Read the operands into variables
// of type double. Implement this for operations called +, −, ∗, /, plus, minus, mul, and div with
// their obvious meanings.

#include <iostream>
#include <string>
using namespace std;

int main() {
	std::string operation;
	double first_operand;
	double second_operand;

	std::cin >> operation >> first_operand >> second_operand;

	if (operation == "+" || operation == "plus") {
		std::cout << first_operand + second_operand << '\n';
	} else if (operation == "-" || operation == "minus") {
		std::cout << first_operand - second_operand << '\n';
	} else if (operation == "*" || operation == "mul") {
		std::cout << first_operand * second_operand << '\n';
	} else if (operation == "/" || operation == "div") {
		std::cout << first_operand / second_operand << '\n';
	} else {
		std::cerr << "Unknown operation: " << operation << '\n';
		return 1;
	}

	return 0;
}

