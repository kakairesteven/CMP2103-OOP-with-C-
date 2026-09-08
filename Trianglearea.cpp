#include <iostream>
#include <cmath>

int main() {
    double x1, y1, x2, y2, x3, y3;

    // Prompt the user for input
    std::cout << "Enter three points for a triangle: ";
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    // Calculate the length of each side using the distance formula
    double side1 = std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
    double side2 = std::sqrt(std::pow(x3 - x2, 2) + std::pow(y3 - y2, 2));
    double side3 = std::sqrt(std::pow(x1 - x3, 2) + std::pow(y1 - y3, 2));

    // Compute the semi-perimeter (s)
    double s = (side1 + side2 + side3) / 2.0;

    // Compute the area using Heron's formula
    double area = std::sqrt(s * (s - side1) * (s - side2) * (s - side3));

    // Display the result
    std::cout << "The area of the triangle is " << area << std::endl;

    return 0;
}