#include <iostream>

int main()
{
	double miles;

	std::cout << "Enter the number of miles: ";
	std::cin >> miles;

	std::cout << miles << " miles is " << miles * 1.609
			  << " kilometers.\n";

	return 0;
}