
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double x1, y1, x2, y2, x3, y3;

    cout << "Enter the three points for a triangle (x1 y1 x2 y2 x3 y3): ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    double side1 = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    double side2 = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    double side3 = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));

    double s = (side1 + side2 + side3) / 2.0;
    double area = sqrt(s * (s - side1) * (s - side2) * (s - side3));

    cout << fixed << setprecision(1);
    cout << "The area of the triangle is " << area << endl;

    return 0;
}
