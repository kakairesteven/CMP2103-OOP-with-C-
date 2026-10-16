// (Area and perimeter of a circle) Write a program that displays the area and perimeter of a circle that has a radius of 5.5 using the following formulas:
//      area = radius * radius * pi
//      perimeter = 2 * radius * pi

// Where pi = 3.14.

#include <iostream>
#include <iomanip>
using namespace std; 

int main()
{
    //  Print statement
    std::cout << "Please enter the radius of a circle\n";

    // Initialize radius
    int radius = 0;

    // read radius
    std::cin >> radius;

    // Pi value
    double pi = 3.14;

    // Calculate area
    double area = radius * radius * pi;

    // Calculate perimeter
    double perimeter = 2 * radius * pi;

    // Print
    std::cout << "A circle of radius, " << radius << "has: \n";
    std::cout << "Area, " << area << "\n";
    std::cout << "Perimeter, " << perimeter << "\n";

    return 0;
}

// Try
// Rewrite this program using a close approximation of π and return the value to a precision of 10 decimal places.
