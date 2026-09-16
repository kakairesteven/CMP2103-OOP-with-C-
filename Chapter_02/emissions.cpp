// Given a dataset of emission released in Kampala City;
// Date     Month       Year Quanity
// 08 8.0   '2026'      40
// 10 8.0   '2026'      60
// 12 8.0   '2027'      90

// Write a program that display date as dd/mm/yyy and Quantity in a tabular form. As usual, the program should prompt the user to enter values.

// Output example.

// Date           Year Quanity
// 08/8/2026      40
// 10/8/2026      60
// 12/8/2027      90

#include <iomanip>
#include <iostream>
using namespace std;

struct Emission {
	int day;
	int month;
	int year;
	int quantity;
};

int main() {
	Emission emissions[3];

	for (int index = 0; index < 3; ++index) {
		cout << "Enter day, month, year, and quantity for record "
				  << index + 1 << ": ";
		cin >> emissions[index].day >> emissions[index].month
				 >> emissions[index].year >> emissions[index].quantity;
	}

	cout << "\nDate\t\tYear\tQuantity\n";
	for (const Emission& emission : emissions) {
		cout << setfill('0') << setw(2) << emission.day << '/'
				  << setw(1) << emission.month << '/' << setfill(' ')
				  << emission.year << "\t" << emission.quantity << '\n';
	}

	return 0;
}
