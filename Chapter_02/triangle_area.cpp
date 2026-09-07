// Geometry: area of a triangle) Write a program that prompts the user to enter the
// three points (x1, y1), (x2, y2), and (x3, y3) of a triangle and displays its area.
// The formula for computing the area of a triangle is s = (side1 + side2 + side3) / 2
// Area = sqrt(s(s-side1)(s-side2)(s-side3))
// Example: Enter three points for a triangle: 1.5, -3.4, 4.6, 5, 9.5, -3.4 
// The area of the triangle is 33.6
#include <iostream>
#include <cmath>    // Required for sqrt() and abs()
#include <iomanip>  // Required for formatting the decimal output

int main() {
    double x1, y1, x2, y2, x3, y3;

    // Step 1: Get the three points from the user
    std::cout << "Enter the coordinates for Point 1:\n";
    std::cout << "x1: ";
    std::cin >> x1;
    std::cout << "y1: ";
    std::cin >> y1;

    std::cout << "\nEnter the coordinates for Point 2:\n";
    std::cout << "x2: ";
    std::cin >> x2;
    std::cout << "y2: ";
    std::cin >> y2;

    std::cout << "\nEnter the coordinates for Point 3:\n";
    std::cout << "x3: ";
    std::cin >> x3;
    std::cout << "y3: ";
    std::cin >> y3;

    // Step 2: Calculate the length of each side using the distance formula
    double side1 = std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
    double side2 = std::sqrt(std::pow(x3 - x2, 2) + std::pow(y3 - y2, 2));
    double side3 = std::sqrt(std::pow(x1 - x3, 2) + std::pow(y1 - y3, 2));

    // Step 3: Calculate the semi-perimeter (s)
    double s = (side1 + side2 + side3) / 2.0;

    // Step 4: Calculate the area using Heron's Formula
    // std::abs() prevents tiny negative numbers caused by computer rounding errors
    double inside_sqrt = s * (s - side1) * (s - side2) * (s - side3);
    double area = std::sqrt(std::abs(inside_sqrt));

    // Step 5: Display the result formatted to 2 decimal places
    std::cout << "\nThe area of the triangle is: " 
              << std::fixed << std::setprecision(2) << area << "\n";

    return 0;
}

