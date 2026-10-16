#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    // Allow user to enter 3 points.
    cout << "Enter 3 points for a triangle: " << endl;
    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    // Obtaining the lengths of the 3 sides of the triangle.
    double side1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    double side2 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    double side3 = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
    
    // Calculating for the perimeter length (p).
    double p = (side1 + side2 + side3) / 2;
    
    // Calculating the area of the triangle.
    double area = sqrt(p * (p - side1) * (p - side2) * (p - side3));
    
    // Final result display.
    cout << fixed << setprecision(1);
    cout << "The area of the triangle is " << area << " square units." << endl;

    return 0;
}