// Geometry: area of a triangle) Write a program that prompts the user to enter the
// three points (x1, y1), (x2, y2), and (x3, y3) of a triangle and displays its area.
// The formula for computing the area of a triangle is s = (side1 + side2 + side3) / 2
// Area = sqrt(s(s-side1)(s-side2)(s-side3))
// Example: Enter three points for a triangle: 1.5, -3.4, 4.6, 5, 9.5, -3.4 
// The area of the triangle is 33.6
//Solution

#include <iostream> //Standard Library Header
#include <math.h>   //Provide access to math functions

using namespace std; //Prevents repetition of std::

int main() {
    //User enters three co-ordinates
    double x1, y1, x2, y2, x3, y3;
    cout << "Enter three co-ordinates for a triangle.\n";
    cout << "Point A(x1, y1): ";
    cin >> x1 >> y1;
    cout << "Point B(x2, y2): ";
    cin >> x2 >> y2;
    cout << "Point C(x3, y3): ";
    cin >> x3 >> y3;

    //Calculate the length of each side
    double AB = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    double AC = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
    double BC = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    
    //Calculate area
    double s = (AB + AC + BC) / 2;
    double area = sqrt(s * (s - AB) * (s - AC) * (s - BC));
    
    //Print out area
    cout << "The area is " << area << ".\n";
    
    return 0;
}