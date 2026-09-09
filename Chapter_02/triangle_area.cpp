// Geometry: area of a triangle) Write a program that prompts the user to enter the
// three points (x1, y1), (x2, y2), and (x3, y3) of a triangle and displays its area.
// The formula for computing the area of a triangle is s = (side1 + side2 + side3) / 2
// Area = sqrt(s(s-side1)(s-side2)(s-side3))
// Example: Enter three points for a triangle: 1.5, -3.4, 4.6, 5, 9.5, -3.4 
// The area of the triangle is 33.6

#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
	double x1;
	double y1;
	double x2;
	double y2;
	double x3;
	double y3;

	std::cout << "Enter three points for a triangle: ";
	if (!(std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)) {
		return 1;
	}

	const double side1 = std::hypot(x2 - x1, y2 - y1);
	const double side2 = std::hypot(x3 - x2, y3 - y2);
	const double side3 = std::hypot(x1 - x3, y1 - y3);
	const double semiperimeter = (side1 + side2 + side3) / 2.0;
	const double area = std::sqrt(
		semiperimeter * (semiperimeter - side1) *
		(semiperimeter - side2) * (semiperimeter - side3));

	std::cout << std::fixed << std::setprecision(1)
			  << "The area of the triangle is " << area << '\n';

	return 0;
}
