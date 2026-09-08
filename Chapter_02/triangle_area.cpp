// Geometry: area of a triangle) Write a program that prompts the user to enter the
// three points (x1, y1), (x2, y2), and (x3, y3) of a triangle and displays its area.
// The formula for computing the area of a triangle is s = (side1 + side2 + side3) / 2
// Area = sqrt(s(s-side1)(s-side2)(s-side3))
// Example: Enter three points for a triangle: 1.5, -3.4, 4.6, 5, 9.5, -3.4 
// The area of the triangle is 33.6

#include <iostream>
#include <cmath>

int main() {
    double x1, y1, x2, y2, x3, y3;

    std::cout << "Enter three points for a triangle: ";
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    // Compute the three side lengths using the distance formula
    double side1 = std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
    double side2 = std::sqrt(std::pow(x3 - x2, 2) + std::pow(y3 - y2, 2));
    double side3 = std::sqrt(std::pow(x1 - x3, 2) + std::pow(y1 - y3, 2));

    // Compute the semi-perimeter
    double s = (side1 + side2 + side3) / 2;

    // Compute the area using Heron's formula
    double area = std::sqrt(s * (s - side1) * (s - side2) * (s - side3));

    std::cout << "The area of the triangle is " << area << std::endl;

    return 0;
}