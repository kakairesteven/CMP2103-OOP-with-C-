#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double x1, y1, x2, y2, x3, y3;

    // Prompt user for input
    cout << "Enter three points for a triangle: ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    // Calculate side lengths using the distance formula
    double side1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    double side2 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    double side3 = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));

    // Calculate semi-perimeter s
    double s = (side1 + side2 + side3) / 2.0;

    // Calculate area using Heron's formula
    double area = sqrt(s * (s - side1) * (s - side2) * (s - side3));

    // Display result rounded to one decimal place
    cout << "The area of the triangle is " << area << endl;

    return 0;
}
